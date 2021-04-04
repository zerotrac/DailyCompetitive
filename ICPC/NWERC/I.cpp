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

int n;
int d[410];
int e[3][410], ts[3][410][410], te[3][410][410];
bool good[3][3][410][410];

inline void init(int u) {
    for (int i = 1; i <= n; ++i) {
        int t = 0;
        for (int j = i, cnt = 1; cnt <= n; ++cnt) {
            ts[u][i][j] = t;
            te[u][i][j] = t + e[u][j];
            t += e[u][j] + d[j];
            ++j;
            if (j == n + 1) {
                j = 1;
            }
        }
    }
}

inline void check(int u, int v) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) {
                continue;
            }
            bool flag = true;
            for (int k = 1; k <= n; ++k) {
                int l1 = ts[u][i][k], r1 = te[u][i][k];
                int l2 = ts[v][j][k], r2 = te[v][j][k];
                if (l1 >= r2 || l2 >= r1) {

                }
                else {
                    flag = false;
                    break;
                }
            }
            good[u][v][i][j] = flag;
        }
    }
}

inline void work() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> d[i];
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> e[i][j];
        }
    }

    init(0);
    init(1);
    init(2);

    check(0, 1);
    check(0, 2);
    check(1, 2);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= n; ++k) {
                if (good[0][1][i][j] && good[0][2][i][k] && good[1][2][j][k]) {
                    cout << i << " " << j << " " << k << "\n";
                    return;
                }
            }
        }
    }
    cout << "impossible\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}