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

int a[200010], l[200010], r[200010], b[400010];
int n, k;

inline void work() {
    cin >> n >> k;
    memset(l, 0, sizeof(int) * (k + 1));
    memset(r, 0, sizeof(int) * (k + 1));
    memset(b, 0, sizeof(int) * (k * 2 + 1));
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i + i <= n; ++i) {
        ++l[min(a[i], a[n - i + 1])];
        ++r[max(a[i], a[n - i + 1])];
        ++b[a[i] + a[n - i + 1]];
    }
    
    int ans = n / 2;
    int sum = l[1];
    for (int i = 2; i <= k; ++i) {
        ans = min(ans, sum + (n / 2 - sum) * 2 - b[i]);
        sum += l[i];
    }
    for (int i = k + 1; i <= k + k; ++i) {
        ans = min(ans, sum + (n / 2 - sum) * 2 - b[i]);
        sum -= r[i - k];
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