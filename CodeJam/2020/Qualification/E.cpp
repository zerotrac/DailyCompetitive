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

set<int> valid;
map<int, vector<vector<int>>> table;

int mask[10];
int g[10][10];
int ans = 0;

inline void printmat(int n) {
    int trace = 0;
    for (int i = 1; i <= n; ++i) {
        trace += g[i][i];
    }
    cout << "===" << trace << "\n";
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << g[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "===\n";
}

inline int savetrace(int n) {
    int trace = 0;
    for (int i = 1; i <= n; ++i) {
        trace += g[i][i];
    }
    valid.insert(trace);
    return trace;
}

void dfs(int n, int num, int row) {
    if (num == n + 1) {
        ++ans;
        int trace = savetrace(n);
        if (!table.count(trace)) {
            vector<vector<int>> dum(n, vector<int>(n));
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    dum[i - 1][j - 1] = g[i][j];
                }
            }
            table[trace] = move(dum);
        }
        // if (g[1][1] + g[2][2] + g[3][3] + g[4][4] == 4 && g[5][5] == 5 && g[6][6] == 6 && g[4][5] == 6 && g[4][6] == 5) {
        if (trace == n - 2 + n + n - 1 && g[n][n] == n) {
            printmat(n);
            while (1);
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

inline void work(int n) {
    memset(mask, 0, sizeof(mask));
    ans = 0;
    valid.clear();
    table.clear();
    dfs(n, 1, 1);
    cout << "n = " << n << " ans = " << ans << "\n";
    cout << "{ "; for (int num: valid) cout << num << " "; cout << "}\n";
    /*for (auto& [trace, mat]: table) {
        cout << "===trace = " << trace << "\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << mat[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "===\n";
    }*/
}

int main() {
    for (int i = 7; i <= 10; ++i) {
        work(i);
    }
    return 0;
}