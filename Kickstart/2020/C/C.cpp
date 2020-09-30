#include <iostream>
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

int n, x;

inline void work() {
    cin >> n;
    unordered_map<int, int> prev = {{0, 1}};
    LL ans = 0;
    int sum = 0;
    int sub_cur = 0, sub_max = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        sum += x;
        sub_cur = max(sub_cur + x, 0);
        sub_max = max(sub_max, sub_cur);
        for (int j = 0; j * j <= sub_max; ++j) {
            if (prev.count(sum - j * j)) {
                ans += prev[sum - j * j];
            }
        }
        ++prev[sum];
    }
    cout << ans << "\n";
}

int main() {
    // freopen("C.txt", "r", stdin);
    quickread();
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; ++_) {
        cout << "Case #" << _ << ": ";
        work();
    }
    return 0;
}