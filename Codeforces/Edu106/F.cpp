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
const int mod = 998244353;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int n, k, x, y;
vector<vector<int>> edges;
// f[u][j] = number of ways to cut the subtree rooted at u
// where the all the paths inside are <= k and the longest path to the root is j
vector<vector<int>> f;

vector<int> combine(const vector<int>& v0, const vector<int>& v1) {
    // v0 has attached to the root, but v1 has not
    vector<int> v(max((int)v0.size(), min((int)v1.size() + 1, k + 1)));
    
    // keep the v1 edge
    for (int i = 0; i < v0.size(); ++i) {
        for (int j = 0; j < v1.size() && i + j + 1 <= k; ++j) {
            int idx = max(i, j + 1);
            v[idx] += (LL)v0[i] * v1[j] % mod;
            if (v[idx] >= mod) {
                v[idx] -= mod;
            }
        }
    }

    // cut the v1 edge
    int total = 0;
    for (int o: v1) {
        total += o;
        if (total >= mod) {
            total -= mod;
        }
    }
    for (int j = 0; j < v0.size(); ++j) {
        v[j] += (LL)v0[j] * total % mod;
        if (v[j] >= mod){
            v[j] -= mod;
        }
    }

    return v;
}

void dfs(int u, int fa) {
    bool found = false;
    for (int v: edges[u]) {
        if (v == fa) {
            continue;
        }
        dfs(v, u);
        if (!found) {
            found = true;
            vector<int> dum(min((int)f[v].size() + 1, k + 1));
            // keep the edge
            for (int j = 1; j < dum.size(); ++j) {
                dum[j] = f[v][j - 1];
            }
            // cut the edge
            for (int o: f[v]) {
                dum[0] += o;
                if (dum[0] >= mod) {
                    dum[0] -= mod;
                }
            }
            f[u] = move(dum);
        }
        else {
            f[u] = combine(f[u], f[v]);
        }
    }
    if (!found) {
        f[u] = {1};
    }
}

inline void work() {
    cin >> n >> k;
    edges.resize(n + 1);
    for (int i = 1; i < n; ++i) {
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    f.resize(n + 1);
    dfs(1, 0);

    int ans = 0;
    for (int o: f[1]) {
        ans += o;
        if (ans >= mod) {
            ans -= mod;
        }
    }
    cout << ans << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}