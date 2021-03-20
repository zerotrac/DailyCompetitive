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

int h, w, a, b;
int ans;
int g[20][20];

pair<int, int> get_next(int i, int j) {
    return j == w ? pair{i + 1, 1} : pair{i, j + 1};
}

void dfs(int i, int j, int rest_a) {
    if (!rest_a) {
        ++ans;
        return;
    }
    if (i == h + 1) {
        return;
    }
    
    auto [ni, nj] = get_next(i, j);
    dfs(ni, nj, rest_a);
    if (!g[i][j] && !g[i][j + 1]) {
        g[i][j] = g[i][j + 1] = 1;
        dfs(ni, nj, rest_a - 1);
        g[i][j] = g[i][j + 1] = 0;
    }
    if (!g[i][j] && !g[i + 1][j]) {
        g[i][j] = g[i + 1][j] = 1;
        dfs(ni, nj, rest_a - 1);
        g[i][j] = g[i + 1][j] = 0;
    }
}

inline void work() {
    cin >> h >> w >> a >> b;
    for (int i = 0; i <= h + 1; ++i) {
        for (int j = 0; j <= w + 1; ++j) {
            g[i][j] = 1;
        }
    }
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            g[i][j] = 0;
        }
    }
    dfs(1, 1, a);
    cout << ans << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}