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
int c[100010];
bool good[100010];
vector<vector<int>> edges;
unordered_map<int, int> rec;

void dfs(int u, int fa) {
    if (!rec.count(c[u])) {
        good[u] = true;
        rec[c[u]] = u;
    }
    else {
        good[u] = false;
    }

    for (int v: edges[u]) {
        if (v != fa) {
            dfs(v, u);
        }
    }

    if (rec[c[u]] == u) {
        rec.erase(c[u]);
    }
}

inline void work() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }
    edges.resize(n + 1);
    for (int i = 1; i < n; ++i) {
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; ++i) {
        if (good[i]) {
            cout << i << "\n";
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}