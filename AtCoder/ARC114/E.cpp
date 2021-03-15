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

int h, w, h1, w1, h2, w2;

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

inline int inv(int x) {
    return quickmul(x, mod - 2);
}

inline int get(int x, int y) {
    int ret = 0;
    for (int i = 1; i <= x; ++i) {
        ret += inv(i + y);
        if (ret >= mod) {
            ret -= mod;
        }
    }
    return ret;
}

inline void work() {
    cin >> h >> w >> h1 >> w1 >> h2 >> w2;
    tie(h1, h2) = minmax({h1, h2});
    tie(w1, w2) = minmax({w1, w2});
    int a = h1 - 1;
    int b = h - h2;
    int c = w1 - 1;
    int d = w - w2;
    int e = (h2 - h1) + (w2 - w1);

    int ans = (1LL + get(a, e) + get(b, e) + get(c, e) + get(d, e)) % mod;
    cout << ans << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}