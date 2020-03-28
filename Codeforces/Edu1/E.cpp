#include <iostream>
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

int f[31][31][51];
int t, m, n, k;

inline void work() {
    for (int i = 1; i <= 30; ++i) {
        for (int j = 1; j <= 30; ++j) {
            for (int k = 1, kmax = min(i * j - 1, 50); k <= kmax; ++k) {
                f[i][j][k] = INT_MAX;
                for (int kl = 0; kl <= k; ++kl) {
                    int kr = k - kl;
                    // horizontally
                    for (int il = 1; il < i; ++il) {
                        int ir = i - il;
                        if (il * j >= kl && ir * j >= kr) {
                            f[i][j][k] = min(f[i][j][k], f[il][j][kl] + f[ir][j][kr] + j * j);
                        }
                    }
                    // vertically
                    for (int jl = 1; jl < j; ++jl) {
                        int jr = j - jl;
                        if (i * jl >= kl && i * jr >= kr) {
                            f[i][j][k] = min(f[i][j][k], f[i][jl][kl] + f[i][jr][kr] + i * i);
                        }
                    }
                }
            }
            if (i * j <= 50) {
                f[i][j][i * j] = 0;
            }
        }
    }
    cin >> t;
    while (t--) {
        cin >> m >> n >> k;
        cout << f[m][n][k] << "\n";
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}