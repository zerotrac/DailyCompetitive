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

int a[40010], b[40010];
int cnta[40010], cntb[40010];
int m, n;
LL k;

inline void report(int* cnt, int cur) {
    for (int i = 1; i <= cur; ++i) {
        cnt[i] += cur - i + 1;
    }
}

inline void work() {
    cin >> m >> n >> k;
    int cur = 0;
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
        if (a[i] == 1) {
            ++cur;
        }
        else {
            report(cnta, cur);
            cur = 0;
        }
    }
    if (cur) {
        report(cnta, cur);
    }
    cur = 0;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        if (b[i] == 1) {
            ++cur;
        }
        else {
            report(cntb, cur);
            cur = 0;
        }
    }
    if (cur) {
        report(cntb, cur);
    }
    LL ans = 0;
    for (int i = 1; i <= m; ++i) {
        if (k % i == 0 && k / i <= n) {
            ans += (LL)cnta[i] * cntb[k / i];
        }
    }
    cout << ans << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}