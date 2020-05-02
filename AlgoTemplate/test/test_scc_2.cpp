// https://wcipeg.com/problem/ioi9613

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
int n, x;

inline void work() {
    cin >> n;
    edges.resize(n);
    for (int i = 0; i < n; ++i) {
        while (true) {
            cin >> x;
            if (x == 0) {
                break;
            }
            edges[i].push_back(x - 1);
        }
    }
    // auto [scc_cnt, group] = TarjanSCC::getSCC(n, edges);
    auto dum = TarjanSCC::getSCC(n, edges);
    int scc_cnt = dum.first;
    vector<int> group = dum.second;
    vector<int> indeg(n), outdeg(n);
    for (int u = 0; u < n; ++u) {
        for (int v: edges[u]) {
            if (group[u] != group[v]) {
                ++indeg[group[v]];
                ++outdeg[group[u]];
            }
        }
    }
    int inzero = 0, outzero = 0;
    for (int i = 0; i < scc_cnt; ++i) {
        if (!indeg[i]) {
            ++inzero;
        }
        if (!outdeg[i]) {
            ++outzero;
        }
    }
    cout << inzero << "\n";
    cout << (scc_cnt == 1 ? 0 : max(inzero, outzero)) << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}