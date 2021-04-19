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

// f[i][cnt][place] = we use {i} nodes, results in {cnt} pairs, there are {place} positions to put the smaller numbers
// f[i][cnt][place] -> f[i + i0][cnt + i0 * (i0 - 1) / 2][i0 - (place + 2)] * C(i0 - 1, place + 1)
LL f[62][910][62];
LL c[62][62];

inline void init() {
    c[0][0] = 1;
    for (int i = 1; i <= 61; ++i) {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }
}

inline void work() {
    cin >> n >> k;
    f[0][0][0] = 1;
    for (int i = 1; i <= n * 2 + 1 && i * (i - 1) / 2 <= k; ++i) {
        f[i][i * (i - 1) / 2][i - 1] = 1;
    }
    for (int i = 0; i <= n * 2 + 1; ++i) {
        for (int cnt = 0; cnt <= i * (i - 1) / 2 && cnt <= k; ++cnt) {
            for (int place = 0; place < i; ++place) {
                if (f[i][cnt][place] == 0) {
                    continue;
                }
                for (int i0 = place + 2; i + i0 <= n * 2 + 1 && cnt + i0 * (i0 - 1) / 2 <= k; ++i0) {
                    f[i + i0][cnt + i0 * (i0 - 1) / 2][i0 - (place + 2)] += f[i][cnt][place] * c[i0 - 1][place + 1];
                }
            }
        }
    }

    LL ans = 0;
    for (int i = 2; i <= n * 2 + 1; ++i) {
        for (int cnt = 1; cnt <= i * (i - 1) / 2 && cnt <= k; ++cnt) {
            for (int place = 1; place < i; ++place) {
                ans += f[i][cnt][place] * f[n * 2 + 1 - i][k - cnt][place - 1];
            }
        }
    }
    ans += f[n * 2 + 1][k][0];
    cout << ans << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    init();
    work();
    return 0;
}