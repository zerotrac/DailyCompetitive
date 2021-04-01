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

int f[1010][1010][2];
string s, t;

inline void work() {
    cin >> s >> t;
    int m = s.size(), n = t.size();
    int ans = 0;
    auto ua = [](int& x, int y) {
        x += y;
        if (x >= mod) {
            x -= mod;
        }
    };
    auto um = [](int& x, int y) {
        x -= y;
        if (x < 0) {
            x += mod;
        }
    };
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i > 0) {
                if (i > 1 && s[i - 2] != s[i - 1]) {
                    ua(f[i][j][0], f[i - 1][j][0]);
                }
                if (j > 0 && t[j - 1] != s[i - 1]) {
                    ua(f[i][j][0], f[i - 1][j][1]);
                }
            }
            if (j > 0) {
                if (i > 0 && s[i - 1] != t[j - 1]) {
                    ua(f[i][j][1], f[i][j - 1][0]);
                }
                if (j > 1 && t[j - 2] != t[j - 1]) {
                    ua(f[i][j][1], f[i][j - 1][1]);
                }
            }
            if (i > 0) {
                ua(f[i][j][0], 1);
            }
            if (j > 0) {
                ua(f[i][j][1], 1);
            }
            if (i > 0 && j > 0) {
                ua(ans, f[i][j][0]);
                ua(ans, f[i][j][1]);
            }
        }
    }
    for (int i = 1; i <= m; ++i) {
        um(ans, (LL)f[i][0][0] * n % mod);
    }
    for (int j = 1; j <= n; ++j) {
        um(ans, (LL)f[0][j][1] * m % mod);
    }
    cout << ans << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}