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
const int mod = 1e9 + 7;
// const int mod = 998244353;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int fac[200010], facinv[200010];
PII a[3010];
int f[3010][2];
int h, w, n;

inline int quickmul(int x, int y) {
    int ret = 1, mul = x;
    while (y) {
        if (y & 1) {
            ret = (LL)ret * mul % mod;
        }
        mul = (LL)mul * mul % mod;
        y >>= 1;
    }
    return ret;
}

inline int C(int x, int y) {
    return (LL)fac[x] * facinv[y] % mod * facinv[x - y] % mod;
}

inline void work() {
    cin >> h >> w >> n;
    fac[0] = facinv[0] = 1;
    for (int i = 1; i <= h + w; ++i) {
        fac[i] = (LL)fac[i - 1] * i % mod;
        facinv[i] = quickmul(fac[i], mod - 2);
    }
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a + 1, a + n + 1);
    int ans = C(h + w - 2, h - 1);
    for (int i = 1; i <= n; ++i) {
        int x = a[i].first;
        int y = a[i].second;
        f[i][0] = (LL)C(x - 1 + y - 1, x - 1) % mod;
        for (int j = 1; j < i; ++j) {
            if (x >= a[j].first && y >= a[j].second) {
                int coef = C(x - a[j].first + y - a[j].second, x - a[j].first);
                f[i][0] = (f[i][0] + (LL)f[j][1] * coef % mod) % mod;
                f[i][1] = (f[i][1] + (LL)f[j][0] * coef % mod) % mod;
            }
        }
        int tail = C(h - x + w - y, h - x);
        ans = (ans - (LL)f[i][0] * tail % mod + mod) % mod;
        ans = (ans + (LL)f[i][1] * tail % mod) % mod;
    }
    cout << ans << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}