// https://loj.ac/problem/10091
// https://www.luogu.com.cn/problem/P2341

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

#include "../tarjanscc.cpp"

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

vector<vector<int>> edges;
int n, m, x, y;

inline void work() {
    cin >> n >> m;
    edges.resize(n);
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        edges[x - 1].push_back(y - 1);
    }
    auto [scc_cnt, group] = TarjanSCC::getSCC(n, edges);
    vector<int> group_cnt(scc_cnt);
    vector<int> out_deg(scc_cnt);
    for (int i = 0; i < n; ++i) {
        ++group_cnt[group[i]];
    }
    for (int u = 0; u < n; ++u) {
        for (int v: edges[u]) {
            if (group[u] != group[v]) {
                ++out_deg[group[u]];
            }
        }
    }
    int valid = -1;
    for (int i = 0; i < scc_cnt; ++i) {
        if (!out_deg[i]) {
            if (valid != -1) {
                cout << "0\n";
                return;
            }
            valid = i;
        }
    }
    cout << group_cnt[valid] << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}