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

int n, k;
int g[6][6], h[6][6];
int len[6];

string st;

int ans;

inline bool check() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (g[i][j] == 1 && h[i][j] != 1) {
                return false;
            }
            if (g[i][j] == -1 && h[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

void dfs(int x) {
    if (x == k + 1) {
        if (check()) {
            ++ans;
        }
        return;
    }

    // place len[x]

    // hor
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j + len[x] - 1 <= n; ++j) {
            bool good = true;
            for (int k = j; k <= j + len[x] - 1; ++k) {
                if (h[i][k] != 0) {
                    good = false;
                    break;
                }
            }
            if (good) {
                for (int k = j; k <= j + len[x] - 1; ++k) {
                    h[i][k] = 1;
                }
                dfs(x + 1);
                for (int k = j; k <= j + len[x] - 1; ++k) {
                    h[i][k] = 0;
                }
            }
        }
    }

    // ver
    if (len[x] == 1) {
        return;
    }

    for (int i = 1; i + len[x] - 1 <= n; ++i) {
        for (int j = 1; j  <= n; ++j) {
            bool good = true;
            for (int k = i; k <= i + len[x] - 1; ++k) {
                if (h[k][j] != 0) {
                    good = false;
                    break;
                }
            }
            if (good) {
                for (int k = i; k <= i + len[x] - 1; ++k) {
                    h[k][j] = 1;
                }
                dfs(x + 1);
                for (int k = i; k <= i + len[x] - 1; ++k) {
                    h[k][j] = 0;
                }
            }
        }
    }
}

inline void work() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> st;
        for (int j = 1; j <= n; ++j) {
            if (st[j - 1] == 'X') {
                g[i][j] = -1;
            }
            else if (st[j - 1] == 'O') {
                g[i][j] = 1;
            }
        }
    }

    for (int i = 1; i <= k; ++i) {
        cin >> len[i];
    }

    dfs(1);

    cout << ans << endl;
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}