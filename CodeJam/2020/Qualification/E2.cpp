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

map<int, vector<vector<int>>> table;

int mask[10];
int g[10][10];

inline int savetrace(int n) {
    int trace = 0;
    for (int i = 1; i <= n; ++i) {
        trace += g[i][i];
    }
    return trace;
}

void dfs(int n, int num, int row) {
    if (num == n + 1) {
        int trace = savetrace(n);
        if (!table.count(trace)) {
            vector<vector<int>> dum(n, vector<int>(n));
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    dum[i - 1][j - 1] = g[i][j];
                }
            }
            table[n * 100 + trace] = move(dum);
        }
        return;
    }

    for (int col = 1; col <= n; ++col) {
        if (!g[row][col] && !(mask[num] & (1 << col))) {
            mask[num] ^= (1 << col);
            g[row][col] = num;
            if (row == n) {
                dfs(n, num + 1, 1);
            }
            else {
                dfs(n, num, row + 1);
            }
            mask[num] ^= (1 << col);
            g[row][col] = 0;
        }
    }
}

inline void precalc(int n) {
    dfs(n, 1, 1);
}

inline void work() {
    int n, k;
    cin >> n >> k;
    if (table.count(n * 100 + k)) {
        cout << "POSSIBLE\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << table[n * 100 + k][i][j];
                cout << (j == n - 1 ? "\n" : " ");
            }
        }
    }
    else {
        cout << "IMPOSSIBLE\n";
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    for (int i = 2; i <= 5; ++i) {
        precalc(i);
    }
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; ++_) {
        cout << "Case #" << _ << ": ";
        work();
    }
    return 0;
}