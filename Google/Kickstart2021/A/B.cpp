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
// 0=left 1=up 2=right 3=down
int g[1010][1010], sum[1010][1010][4];

inline void work() {
    cin >> m >> n;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> g[i][j];
            
        }
    }
    for (int i = 0; i <= m + 1; ++i) {
        for (int j = 0; j <= n + 1; ++j) {
            sum[i][j][0] = sum[i][j][1] = sum[i][j][2] = sum[i][j][3] = 0;
        }
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (g[i][j] == 1) {
                sum[i][j][0] = sum[i][j - 1][0] + 1;
                sum[i][j][1] = sum[i - 1][j][1] + 1;
            }
        }
    }

    for (int i = m; i >= 1; --i) {
        for (int j = n; j >= 1; --j) {
            if (g[i][j] == 1) {
                sum[i][j][2] = sum[i][j + 1][2] + 1;
                sum[i][j][3] = sum[i + 1][j][3] + 1;
            }
        }
    }

    // cout << sum[4][1][0] << " " << sum[4][1][1] << " " << sum[4][1][2] << " " << sum[4][1][3] << endl;

    auto get = [](int x, int y) {
        // x>=4 = long, y>=2 = short
        int x_count = x / 2 - 1;
        int y_count = y - 1;
        return max(min(x_count, y_count), 0);
    };

    LL ans = 0;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            ans += get(sum[i][j][0], sum[i][j][1]);
            ans += get(sum[i][j][1], sum[i][j][0]);

            ans += get(sum[i][j][1], sum[i][j][2]);
            ans += get(sum[i][j][2], sum[i][j][1]);

            ans += get(sum[i][j][2], sum[i][j][3]);
            ans += get(sum[i][j][3], sum[i][j][2]);

            ans += get(sum[i][j][3], sum[i][j][0]);
            ans += get(sum[i][j][0], sum[i][j][3]);
        }
    }

    cout << ans << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; ++_) {
        cout << "Case #" << _ << ": ";
        work();
    }
    return 0;
}