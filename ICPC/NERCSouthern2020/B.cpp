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

int n, m;
int a[200010], k[200010], ans[200010];
LL sum[200010];

inline void work() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i) {
        cin >> k[i];
    }

    map<int, int> s;
    priority_queue<pair<int, int>> q;
    for (int i = 1; i <= n; ++i) {
        s[i] = i;
        sum[i] = a[i];
        if (i != n) {
            q.emplace(a[i] - 1, i);
        }
    }

    int cur = 0;
    for (int i = m; i >= 1; --i) {
        while (!q.empty() && get<0>(q.top()) >= k[i]) {
            auto [ts, l1] = q.top();
            q.pop();
            if (!s.count(l1)) {
                continue;
            }
            int r1 = s[l1];
            auto it = s.upper_bound(l1);
            int l2 = it->first;
            int r2 = it->second;
            cur = max(cur, r2 - l1);
            sum[l1] += sum[l2];
            s[l1] = r2;
            s.erase(l2);
            if (r2 != n) {
                q.emplace((sum[l1] - 1) / (r2 - l1 + 1), l1);
            }
        }
        ans[i] = cur;
    }
    
    for (int i = 1; i <= m; ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}