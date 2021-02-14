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

static constexpr int maxs = 17;
int f[200010][maxs + 1];
int dep[200010];

vector<vector<int>> edges;
int n, q, x, y;

void dfs(int u, int d, int fa) {
    f[u][0] = fa;
    dep[u] = d;
    for (int v: edges[u]) {
        if (!dep[v]) {
            dfs(v, d + 1, u);
        }
    }
}

inline int lift(int x, int d) {
    for (int i = maxs; i >= 0; --i) {
        if (d >= (1 << i)) {
            x = f[x][i];
            d -= (1 << i);
        }
    }
    return x;
}

inline int lca(int x, int y) {
    int dx = dep[x], dy = dep[y];
    if (dx < dy) {
        swap(x, y);
        swap(dx, dy);
    }
    x = lift(x, dx - dy);
    if (x == y) {
        return x;
    }
    for (int i = maxs; i >= 0; --i) {
        if (f[x][i] != f[y][i]) {
            x = f[x][i];
            y = f[y][i];
        }
    }
    return f[x][0];
}

inline void work() {
    cin >> n >> q;
    edges.resize(n + 1);
    for (int i = 1; i < n; ++i) {
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    dfs(1, 1, 0);

    for (int j = 1; j <= maxs; ++j) {
        for (int i = 1; i <= n; ++i) {
            f[i][j] = f[f[i][j - 1]][j - 1];
        }
    }

    for (int i = 1; i <= q; ++i) {
        cin >> x >> y;
        int dx = dep[x], dy = dep[y];
        int z = lca(x, y);
        int dz = dep[z];
        int ncnt = (dx - dz) + (dy - dz) + 1;
        LL ans = n + (LL)ncnt * (ncnt - 1) / 2;
        cout << ans << "\n";
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}