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

LL l, r;

inline void work() {
    cin >> l >> r;
    bool rev = false;
    if (l < r) {
        swap(l, r);
        rev = true;
    }
    // l >= r
    LL delta = l - r;
    LL u = 1, v = 2000000000, ans1 = 0;
    while (u <= v) {
        LL mid = (u + v) / 2;
        if ((rev && mid * (mid + 1) / 2 >= delta) || (!rev && mid * (mid + 1) / 2 > delta)) {
            ans1 = mid;
            v = mid - 1;
        }
        else {
            u = mid + 1;
        }
    }
    if (ans1 * (ans1 + 1) / 2 > l) {
        if (rev) {
            cout << ans1 - 1 << " " << r << " " << l - ans1 * (ans1 - 1) / 2 << "\n";
        }
        else {
            cout << ans1 - 1 << " " << l - ans1 * (ans1 - 1) / 2 << " " << r << "\n";
        }
        return;
    }

    l -= ans1 * (ans1 + 1) / 2;
    // (ans1 + 1) * k + k * (k - 1)
    // (ans1 + 2) * k + k * (k - 1)
    u = 1, v = 2000000000;
    LL ans2 = 0;
    while (u <= v) {
        LL mid = (u + v) / 2;
        if ((ans1 + 1) * mid + mid * (mid - 1) <= r && (ans1 + 2) * mid + mid * (mid - 1) <= l) {
            ans2 = mid;
            u = mid + 1;
        }
        else {
            v = mid - 1;
        }
    }
    l -= (ans1 + 2) * ans2 + ans2 * (ans2 - 1);
    r -= (ans1 + 1) * ans2 + ans2 * (ans2 - 1);
    ans1 += ans2 * 2;
    if (r >= ans1 + 1) {
        r -= ans1 + 1;
        ++ans1;
    }
    if (rev) {
        cout << ans1 << " " << r << " " << l << "\n";
    }
    else {
        cout << ans1 << " " << l << " " << r << "\n";
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; ++_) {
        cout << "Case #" << _ << ": ";
        work();
    }
    return 0;
}