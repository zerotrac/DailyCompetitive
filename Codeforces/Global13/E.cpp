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

static constexpr int MAXN = 200000;

int n, x, y;
unordered_map<int, pair<int, int>> fib;

inline void init() {
    int a = 1, b = 1;
    while (a + b <= MAXN) {
        int c = a + b;
        fib[c] = {a, b};
        tie(a, b) = {b, c};
    }
}

vector<vector<int>> edges_bi;
vector<unordered_set<int>> edges_uni;
int parent[MAXN + 10], sz[MAXN + 10];
int q[MAXN + 10];

void dfs(int u, int fa) {
    parent[u] = fa;
    sz[u] = 1;
    for (int v: edges_bi[u]) {
        if (v != fa) {
            dfs(v, u);
            edges_uni[u].insert(v);
            sz[u] += sz[v];
        }
    }
}

inline void dec(int u, int dt) {
    while (u) {
        sz[u] -= dt;
        u = parent[u];
    }
}

bool split(int u) {
    if (sz[u] == 1 || sz[u] == 2) {
        return true;
    }

    auto [fit_a, fit_b] = fib[sz[u]];
    int head = 0, tail = 0;
    q[0] = u;

    int candidate = 0;
    while (head <= tail) {
        int v = q[head++];
        if (sz[v] == fit_a || sz[v] == fit_b) {
            candidate = v;
            break;
        }
        for (int w: edges_uni[v]) {
            q[++tail] = w;
        }
    }

    if (!candidate) {
        return false;
    }

    dec(parent[candidate], sz[candidate]);
    edges_uni[parent[candidate]].erase(candidate);
    parent[candidate] = 0;
    return split(u) && split(candidate);
}

inline void work() {
    cin >> n;
    if (n != 1 && !fib.count(n)) {
        cout << "NO\n";
        return;
    }

    edges_uni.resize(n + 1);
    edges_bi.resize(n + 1);
    for (int i = 1; i < n; ++i) {
        cin >> x >> y;
        edges_bi[x].push_back(y);
        edges_bi[y].push_back(x);
    }

    dfs(1, 0);
    cout << (split(1) ? "YES" : "NO") << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    init();
    work();
    return 0;
}