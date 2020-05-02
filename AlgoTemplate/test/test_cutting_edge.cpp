// https://www.luogu.com.cn/problem/P1656

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
        edges[y - 1].push_back(x - 1);
    }
    vector<PII> cutting_edges = TarjanSCC::getCuttingEdge(n, edges);
    sort(cutting_edges.begin(), cutting_edges.end());
    for (const PII& o: cutting_edges) {
        cout << o.first + 1 << " " << o.second + 1 << "\n";
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}