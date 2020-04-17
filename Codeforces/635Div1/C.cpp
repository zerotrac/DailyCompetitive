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
const int mod = 998244353;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int f[3010][3010];
int l[3010][3010], r[3010][3010];
int mul2[3010];
string S, T;
int m, n;

inline void work() {
    cin >> S;
    cin >> T;
    m = S.size();
    n = T.size();

    mul2[0] = 1;
    for (int i = 1; i <= m; ++i) {
        mul2[i] = mul2[i - 1] * 2 % mod;
    }

    int ans = 0;
    l[m + 1][0] = 1;
    for (int i = m; i >= 1; --i) {
        l[i][0] = l[i + 1][0] + 1;
        for (int j = 1; j <= n; ++j) {
            if (m - i + 1 >= j) {
                if (j != n) {
                    l[i][j] = l[i + 1][j];
                }
                if (S[i - 1] == T[j - 1]) {
                    l[i][j] += l[i + 1][j - 1];
                    l[i][j] %= mod;
                    if (j == n && i != 1) {
                        ans += (LL)l[i][j] * mul2[i - 1] % mod;
                        ans %= mod;
                    }
                }
            }
        }
    }

    memset(f, -1, sizeof(f));
    for (int i = n; i >= 1; --i) {
        for (int j = i; j <= n; ++j) {
            int pos = j - i;
            if (i == j) {
                if (S[0] == T[i - 1]) {
                    f[i][j] = 2;
                }
            }
            else {
                if ((f[i + 1][j] != -1 && T[i - 1] == S[pos]) || (f[i][j - 1] != -1 && T[j - 1] == S[pos])) {
                    f[i][j] = 0;
                    if (f[i + 1][j] != -1 && T[i - 1] == S[pos]) {
                        f[i][j] += f[i + 1][j];
                    }
                    if (f[i][j - 1] != -1 && T[j - 1] == S[pos]) {
                        f[i][j] += f[i][j - 1];
                    }
                    f[i][j] %= mod;
                }
            }
        }
        if (f[i][n] != -1) {
            if (i == 1) {
                ans += (LL)f[i][n] * l[n - i + 2][i - 1] % mod;
            }
            else {
                ans += (LL)f[i][n] * l[n - i + 3][i - 1] % mod;
            }
            ans %= mod;
        }
    }
    cout << ans << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}
