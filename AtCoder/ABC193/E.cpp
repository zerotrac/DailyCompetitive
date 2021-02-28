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

#include <atcoder/math>

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

LL x, y, p, q;

inline void work() {
    cin >> x >> y >> p >> q;
    LL ans = LLONG_MAX;
    for (LL i = x; i < x + y; ++i) {
        for (LL j = p; j < p + q; ++j) {
            auto [u, v] = atcoder::crt({i, j}, {(x + y) * 2, p + q});
            if (v) {
                ans = min(ans, u);
            }
        }
    }
    if (ans == LLONG_MAX) {
        cout << "infinity" << "\n";
    }
    else {
        cout << ans << "\n";
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    int T;
    cin >> T;
    while (T--) {
        work();
    }
    return 0;
}