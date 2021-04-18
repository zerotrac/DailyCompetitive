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

int n, x, y;
vector<vector<int>> edges;
int p = 0, pdist = 0;
bool path[200010];
int ans[200010];
int val = 1;

void dfs(int u, int fa, int dist) {
    if (dist > pdist) {
        p = u;
        pdist = dist;
    }
    for (int v: edges[u]) {
        if (v != fa) {
            dfs(v, u, dist + 1);
        }
    }
}

bool dfs2(int u, int fa) {
    if (u == p) {
        return path[u] = true;
    }
    for (int v: edges[u]) {
        if (v != fa) {
            dfs2(v, u);
            path[u] |= path[v];
        }
    }
    return path[u];
}

void dfs3(int u, int fa) {
    ans[u] = val;
    for (int v: edges[u]) {
        if (v != fa && !path[v]) {
            ++val;
            dfs3(v, u);
            ++val;
        }
    }
    for (int v: edges[u]) {
        if (v != fa && path[v]) {
            ++val;
            dfs3(v, u);
        }
    }
}

inline void work() {
    cin >> n;
    edges.resize(n + 1);
    for (int i = 1; i < n; ++i) {
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    // u-v is the diameter
    dfs(1, 0, 0);
    int u = p;
    pdist = 0;
    dfs(p, 0, 0);
    int v = p;
    dfs2(u, 0);
    dfs3(u, 0);

    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << "\n";
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}