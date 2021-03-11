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

unordered_set<int> edges[3010];
unordered_set<int> euler[3010];
vector<int> path;
int deg[3010];
int n, m, x, y;

void dfs(int u) {
    while (!euler[u].empty()) {
        int v = *euler[u].begin();
        euler[u].erase(v);
        euler[v].erase(u);
        dfs(v);
    }
    path.push_back(u);
}

void tour(int u) {
    path.clear();
    int odd_node = 0;
    for (int i = 1; i <= n; ++i) {
        if (euler[i].size() & 1) {
            ++odd_node;
        }
    }
    if (odd_node > 2) {
        return;
    }
    if (odd_node == 2 && !(euler[u].size() & 1)) {
        return;
    }
    dfs(u);
}

inline bool check() {
    for (int i = 1; i <= n; ++i) {
        if (!euler[i].empty()) {
            return false;
        }
    }
    return true;
}

inline void duplicate() {
    for (int i = 1; i <= n; ++i) {
        euler[i] = edges[i];
    }
}

inline void feed(int u, const vector<int>& candidates) {
    if (candidates.size()) {
        path.push_back(-1);
        for (int v: candidates) {
            path.push_back(v);
            path.push_back(u);
        }
    }
}

inline void work() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> x >> y;
        edges[x].insert(y);
        edges[y].insert(x);
        ++deg[x];
        ++deg[y];
    }

    bool found = false;

    for (int u = 1; u <= n && !found; ++u) {
        vector<int> candidates;
        for (int v: edges[u]) {
            if (deg[v] & 1) {
                candidates.push_back(v);
            }
        }
        duplicate();
        for (int v: candidates) {
            euler[u].erase(v);
            euler[v].erase(u);
        }
        tour(u);
        if (check()) {
            feed(u, candidates);
            found = true;
            break;
        }

        for (int i = 0; i < candidates.size(); ++i) {
            int vgood = candidates[i];
            duplicate();
            for (int v: candidates) {
                if (v != vgood) {
                    euler[u].erase(v);
                    euler[v].erase(u);
                }
            }
            tour(u);
            if (check()) {
                candidates.erase(candidates.begin() + i);
                feed(u, candidates);
                found = true;
                break;
            }
        }
    }

    if (!found) {
        cout << 0 << "\n";
    }
    else {
        cout << path.size() << "\n";
        for (int o: path) {
            cout << o << " ";
        }
        cout << "\n";
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}