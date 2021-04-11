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
int a[500010], l[500010], tree[500010], delay_upd[500010];

inline int lowbit(int x) {
    return x & (-x);
}

inline int query(int x) {
    int ret = 0;
    while (x) {
        ret = max(ret, tree[x]);
        x -= lowbit(x);
    }
    return ret;
}

inline void update(int x, int val) {
    while (x <= n) {
        tree[x] = max(tree[x], val);
        x += lowbit(x);
    }
}

inline void work() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        l[i] = 0;
        tree[i] = 0;
        delay_upd[i] = 0;
    }

    stack<int> s;
    for (int i = n; i >= 1; --i) {
        while (!s.empty() && a[i] > a[s.top()]) {
            l[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }

    vector<pair<int, int>> jump;
    for (int i = 1; i <= n; ++i) {
        if (l[i]) {
            jump.emplace_back(l[i], i);
        }
    }
    sort(jump.begin(), jump.end());

    int ans = 0;
    int j = 0;
    for (int i = 1; i <= n; ++i) {
        while (j < jump.size() && jump[j].first == i) {
            delay_upd[jump[j].second] = query(a[jump[j].second]) + 2;
            ++j;
        }
        int cur = max(query(a[i]) + 1, delay_upd[i]);
        ans = max(ans, cur);
        update(a[i], cur);
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