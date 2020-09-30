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

const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int a[110][110];
int m, n;

inline void work() {
    cin >> m >> n;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    LL ans = 0;
    while (true) {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans += a[i][j];
            }
        }
        bool flag = false;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!a[i][j]) {
                    continue;
                }
                int p = 0, q = 0;
                for (int d = 0; d < 4; ++d) {
                    int x = i + dirs[d][0];
                    int y = j + dirs[d][1];
                    while (x >= 0 && x < m && y >= 0 && y < n) {
                        if (a[x][y] != 0) {
                            p += abs(a[x][y]);
                            ++q;
                            break;
                        }
                        x += dirs[d][0];
                        y += dirs[d][1];
                    }
                }
                if (q * a[i][j] < p) {
                    a[i][j] = -a[i][j];
                    flag = true;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                a[i][j] = max(a[i][j], 0);
            }
        }
        if (!flag) {
            break;
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