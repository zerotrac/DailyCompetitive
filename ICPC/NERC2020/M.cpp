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

int last[100010], indeg[100010], f[100010];
int n, x, y;

inline void work() {
    cin >> n;
    unordered_map<int, vector<int>> edges;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        for (int j = 1; j <= x; ++j) {
            cin >> y;
            if (last[y]) {
                edges[i].push_back(last[y]);
                ++indeg[last[y]];
            }
            last[y] = i;
        }
    }

    int ans = 0;
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (!indeg[i]) {
            q.push(i);
            f[i] = 1;
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans = max(ans, f[u]);
        if (edges.count(u)) {
            for (int v: edges[u]) {
                --indeg[v];
                f[v] = max(f[v], f[u] + 1);
                if (!indeg[v]) {
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