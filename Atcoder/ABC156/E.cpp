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

int fac[400010], facinv[400010];
int n, k;

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

inline int C(int n, int k) {
    return (LL)fac[n] * facinv[k] % mod * facinv[n - k] % mod;
}

inline void init() {
    fac[0] = facinv[0] = 1;
    for (int i = 1; i <= n + k; ++i) {
        fac[i] = (LL)fac[i - 1] * i % mod;
        facinv[i] = quickmul(fac[i], mod - 2) % mod;
    }
}

inline void work() {
    cin >> n >> k;
    k = min(k, n - 1);
    init();
    int ans = 0;
    for (int i = 0; i <= k; ++i) {
        ans += (LL)C(n, i) * C(n - 1, n - i - 1) % mod;
        ans %= mod;
    }
    cout << ans << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}