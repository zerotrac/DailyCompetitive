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
int g[1010][1010];
bool used[200010], large[200010];
int cur = 0;

void dfs(int u) {
    ++cur;
    used[u] = true;
    for (int i = 1; i <= n; ++i) {
        if (!used[i] && !g[u][i]) {
            dfs(i);
        }
    }
}

inline void do1() {
    for (int i = 1; i <= m; ++i) {
        cin >> x >> y;
        g[x][y] = g[y][x] = 1;
    }
    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            cur = 0;
            dfs(i);
            ans.push_back(cur);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (int o: ans) {
        cout << o << " ";
    }
    cout << "\n";
}

inline void do2() {
    int maxcomp = 0;
    while ((maxcomp + 1) * (n - maxcomp - 1) <= m) {
        ++maxcomp;
    }
    if (!maxcomp) {
        cout << 1 << "\n";
        cout << n << "\n";
    }

    vector<vector<int>> edges(n + 1);
    for (int i = 1; i <= m; ++i) {
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i) {
        sort(edges[i].begin(), edges[i].end());
    }
    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
        if (used[i]) {
            continue;
        }

        queue<int> q;
        q.push(i);
        used[i] = true;
        vector<int> hist = {i};
        bool good = true;
        while (!q.empty() && good) {
            int u = q.front();
            q.pop();
            int ptr = 0;
            for (int v = 1; v <= n; ++v) {
                if (u == v) {
                    continue;
                }
                if (ptr < edges[u].size() && v == edges[u][ptr]) {
                    ++ptr;
                    continue;
                }
                if (large[v]) {
                    good = false;
                    break;
                }
                if (!used[v]) {
                    q.push(v);
                    hist.push_back(v);
                    used[v] = true;
                    if (hist.size() > maxcomp) {
                        good = false;
                        break;
                    }
                }
            }
        }
        if (good) {
            ans.push_back(hist.size());
        }
        else {
            for (int o: hist) {
                large[o] = true;
            }
        }
    }

    int total = accumulate(ans.begin(), ans.end(), 0);
    if (total < n) {
        ans.push_back(n - total);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (int o: ans) {
        cout << o << " ";
    }
    cout << "\n";
}

inline void work() {
    cin >> n >> m;
    if (n <= 1000) {
        do1();
    }
    else {
        do2();
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}