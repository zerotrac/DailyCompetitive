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

int a[16][16];
LL value[1 << 16], f[1 << 16];
int n;

inline void work() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i < (1 << n); ++i) {
        if (__builtin_popcount(i) > 1) {
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    value[i] = value[i - (1 << j)];
                    for (int k = j + 1; k < n; ++k) {
                        if (i & (1 << k)) {
                            value[i] += a[j][k];
                        }
                    }
                    break;
                }
            }
        }
    }
    for (int i = 1; i < (1 << n); ++i) {
        if (__builtin_popcount(i) > 1) {
            for (int j = i; j; j = (j - 1) & i) {
                f[i] = max(f[i], f[i ^ j] + value[j]);
            }
        }
    }
    LL ans = *max_element(f, f + (1 << n));
    cout << ans << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}