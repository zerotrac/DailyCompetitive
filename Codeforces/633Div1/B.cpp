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
int deg[100010], dist[100010];
int n, x, y, ans;

void dfs1(int u, int d) {
    dist[u] = d;
    for (int v: edges[u]) {
        if (dist[v] == -1){
            dfs1(v, d + 1);
        }
    }
}

void dfs2(int u, int fa) {
    int leaf_cnt = 0;
    for (int v: edges[u]) {
        if (v != fa) {
            if (deg[v] == 1) {
                ++leaf_cnt;
            }
            else {
                dfs2(v, u);
            }
        }
    }
    if (leaf_cnt) {
        ans -= leaf_cnt - 1;
    }
}

inline void work() {
    cin >> n;
    for (int i = 1; i < n; ++i) {
        cin >> x >> y;
        ++deg[x];
        ++deg[y];
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    int leaf = -1, root = -1;
    for (int i = 1; i <= n; ++i) {
        if (deg[i] == 1) {
            leaf = i;
        }
        else if (deg[i] > 1) {
            root = i;
        }
    }
    
    memset(dist, -1, sizeof(dist));
    dfs1(leaf, 0);
    bool flag = true;
    for (int i = 1; i <= n; ++i) {
        if (deg[i] == 1 && (dist[i] & 1)) {
            flag = false;
            break;
        }
    }
    cout << (flag ? 1 : 3) << " ";

    ans = n - 1;
    dfs2(root, -1);
    cout << ans << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}