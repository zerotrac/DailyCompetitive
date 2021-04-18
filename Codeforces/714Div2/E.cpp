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
const int mod = 1e9 + 7;
// const int mod = 998244353;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int n;
int a[100010];
int fac[100010], inv[100010];

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
    fac[0] = inv[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fac[i] = (LL)fac[i - 1] * i % mod;
        inv[i] = quickmul(fac[i], mod - 2);
    }
}

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

inline void work() {
    cin >> n;
    init();

    LL sum = 0;
    unordered_map<int, int, custom_hash> freq;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ++freq[a[i]];
        sum += a[i];
    }
    if (sum % n != 0) {
        cout << "0\n";
        return;
    }
    int avg = sum / n;

    int larger = 0, smaller = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] > avg) {
            ++larger;
        }
        else if (a[i] < avg) {
            ++smaller;
        }
    }

    int ans = 1;
    if (larger <= 1 || smaller <= 1) {
        // ans = n!
        for (int i = 1; i <= n; ++i) {
            ans = (LL)ans * i % mod;
        }
    }
    else {
        // ans = C(n, larger + smaller) * larger! * smaller! * 2 * (n - larger - smaller)!
        //     = n! / (larger + smaller)! * larger! * smaller! * 2
        for (int i = larger + smaller + 1; i <= n; ++i) {
            ans = (LL)ans * i % mod;
        }
        for (int i = 1; i <= larger; ++i) {
            ans = (LL)ans * i % mod;
        }
        for (int i = 1; i <= smaller; ++i) {
            ans = (LL)ans * i % mod;
        }
        ans = ans * 2 % mod;
    }

    for (auto&& [_, cnt]: freq) {
        ans = (LL)ans * inv[cnt] % mod;
    }
    cout << ans << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}