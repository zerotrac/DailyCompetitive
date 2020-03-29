#include <iostream>
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
const int mod = 1e9 + 7;
// const int mod = 998244353;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int edge[400010], nxt[400010], head[200010];
int ecnt = 0;

int fac[200010], facinv[200010];
int dp[200010], sz[200010];
int n, x, y;

inline int quickmul(int x, int y) {
    int ret = 1, mul = x;
    while (y) {
        if (y & 1) {
            ret = (LL)ret * mul % mod;
        }
        mul = (LL)mul * mul % mod;
        y >>= 1;
    }
    return ret;
}

inline void addedge(int x, int y) {
    ++ecnt;
    edge[ecnt] = y;
    nxt[ecnt] = head[x];
    head[x] = ecnt;
}

void dfs1(int u) {
    dp[u] = sz[u] = 1;
    for (int i = head[u]; i; i = nxt[i]) {
        int v = edge[i];
        if (!sz[v]) {
            dfs1(v);
            dp[u] = (LL)dp[u] * dp[v] % mod * facinv[sz[v]] % mod;
            sz[u] += sz[v];
        }
    }
    dp[u] = (LL)dp[u] * fac[sz[u] - 1] % mod;
}

void dfs2(int u) {
    for (int i = head[u]; i; i = nxt[i]) {
        int v = edge[i];
        if (sz[v] < sz[u]) {
            dp[v] = (LL)dp[u] * fac[n - sz[v] - 1] % mod * fac[sz[v]] % mod * facinv[sz[v] - 1] % mod * facinv[n - sz[v]] % mod;
            dfs2(v);
        }
    }
}

inline void work() {
    cin >> n;
    fac[0] = facinv[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fac[i] = (LL)fac[i - 1] * i % mod;
        facinv[i] = quickmul(fac[i], mod - 2);
    }
    for (int i = 1; i < n; ++i) {
        cin >> x >> y;
        addedge(x, y);
        addedge(y, x);
    }
    dfs1(1);
    dfs2(1);
    for (int i = 1; i <= n; ++i) {
        cout << dp[i] << "\n";
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}