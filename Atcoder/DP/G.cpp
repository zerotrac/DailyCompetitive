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
// const int mod = 1e9 + 7;
// const int mod = 998244353;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

unordered_map<int, vector<int>> edges;
int indeg[100010], f[100010];
int n, m, x, y;

inline void work() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        edges[x].push_back(y);
        ++indeg[y];
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (!indeg[i]) {
            q.push(i);
        }
    }

    int ans = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (edges.count(u)) {
            for (int v: edges[u]) {
                ans = max(ans, f[v] = max(f[v], f[u] + 1));
                if (--indeg[v] == 0) {
                    q.push(v);
                }
            }
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