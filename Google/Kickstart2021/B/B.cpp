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
int a[300010], b[300010], l[300010], r[300010];

inline void work() {
    cin >> n;
    
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        b[i] = 0;
        l[i] = r[i] = 0;
    }
    if (n <= 3) {
        cout << n << "\n";
        return;
    }

    // b[1 .. n-1]
    for (int i = 1; i < n; ++i) {
        b[i] = a[i + 1] - a[i];
    }

    int ans = 3;
    int prev = b[1], cnt = 1;
    for (int i = 2; i < n; ++i) {
        if (b[i] == prev) {
            ++cnt;
        }
        else {
            prev = b[i];
            cnt = 1;
        }
        ans = max(ans, cnt + 2);
    }
    ans = min(ans, n);

    l[1] = 1;
    for (int i = 2; i < n; ++i) {
        if (b[i] == b[i - 1]) {
            l[i] = l[i - 1] + 1;
        }
        else {
            l[i] = 1;
        }
    }
    r[n - 1] = 1;
    for (int i = n - 2; i >= 1; --i) {
        if (b[i] == b[i + 1]) {
            r[i] = r[i + 1] + 1;
        }
        else {
            r[i] = 1;
        }
    }

    for (int i = 1; i < n - 1; ++i) {
        // (i, i+1) pair
        if (i - 1 >= 1 && b[i - 1] * 2 == b[i] + b[i + 1]) {
            ans = max(ans, l[i - 1] + 3);
        }
        if (i + 2 < n && b[i + 2] * 2 == b[i] + b[i + 1]) {
            ans = max(ans, r[i + 2] + 3);
        }
        if (i - 1 >= 1 && i + 2 < n && b[i - 1] * 2 == b[i] + b[i + 1] && b[i + 2] * 2 == b[i] + b[i + 1]) {
            ans = max(ans, l[i - 1] + r[i + 2] + 3);
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
        cout << "Case #" << _ << ": ";
        work();
    }
    return 0;
}