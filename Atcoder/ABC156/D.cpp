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

int inv[200010];
int n, a, b;

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
    int ans = 1;
    for (int i = k; i >= 1; --i) {
        ans = (LL)ans * (n - k + i) % mod;
        ans = (LL)ans * inv[i] % mod;
    }
    return ans;
}

inline void init() {
    inv[0] = 1;
    for (int i = 1; i <= max(a, b); ++i) {
        inv[i] = quickmul(i, mod - 2) % mod;
    }
}

inline void work() {
    cin >> n >> a >> b;
    init();
    cout << ((quickmul(2, n) - C(n, a) - C(n, b) - 1) % mod + mod) % mod << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}