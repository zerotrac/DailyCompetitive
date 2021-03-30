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
LL x;

inline void work() {
    cin >> n;
    LL sum0 = 0, sum1 = 0;
    LL min0 = LLONG_MAX, min1 = LLONG_MAX;
    LL cnt0 = 0, cnt1 = 0;
    LL ans = LLONG_MAX;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        if (i & 1) {
            sum0 += x;
            min0 = min(min0, x);
            ++cnt0;
        }
        else {
            sum1 += x;
            min1 = min(min1, x);
            ++cnt1;
        }
        if (i > 1) {
            ans = min(ans, (sum0 - min0) + min0 * (n - cnt0 + 1) + (sum1 - min1) + min1 * (n - cnt1 + 1));
        }
    }
    cout << ans << "\n";
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