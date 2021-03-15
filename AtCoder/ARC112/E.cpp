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
const int mod = 998244353;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

static constexpr int MAXN = 3000;
int n, m;
int a[MAXN + 10];
int comb[MAXN + 10][MAXN + 10], f[MAXN + 10][MAXN + 10];

inline void init() {
    comb[0][0] = 1;
    for (int i = 1; i <= MAXN; ++i) {
        comb[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
            if (comb[i][j] >= mod) {
                comb[i][j] -= mod;
            }
        }
    }
    memset(f, -1, sizeof(f));
}

// x valid, y operations
int dfs(int x, int y) {
    if (x > y) {
        return 0;
    }
    if (!x && y) {
        return 0;
    }
    if (!x && !y) {
        return 1;
    }
    if (f[x][y] != -1) {
        return f[x][y];
    }
    
    f[x][y] = (LL)dfs(x, y - 1) * x * 2 % mod + dfs(x - 1, y - 1);
    if (f[x][y] >= mod) {
        f[x][y] -= mod;
    }
    return f[x][y];
}

inline void work() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            if (i != j && a[j - 1] > a[j]) {
                break;
            }
            int change = (i - 1) + (n - j);
            if (change > m) {
                continue;
            }
            ans += (LL)dfs(change, m) * comb[change][i - 1] % mod;
            if (ans >= mod) {
                ans -= mod;
            }
        }
    }
    if (n <= m) {
        for (int i = 0; i <= n; ++i) {
            ans += (LL)dfs(n, m) * comb[n][i] % mod;
            if (ans >= mod) {
                ans -= mod;
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    init();
    quickread();
    work();
    return 0;
}