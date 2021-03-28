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

int n, k, x, y, cnt;
vector<vector<int>> edges;
int dep[200010];
// 0=is a point
// x=has a point in distance x (x <= k)
// -x=does not controlled for consecutive x nodes (x <= k)
int f[200010];

void dfs(int u, int d) {
    dep[u] = d;
    for (int v: edges[u]) {
        if (!dep[v]) {
            dfs(v, d + 1);
        }
    }
}

void dfs2(int u, int mid) {
    int uncontroll = 0;
    int closest = INT_MAX;
    for (int v: edges[u]) {
        if (dep[v] > dep[u]) {
            dfs2(v, mid);
            if (f[v] >= 0) {
                closest = min(closest, f[v] + 1);
            }
            else {
                uncontroll = max(uncontroll, -f[v]);
            }
        }
    }
    if (closest != INT_MAX && closest + uncontroll <= mid) {
        f[u] = closest;
    }
    else if (uncontroll + 1 <= mid) {
        f[u] = -(uncontroll + 1);
    }
    else {
        ++cnt;
        f[u] = 0;
    }
}

inline void work() {
    cin >> n >> k;
    if (n == k) {
        cout << "0\n";
        return;
    }

    edges.resize(n + 1);
    for (int i = 1; i < n; ++i) {
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    dfs(1, 1);

    int l = 1, r = n - 1, ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        cnt = 0;
        memset(f, 0, sizeof(f));
        dfs2(1, mid);
        if (f[1] < 0) {
            ++cnt;
        }
        if (cnt <= k) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
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