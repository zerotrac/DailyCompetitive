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
const int mod = 998244353;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int m, n, L, R;

inline int quickmul(int x, LL y) {
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
    cin >> m >> n >> L >> R;
    if (m % 2 == 1 && n % 2 == 1) {
        cout << quickmul(R - L + 1, (LL)m * n) << "\n";
    }
    else {
        int inv2 = quickmul(2, mod - 2);
        if ((R - L + 1) % 2 == 0) {
            cout << (LL)quickmul(R - L + 1, (LL)m * n) * inv2 % mod << "\n";
        }
        else {
            cout << ((LL)quickmul(R - L + 1, (LL)m * n) + 1) * inv2 % mod << "\n";
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}