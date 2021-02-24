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
const int mod = 1e9 + 7;
// const int mod = 998244353;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int dep[200010];
LL val[200010];
LL f[200010];
int n, x;
vector<vector<int>> edges;

void dfs(int u, int d) {
    dep[u] = d;
    for (int v: edges[u]) {
        if (!dep[v]) {
            dfs(v, d + 1);
        }
    }
}

inline void work() {
    cin >> n;
    edges = vector<vector<int>>(n + 1);
    for (int i = 1; i <= n; ++i) {
        dep[i] = 0;
        f[i] = 0;
    }
    for (int i = 2; i <= n; ++i) {
        cin >> x;
        edges[i].push_back(x);
        edges[x].push_back(i);
    }
    dfs(1, 1);

    for (int i = 2; i <= n; ++i) {
        cin >> val[i];
    }

    vector<int> q = {1};
    while (true) {
        vector<int> r;
        LL minv = LLONG_MAX, maxv = LLONG_MIN, maxplus = LLONG_MIN, maxminus = LLONG_MIN;
        for (int u: q) {
            for (int v: edges[u]) {
                if (dep[v] > dep[u]) {
                    r.push_back(v);
                    minv = min(minv, val[v]);
                    maxv = max(maxv, val[v]);
                    maxplus = max(maxplus, f[u] + val[v]);
                    maxminus = max(maxminus, f[u] - val[v]);
                }
            }
        }
        if (r.empty()) {
            break;
        }

        for (int u: q) {
            for (int v: edges[u]) {
                if (dep[v] > dep[u]) {
                    f[v] = max(f[v], f[u] + maxv - val[v]);
                    f[v] = max(f[v], f[u] + val[v] - minv);
                    f[v] = max(f[v], maxplus - val[v]);
                    f[v] = max(f[v], maxminus + val[v]);
                }
            }
        }

        q = move(r);
    }

    cout << *max_element(f + 1, f + n + 1) << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    int T;
    cin >> T;
    while (T--) {
        work();
    }
    return 0;
}
