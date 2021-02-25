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
string name[110], lang[110];
vector<unordered_set<string>> listen;
string st;
int g[110][110];
int low[110], dfn[110], stk[110];
stack<int> nodes;
int ts = 0, ans = 0;

void dfs(int u) {
    low[u] = dfn[u] = ++ts;
    stk[u] = true;
    nodes.push(u);
    for (int v = 1; v <= n; ++v) {
        if (g[u][v] != 1) {
            continue;
        }
        if (!dfn[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if (stk[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (low[u] == dfn[u]) {
        int cnt = 1;
        while (nodes.top() != u) {
            ++cnt;
            stk[nodes.top()] = false;
            nodes.pop();
        }
        stk[u] = false;
        nodes.pop();
        ans = max(ans, cnt);
    }
}

inline void work() {
    cin >> n;
    listen.resize(n + 1);
    getline(cin, st);
    for (int i = 1; i <= n; ++i) {
        getline(cin, st);
        stringstream ss;
        ss << st;
        ss >> name[i] >> lang[i];
        while (ss >> st) {
            listen[i].insert(st);
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) {
                continue;
            }
            if (listen[j].count(lang[i]) || lang[j] == lang[i]) {
                g[i][j] = 1;
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) {
            dfs(i);
        }
    }

    cout << n - ans << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}