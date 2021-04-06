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

int n, k, x, y;
int a[100010], f[100010][45], value[100010];
vector<vector<int>> edges(n + 1);

void dfs(int u, int fa) {
    for (int v: edges[u]) {
        if (v != fa) {
            dfs(v, u);
            for (int i = 0; i < k * 2; ++i) {
                f[u][i] ^= f[v][(i + 1) % (k * 2)];
            }
        }
    }
    for (int i = k; i < k * 2; ++i) {
        f[u][i] ^= a[u];
    }
}

void dfs2(int u, int fa, const vector<int>& prev) {
    value[u] = f[u][0] ^ prev[1];
    vector<int> curr(prev.size());
    for (int i = 0; i < k * 2; ++i) {
        curr[i] = prev[(i + 1) % (k * 2)];
    }
    for (int i = k; i < k * 2; ++i) {
        curr[i] ^= a[u];
    }
    for (int v: edges[u]) {
        if (v != fa) {
            for (int i = 0; i < k * 2; ++i) {
                curr[i] ^= f[v][(i + 1) % (k * 2)];
            }
        }
    }
    for (int v: edges[u]) {
        if (v != fa) {
            for (int i = 0; i < k * 2; ++i) {
                curr[i] ^= f[v][(i + 1) % (k * 2)];
            }
            dfs2(v, u, curr);
            for (int i = 0; i < k * 2; ++i) {
                curr[i] ^= f[v][(i + 1) % (k * 2)];
            }
        }
    }
}

inline void work() {
    cin >> n >> k;
    edges.resize(n + 1);
    for (int i = 1; i < n; ++i) {
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    dfs(1, 0);
    dfs2(1, 0, vector<int>(k * 2, 0));

    for (int i = 1; i <= n; ++i) {
        cout << (value[i] != 0) << " ";
    }
    cout << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}