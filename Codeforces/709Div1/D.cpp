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

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int n, m;
LL g[610][610], best[610][610];
int x, y, q;
LL z;

inline void work() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            g[i][j] = (i == j ? 0 : LLONG_MAX / 10);
        }
    }
    vector<tuple<int, int, LL>> edges;
    for (int i = 1; i <= m; ++i) {
        cin >> x >> y >> z;
        g[x][y] = g[y][x] = z;
        edges.emplace_back(x, y, z);
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }

    vector<vector<pair<int, LL>>> extra(n + 1);
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        cin >> x >> y >> z;
        extra[x].emplace_back(y, z);
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            best[i][j] = LLONG_MIN / 10;
            if (i != j) {
                for (const auto& [k, w]: extra[i]) {
                    best[i][j] = max(best[i][j], w - g[j][k]);
                }
            }
        }
    }

    int ans = 0;
    for (const auto& [e1, e2, w]: edges) {
        for (int u = 1; u <= n; ++u) {
            if (g[u][e1] + w <= best[u][e2] || g[u][e2] + w <= best[u][e1]) {
                ++ans;
                break;
            }
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