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
int color[200010], indeg[200010];

inline void work() {
    cin >> n >> m;
    edges.resize(n + m);
    for (int i = 1; i <= n + m; ++i) {
        cin >> x >> y;
        if (x < n && y < n) {
            // no need to handle that
        }
        else {
            if (x < y) {
                swap(x, y);
            }
            edges[x].push_back(y);
            ++indeg[y];
        }
    }

    queue<int> q;
    for (int i = 0; i < n + m; ++i) {
        if (!indeg[i]) {
            q.push(i);
        }
    }

    int ans = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans += color[u];
        for (int v: edges[u]) {
            if (!color[u]) {
                color[v] = 1;
            }
            if (--indeg[v] == 0) {
                q.push(v);
            }
        }
    }

    vector<int> circ;
    for (int i = 0; i < n; ++i) {
        if (color[i]) {
            circ.push_back(i);
        }
    }

    auto extra = [](int x) {
        return x / 2;
    };

    if (circ.empty()) {
        ans += extra(n);
    }
    else if (circ.size() == 1) {
        ans += extra(n - 1);
    }
    else {
        for (int i = 1; i < circ.size(); ++i) {
            ans += extra(circ[i] - circ[i - 1] - 1);
        }
        ans += extra(n + circ[0] - circ.back() - 1);
    }

    cout << ans << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}