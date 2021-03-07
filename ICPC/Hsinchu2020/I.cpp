#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <random>
#include <chrono>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;
using PIL = pair<int, LL>;
using PLL = pair<LL, LL>;
// const int mod = 1e9 + 7;
// const int mod = 998244353;

class TarjanSCC {
private:
    // low, dfn, group are basic concepts of SCC/BCC
    static vector<int> low, dfn, group;
    // stack, if-in-stack are concepts of SCC
    static vector<int> stk, instk;
    // BCC component
    static vector<pair<int, int>> comp;
    // timestamp
    static int ts;
    // SCC count
    static int scnt;

private:
    static void getCuttingVertex_(const vector<vector<int>>& edges, int u, int parent, vector<int>& ans, vector<vector<pair<int, int>>>& comps) {
        low[u] = dfn[u] = ++ts;
        int child = 0;
        bool isCV = false;
        for (int v: edges[u]) {
            if (dfn[v] == -1) {
                comp.emplace_back(u, v);
                ++child;
                getCuttingVertex_(edges, v, u, ans, comps);
                low[u] = min(low[u], low[v]);
                if (parent == -1 || low[v] >= dfn[u]) {
                    vector<pair<int, int>> newcomp;
                    while (comp.back() != pair{u, v}) {
                        newcomp.push_back(comp.back());
                        comp.pop_back();
                    }
                    newcomp.emplace_back(u, v);
                    comp.pop_back();
                    comps.push_back(move(newcomp));
                }
                if (!isCV && parent != -1 && low[v] >= dfn[u]) {
                    ans.push_back(u);
                    isCV = true;
                }
            }
            else if (v != parent) {
                // back-edge
                if (dfn[u] > dfn[v]) {
                    comp.emplace_back(u, v);
                }
                low[u] = min(low[u], dfn[v]);
            }
        }
        if (!isCV && parent == -1 && child >= 2) {
            ans.push_back(u);
        }
    }

    static void getCuttingEdge_(const vector<vector<int>>& edges, int u, int parent, vector<PII>& ans) {
        low[u] = dfn[u] = ++ts;
        for (int v: edges[u]) {
            if (dfn[v] == -1) {
                getCuttingEdge_(edges, v, u, ans);
                low[u] = min(low[u], low[v]);
                if (low[v] > dfn[u]) {
                    ans.emplace_back(u, v);
                }
            }
            else if (v != parent) {
                low[u] = min(low[u], dfn[v]);
            }
        }
    }

public:
    // input: node count, graph
    // output: cutting vertices, BCC components
    static pair<vector<int>, vector<vector<pair<int, int>>>> getCuttingVertex(int n, const vector<vector<int>>& edges) {
        low.assign(n, -1);
        dfn.assign(n, -1);
        comp.clear();
        ts = -1;
        vector<int> ans;
        vector<vector<pair<int, int>>> comps;
        for (int i = 0; i < n; ++i) {
            if (dfn[i] == -1) {
                getCuttingVertex_(edges, i, -1, ans, comps);
            }
        }
        return {ans, comps};
    }

    // input: node count, graph
    // output: cutting edges
    static vector<PII> getCuttingEdge(int n, const vector<vector<int>>& edges) {
        low.assign(n, -1);
        dfn.assign(n, -1);
        ts = -1;
        vector<pair<int, int>> ans;
        for (int i = 0; i < n; ++i) {
            if (dfn[i] == -1) {
                getCuttingEdge_(edges, i, -1, ans);
            }
        }
        return ans;
    }
};

vector<int> TarjanSCC::low, TarjanSCC::dfn, TarjanSCC::group;
vector<int> TarjanSCC::stk, TarjanSCC::instk;
vector<pair<int, int>> TarjanSCC::comp;
int TarjanSCC::ts;
int TarjanSCC::scnt;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int n, m, x, y;

inline void work() {
    cin >> n >> m;
    vector<vector<int>> edges(n);
    for (int i = 1; i <= m; ++i) {
        cin >> x >> y;
        --x;
        --y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    auto [cutting_vertexes, bcc_components] = TarjanSCC::getCuttingVertex(n, edges);
    auto cutting_edges = TarjanSCC::getCuttingEdge(n, edges);

    cout << cutting_vertexes.size() << " " << cutting_edges.size() << " ";

    int l = bcc_components.size();
    int r = 0;
    for (const auto& comp: bcc_components) {
        r = max(r, (int)comp.size());
    }
    
    int g = gcd(l, r);
    l /= g;
    r /= g;

    cout << l << " " << r << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    int T;
    cin >> T;
    while (T--) {
        work();
    }
    return 0;
}