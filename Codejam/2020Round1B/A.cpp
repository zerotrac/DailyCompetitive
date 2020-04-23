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
// const int mod = 998244353;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

LL x, y;

inline bool finish(LL x, LL y) {
    return !x && !y;
}

inline bool check(LL x, LL y, LL s) {
    return (x % s == 0 && x % (s << 1) != 0 && y % (s << 1) == 0) || (y % s == 0 && y % (s << 1) != 0 && x % (s << 1) == 0);
}

inline void work() {
    cin >> x >> y;
    string ans = "";
    for (LL step = 1; !(!x && !y); step <<= 1) {
        if (finish(x, y + step)) {
            y += step;
            ans += 'S';
        }
        else if (finish(x, y - step)) {
            y -= step;
            ans += 'N';
        }
        else if (finish(x - step, y)) {
            x -= step;
            ans += 'E';
        }
        else if (finish(x + step, y)) {
            x += step;
            ans += 'W';
        }
        else if (check(x, y + step, step << 1)) {
            y += step;
            ans += 'S';
        }
        else if (check(x, y - step, step << 1)) {
            y -= step;
            ans += 'N';
        }
        else if (check(x - step, y, step << 1)) {
            x -= step;
            ans += 'E';
        }
        else if (check(x + step, y, step << 1)) {
            x += step;
            ans += 'W';
        }
        else {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    cout << ans << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; ++_) {
        work();
    }
    return 0;
}