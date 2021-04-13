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
// const int mod = 998244353;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int n;
int x, y, u, v;

struct PairHash {
    size_t operator() (const pair<int, int>& o) const {
        return (hash<int>()(o.first) << 16) ^ hash<int>()(o.second);
    }
};

inline void work() {
    cin >> n;
    unordered_map<pair<int, int>, int, PairHash> cnt;
    for (int i = 1; i <= n; ++i) {
        cin >> x >> y >> u >> v;
        int dx = u - x;
        int dy = v - y;
        int g = gcd(dx, dy);
        dx /= g;
        dy /= g;
        ++cnt[{dx, dy}];
    }

    LL ans = 0;
    for (const auto& [k, v1]: cnt) {
        const auto& [dx, dy] = k;
        if (cnt.count({-dx, -dy})) {
            ans += (LL)v1 * cnt[{-dx, -dy}];
        }
    }
    cout << ans / 2 << "\n";
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