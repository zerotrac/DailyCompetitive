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
const int mod = 1e9 + 7;
// const int mod = 998244353;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

unordered_map<int, vector<int>> edges;
int f[100010][2];
bool visited[100010];
int n, x, y;

void dfs(int u) {
    visited[u] = true;
    // 0-black 1-white
    f[u][0] = f[u][1] = 1;
    if (edges.count(u)) {
        for (int v: edges[u]) {
            if (!visited[v]) {
                dfs(v);
                f[u][0] = (LL)f[u][0] * f[v][1] % mod;
                f[u][1] = (LL)f[u][1] * (f[v][0] + f[v][1]) % mod;
            }
        }
    }
}

inline void work() {
    cin >> n;
    for (int i = 1; i < n; ++i) {
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    dfs(1);
    cout << (f[1][0] + f[1][1]) % mod << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}