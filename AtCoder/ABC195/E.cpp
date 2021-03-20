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

static constexpr int MAXN = 200000;
int n;
string s, t;
int coef[MAXN + 10];
int f[MAXN + 10][7];

inline void init() {
    coef[0] = 1;
    for (int i = 1; i <= MAXN; ++i) {
        coef[i] = coef[i - 1] * 10 % 7;
    }
}

// 1: Aoki -1: Takahashi 0: n/a
int dfs(int x, int prev) {
    if (x == n) {
        return (prev != 0 ? 1 : -1);
    }
    if (f[x][prev]) {
        return f[x][prev];
    }

    int c1 = dfs(x + 1, prev);
    int c2 = dfs(x + 1, (prev + (s[x] - '0') * coef[n - x - 1]) % 7);
    if (t[x] == 'A') {
        f[x][prev] = (c1 == 1 || c2 == 1 ? 1 : -1);
    }
    else {
        f[x][prev] = (c1 == -1 || c2 == -1 ? -1 : 1);
    }
    return f[x][prev];
}

inline void work() {
    cin >> n >> s >> t;
    int ret = dfs(0, 0);
    cout << (ret == 1 ? "Aoki" : "Takahashi") << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    init();
    work();
    return 0;
}