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

int a[100010], shift[100010];
int n, m, x;

inline void work() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i];
    }

    shift[m] = n - (m + a[m] - 1);
    for (int i = m - 1; i >= 1; --i) {
        shift[i] = min(shift[i + 1], n - (i + a[i] - 1));
    }
    if (shift[1] < 0) {
        cout << "-1\n";
        return;
    }

    int cur = 0;
    vector<int> ans(m + 1);
    ans[1] = 1;
    for (int i = 2; i <= m; ++i) {
        ans[i] = ans[i - 1] + 1;
        int span = min(shift[i] - cur, a[i - 1] - 1);
        cur += span;
        ans[i] += span;
    }
    if (ans[m] + a[m] - 1 != n) {
        cout << "-1\n";
    }
    else {
        for (int i = 1; i <= m; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}