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

int m, n;
int g[110][110];
int f[51][110][110];
string hop;
string line;

inline void work() {
    cin >> n >> m >> hop;

    for (int i = m; i >= 1; --i) {
        cin >> line;
        for (int j = 1; j <= n; ++j) {
            g[i][j] = line[j - 1] - '0';
            // printf("g[%d][%d] = %d\n", i, j, g[i][j]);
        }
    }

    for (int k = 0; k <= hop.size(); ++k) {
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i == 1 && j == 1) {
                    f[k][i][j] = (k == 0 ? g[i][j] : INT_MAX / 2);
                    continue;
                }
                f[k][i][j] = INT_MAX / 2;
                if (i > 1) {
                    f[k][i][j] = min(f[k][i][j], f[k][i - 1][j]);
                }
                if (j > 1) {
                    f[k][i][j] = min(f[k][i][j], f[k][i][j - 1]);
                }
                if (k > 0) {
                    int step = hop[k - 1] - '0';
                    if (i > step + 1) {
                        f[k][i][j] = min(f[k][i][j], f[k - 1][i - step - 1][j]);
                    }
                    if (j > step + 1) {
                        f[k][i][j] = min(f[k][i][j], f[k - 1][i][j - step - 1]);
                    }
                }
                f[k][i][j] += g[i][j];
                // printf("f[%d][%d][%d] = %d\n", k, i, j, f[k][i][j]);
            }
        }
    }

    int ans = INT_MAX / 2;
    for (int k = 0; k <= hop.size(); ++k) {
        ans = min(ans, f[k][m][n]);
    }
    cout << ans << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}