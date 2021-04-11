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

int n, k, x, y, z;
vector<vector<int>> edges;
bool good[100010];
int dep[100010], cnt[100010];
int ans = 0;

void dfs(int u, int d) {
    dep[u] = d;
    for (int v: edges[u]) {
        if (!dep[v]) {
            dfs(v, d + 1);
            cnt[u] += cnt[v];
        }
    }
}

void dfs2(int u, bool outside) {
    if (good[u]) {
        ++ans;
    }
    else if (outside && cnt[u]) {
        ++ans;
    }
    else {
        int has = 0;
        for (int v: edges[u]) {
            if (dep[v] > dep[u] && cnt[v]) {
                ++has;
            }
        }
        if (has >= 2) {
            ++ans;
        }
    }
    for (int v: edges[u]) {
        if (dep[v] > dep[u]) {
            dfs2(v, outside || (cnt[v] != cnt[u]));
        }
    }
}

inline void work() {
    cin >> n >> k;
    edges.resize(n + 1);
    for (int i = 1; i < n; ++i) {
        cin >> x >> y >> z;
        edges[x].emplace_back(y);
        edges[y].emplace_back(x);
    }
    for (int i = 1; i <= k; ++i) {
        cin >> x;
        good[x] = true;
        cnt[x] = 1;
    }
    dfs(1, 1);
    dfs2(1, false);
    cout << ans << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}