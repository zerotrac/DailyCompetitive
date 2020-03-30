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

LL tree[200010];
int h[200010], a[200010];
int n;

inline int lowbit(int x) {
    return x & (-x);
}

inline LL query(int x) {
    LL ret = 0;
    while (x) {
        ret = max(ret, tree[x]);
        x -= lowbit(x);
    }
    return ret;
}

inline void update(int x, LL v) {
    while (x <= n) {
        tree[x] = max(tree[x], v);
        x += lowbit(x);
    }
}

inline void work() {
    cin >> n;
    LL ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        LL value = query(h[i]);
        ans = max(ans, value + a[i]);
        update(h[i], value + a[i]);
    }
    cout << ans << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}