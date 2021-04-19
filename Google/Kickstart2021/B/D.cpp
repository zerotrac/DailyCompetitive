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

int n, q, x, y, l, c, w;
LL a;
LL ans[100010];
vector<vector<tuple<int, int, LL>>> edges;
vector<vector<pair<int, int>>> qs;
LL tree[800010];
int tmax;

LL query(int x, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) {
        return 0;
    }
    if (ql <= l && r <= qr) {
        return tree[x];
    }
    int mid = (l + r) / 2;
    return gcd(query(x * 2, l, mid, ql, qr), query(x * 2 + 1, mid + 1, r, ql, qr));
}

void update(int x, int l, int r, int ul, LL y) {
    if (ul < l || ul > r) {
        return;
    }
    if (l == r) {
        tree[x] = y;
        return;
    }
    int mid = (l + r) / 2;
    update(x * 2, l, mid, ul, y);
    update(x * 2 + 1, mid + 1, r, ul, y);
    tree[x] = gcd(tree[x * 2], tree[x * 2 + 1]);
}

void dfs(int u, int fa) {
    for (auto&& [idx, ww]: qs[u]) {
        ans[idx] = query(1, 1, tmax, 1, ww);
    }
    for (auto&& [v, ll, aa]: edges[u]) {
        if (v != fa) {
            update(1, 1, tmax, ll, aa);
            dfs(v, u);
            update(1, 1, tmax, ll, 0);
        }
    }
}

inline void work() {
    cin >> n >> q;
    tmax = 0;
    edges.clear();
    edges.resize(n + 1);
    for (int i = 1; i < n; ++i) {
        cin >> x >> y >> l >> a;
        edges[x].emplace_back(y, l, a);
        edges[y].emplace_back(x, l, a);
        tmax = max(tmax, l);
    }
    qs.clear();
    qs.resize(n + 1);
    for (int i = 1; i <= q; ++i) {
        cin >> c >> w;
        qs[c].emplace_back(i, w);
        tmax = max(tmax, w);
    }

    memset(tree, 0, sizeof(tree));
    dfs(1, 0);
    for (int i = 1; i <= q; ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";
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