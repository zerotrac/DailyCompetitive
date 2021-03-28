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

int n, m;
static constexpr int MAXA = 11;
int f[5010], g[5010];
int fac[5010], facinv[5010];

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

inline void init() {
    fac[0] = facinv[0] = 1;
    for (int i = 1; i <= 5000; ++i) {
        fac[i] = (LL)fac[i - 1] * i % mod;
        facinv[i] = quickmul(fac[i], mod - 2);
    }
}

inline int C(int n, int k) {
    return (LL)fac[n] * facinv[k] % mod * facinv[n - k] % mod;
}

inline void work() {
    cin >> n >> m;
    f[0] = 1;
    for (int i = MAXA; i >= 0; --i) {
        int value = 1 << i;
        memset(g, 0, sizeof(g));
        for (int use = 0; value * use <= m && use <= n; use += 2) {
            // C(n, use)
            int para = C(n, use);
            int total = value * use;
            for (int j = m; j >= total; --j) {
                g[j] = (g[j] + (LL)para * f[j - total] % mod) % mod;
            }
        }
        for (int j = 0; j <= m; ++j) {
            f[j] = g[j];
        }
    }
    cout << f[m] << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    init();
    quickread();
    work();
    return 0;
}