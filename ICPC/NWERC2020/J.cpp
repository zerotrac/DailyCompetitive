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

int n, m, x, y;
vector<vector<int>> edges;
int cnt0, cnt1;

vector<int> path;
int color[200010];

void dfs(int u) {
    --cnt0;
    color[u] = 1;
    path.push_back(u);
    if (cnt0 == cnt1) {
        return;
    }

    for (int v: edges[u]) {
        if (!color[v]) {
            dfs(v);
            if (cnt0 == cnt1) {
                return;
            }
        }
    }

    ++cnt1;
    color[u] = 2;
    path.pop_back();
}

inline void work() {
    cin >> n >> m;
    edges.resize(n + 1);
    for (int i = 1; i <= m; ++i) {
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    cnt0 = n;
    cnt1 = 0;

    dfs(1);

    cout << path.size() << " " << (n - path.size()) / 2 << "\n";
    for (int o: path) cout << o << " ";
    cout << "\n";
    for (int i = 1; i <= n; ++i) {
        if (color[i] == 0) {
            cout << i << " ";
        }
    }
    cout << "\n";
    for (int i = 1; i <= n; ++i) {
        if (color[i] == 2) {
            cout << i << " ";
        }
    }
    cout << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}