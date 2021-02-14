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

int n;
int fa[100010];
int f[100010], sz[100010];
vector<vector<int>> edges;

void dfs(int u) {
    ++sz[u];
    vector<int> samegood;
    vector<int> samebad;
    vector<int> diff;
    
    for (int v: edges[u]) {
        dfs(v);
        sz[u] += sz[v];
        if (sz[v] % 2 == 0) {
            if (f[v] * 2 >= sz[v]) {
                samegood.push_back(v);
            }
            else {
                samebad.push_back(v);
            }
        }
        else {
            diff.push_back(v);
        }
    }

    ++f[u];
    for (int v: samebad) {
        f[u] += f[v];
    }

    sort(diff.begin(), diff.end(), [&](int v1, int v2) {
        return sz[v1] - f[v1] * 2 > sz[v2] - f[v2] * 2;
    });
    for (int i = 0; i < diff.size(); ++i) {
        int v = diff[i];
        if (i & 1) {
            f[u] += sz[v] - f[v];
        }
        else {
            f[u] += f[v];
        }
    }
    
    for (int v: samegood) {
        if (diff.size() & 1) {
            f[u] += sz[v] - f[v];
        }
        else {
            f[u] += f[v];
        }
    }

    // cout << "u = " << u << " " << f[u] << " " << sz[u] << endl;
}

inline void work() {
    cin >> n;
    edges.resize(n + 1);
    for (int i = 2; i <= n; ++i) {
        cin >> fa[i];
        edges[fa[i]].push_back(i);
    }
    dfs(1);
    cout << f[1] << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}