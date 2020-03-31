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

unordered_map<int, vector<int>> edges;
int f[100010], sz[100010];
int uniq[100010];
int n, m, x, y;

void dfs1(int u) {
    f[u] = sz[u] = uniq[u] = 1;
    if (edges.count(u)) {
        for (int v: edges[u]) {
            if (edges.count(v)) {
                edges[v].erase(remove(edges[v].begin(), edges[v].end(), u), edges[v].end());
            }
            dfs1(v);
            f[u] = (LL)f[u] * (f[v] + 1) % m;
            sz[u] += sz[v];
        }
        int preprod = 1;
        for (int i = 1; i < edges[u].size(); ++i) {
            preprod = (LL)preprod * (f[edges[u][i - 1]] + 1) % m;
            uniq[edges[u][i]] = (LL)uniq[edges[u][i]] * preprod % m;
        }
        int sufprod = 1;
        for (int i = edges[u].size() - 2; i >= 0; --i) {
            sufprod = (LL)sufprod * (f[edges[u][i + 1]] + 1) % m;
            uniq[edges[u][i]] = (LL)uniq[edges[u][i]] * sufprod % m;
        }
    }
}

void dfs2(int u) {
    if (edges.count(u)) {
        for (int v: edges[u]) {
            if (u != 1) {
                uniq[v] = (LL)uniq[v] * (uniq[u] + 1) % m;
            }
            f[v] = (LL)f[v] * (uniq[v] + 1) % m;
            dfs2(v);
        }
    }
}

inline void work() {
    cin >> n >> m;
    for (int i = 1; i < n; ++i) {
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    dfs1(1);
    dfs2(1);
    for (int i = 1; i <= n; ++i) {
        cout << f[i] << "\n";
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}