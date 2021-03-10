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
 
int n, m, x, y;
int g[410][410], ans[410][410];
int tag[410];
vector<vector<int>> edges;
 
inline void work() {
    memset(g, 0x3f, sizeof(g));
    cin >> n >> m;
    edges.resize(n + 1);
    for (int i = 1; i <= m; ++i) {
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
        g[x][y] = g[y][x] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        g[i][i] = 0;
    }
 
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
 
    for (int u = 1; u <= n; ++u) {
        ans[u][u] = 1;
        for (int i = 1; i <= n; ++i) {
            if (i == u) {
                continue;
            }
            int cnt = 0;
            for (int j: edges[i]) {
                if (g[u][j] + 1 == g[u][i]) {
                    ++cnt;
                }
            }
            ans[u][u] = (LL)ans[u][u] * cnt % mod;
        }
    }
 
    int tg = 0;
    for (int u = 1; u <= n; ++u) {
        for (int v = 1; v <= n; ++v) {
            if (u == v) {
                continue;
            }
            ++tg;
            bool check = true;
            for (int i = 1; i <= n; ++i) {
                if (g[u][v] == g[u][i] + g[i][v]) {
                    if (tag[g[u][i]] == tg) {
                        check = false;
                        break;
                    }
                    tag[g[u][i]] = tg;
                }
            }
            if (!check) {
                continue;
            }
 
            ans[u][v] = 1;
            for (int i = 1; i <= n; ++i) {
                if (g[u][v] == g[u][i] + g[i][v]) {
                    continue;
                }
                int cnt = 0;
                for (int j: edges[i]) {
                    if (g[u][j] + 1 == g[u][i] && g[v][j] + 1 == g[v][i]) {
                        ++cnt;
                    }
                }
                ans[u][v] = (LL)ans[u][v] * cnt % mod;
            }
            ans[v][u] = ans[u][v];
        }
    }
 
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}
 
int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}