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

int m, n, k;

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

inline void work() {
    cin >> m >> n >> k;
    if (m == 1 && n == 1) {
        cout << k << "\n";
    }
    else if (m == 1) {
        int ans = quickmul(k, n);
        cout << ans << "\n";
    }
    else if (n == 1) {
        int ans = quickmul(k, m);
        cout << ans << "\n";
    }
    else {
        int ans = 0;
        for (int minv = 1; minv <= k; ++minv) {
            int extra = (LL)((quickmul(minv, m) - quickmul(minv - 1, m) + mod) % mod) * quickmul(k - minv + 1, n) % mod;
            ans = (ans + extra) % mod;
        }
        cout << ans << "\n";
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}