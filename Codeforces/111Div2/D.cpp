#include <iostream>
#include <iomanip>
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

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

class UF {
public:
    vector<int> fa;
    vector<int> sz;
    int n;
    int comp_cnt;
    
public:
    UF(int _n): n(_n), comp_cnt(_n), fa(_n), sz(_n, 1) {
        iota(fa.begin(), fa.end(), 0);
    }
    
    int findset(int x) {
        return fa[x] == x ? x : fa[x] = findset(fa[x]);
    }
    
    void unite(int x, int y) {
        if (sz[x] < sz[y]) {
            swap(x, y);
        }
        fa[y] = x;
        sz[x] += sz[y];
        --comp_cnt;
    }

    bool findAndUnite(int x, int y) {
        int x0 = findset(x);
        int y0 = findset(y);
        if (x0 != y0) {
            unite(x0, y0);
            return true;
        }
        return false;
    }
};

class TarjanSCC {
private:
    static vector<int> low, dfn, group;
    static int ts;

private:
    static void getCuttingEdge_(const vector<vector<int>>& edges, const vector<vector<int>>& edges_id, int u, int last, vector<int>& ans) {
        low[u] = dfn[u] = ++ts;
        for (int i = 0; i < edges[u].size(); ++i) {
            int v = edges[u][i];
            int id = edges_id[u][i];
            if (dfn[v] == -1) {
                getCuttingEdge_(edges, edges_id, v, id, ans);
                low[u] = min(low[u], low[v]);
                if (low[v] > dfn[u]) {
                    ans.push_back(id);
                }
            }
            else if (id != last) {
                low[u] = min(low[u], dfn[v]);
            }
        }
    }

public:
    static vector<int> getCuttingEdge(int n, const vector<vector<int>>& edges, const vector<vector<int>>& edges_id) {
        low.assign(n, -1);
        dfn.assign(n, -1);
        ts = -1;
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (dfn[i] == -1) {
                getCuttingEdge_(edges, edges_id, i, -1, ans);
            }
        }
        return ans;
    }
};

vector<int> TarjanSCC::low, TarjanSCC::dfn, TarjanSCC::group;
int TarjanSCC::ts;

struct Edge {
    int x, y, v, id;
    Edge(int _x, int _y, int _v, int _id): x(_x), y(_y), v(_v), id(_id) {}
    bool operator< (const Edge& that) const {
        return v < that.v;
    }
};

int n, m;
int x, y, v;

inline void work() {
    cin >> n >> m;
    vector<Edge> edges;
    for (int i = 0; i < m; ++i) {
        cin >> x >> y >> v;
        edges.emplace_back(x - 1, y - 1, v, i);
    }
    sort(edges.begin(), edges.end());

    UF uf(n);
    vector<int> ans(m, 1);
    for (int i = 0; i < m;) {
        int j = i;
        while (j < m && edges[j].v == edges[i].v) {
            ++j;
        }
        unordered_map<int, int> s;
        int subg_n = 0;
        for (int k = i; k < j; ++k) {
            Edge& edge = edges[k];
            int fax = uf.findset(edge.x);
            int fay = uf.findset(edge.y);
            if (fax != fay) {
                if (!s.count(fax)) {
                    s[fax] = subg_n++;
                }
                if (!s.count(fay)) {
                    s[fay] = subg_n++;
                }
            }
        }
        vector<vector<int>> subg_edges(subg_n), subg_id(subg_n);
        for (int k = i; k < j; ++k) {
            Edge& edge = edges[k];
            int fax = uf.findset(edge.x);
            int fay = uf.findset(edge.y);
            if (fax != fay) {
                int sx = s[fax], sy = s[fay];
                subg_edges[sx].push_back(sy);
                subg_id[sx].push_back(edge.id);
                subg_edges[sy].push_back(sx);
                subg_id[sy].push_back(edge.id);
            }
            else {
                ans[edge.id] = 2;
            }
        }
        vector<int> result = TarjanSCC::getCuttingEdge(subg_n, subg_edges, subg_id);
        for (int edge_id: result) {
            ans[edge_id] = 0;
        }
        for (int k = i; k < j; ++k) {
            Edge& edge = edges[k];
            uf.findAndUnite(edge.x, edge.y);
        }
        i = j;
    }
    
    for (int i = 0; i < m; ++i) {
        if (ans[i] == 0) {
            cout << "any\n";
        }
        else if (ans[i] == 1) {
            cout << "at least one\n";
        }
        else {
            cout << "none\n";
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}