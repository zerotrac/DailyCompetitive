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

int n, x, y, z;
vector<vector<pair<int, int>>> edges;
bool used[500010];
LL ans;

void dfs(int u, int pv) {
    used[u] = true;
    int child = 0;
    LL most = pv;
    LL sum = pv;
    for (auto [v, sz]: edges[u]) {
        if (!used[v]) {
            dfs(v, sz);
            ++child;
            most = max(most, (LL)sz);
            sum += sz;
        }
    }
    ans += max((sum + 1) / 2, most) - pv;
}

inline void work() {
    cin >> n;
    edges.resize(n);
    for (int i = 1; i < n; ++i) {
        cin >> x >> y >> z;
        edges[x].emplace_back(y, z);
        edges[y].emplace_back(x, z);
    }

    ans = 0;
    dfs(0, 0);
    cout << ans << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}