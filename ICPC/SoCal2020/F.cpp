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

// bool used[10];
// int ans = 0;

// void test_dfs(int cnt, int i, int side) {
//     if (cnt == 9) {
//         if (side == 2) {
//             ans += 2;
//         }
//         else {
//             ans += 1;
//         }
//         return;
//     }
//     // diff side
//     for (int j = 2; j <= 8; ++j) {
//         if (!used[j]) {
//             used[j] = true;
//             test_dfs(cnt + 1, j, 1 - side);
//             used[j] = false;
//         }
//     }
//     // same side
//     if (i != 2 && !used[i - 1]) {
//         used[i - 1] = true;
//         test_dfs(cnt + 1, i - 1, side);
//         used[i - 1] = false;
//     }
//     if (i != 9 && !used[i + 1]) {
//         used[i + 1] = true;
//         test_dfs(cnt + 1, i + 1, side);
//         used[i + 1] = false;
//     }
// }

// inline void test() {
//     used[9] = true;
//     test_dfs(2, 9, 0);
//     cout << "ans = " << ans << "\n";
// }

vector<double> lengths;
bool used[10];

int n, d, s, t, fminv, fmaxv, l;

inline double dist(int i, int j) {
    return sqrt(s * s + (i - j) * (i - j) * d * d);
}

void dfs(int cnt, int i, int side, double len) {
    if (i == 1) {
        lengths.push_back(len * 2 + s + t * cnt * 2);
        return;
    }
    // diff side
    for (int j = 1; j < n; ++j) {
        if (!used[j]) {
            used[j] = true;
            dfs(cnt + 1, j, 1 - side, len + dist(i, j));
            used[j] = false;
        }
    }
    // same side
    if (i != 1 && !used[i - 1]) {
        used[i - 1] = true;
        dfs(cnt + 1, i - 1, side, len + d);
        used[i - 1] = false;
    }
    if (i != n && !used[i + 1]) {
        used[i + 1] = true;
        dfs(cnt + 1, i + 1, side, len + d);
        used[i + 1] = false;
    }
}

inline void work() {
    // n = 一边的数量
    // d = 相邻行的距离
    // s = 相邻列的距离
    // t = 空洞的长度

    cin >> n >> d >> s >> t >> fminv >> fmaxv;
    used[n] = true;
    dfs(1, n, 0, 0.);

    while (cin >> l) {
        int ans = 0;
        for (double length: lengths) {
            if (length > l) {
                continue;
            }
            if (l - 2 * fmaxv <= length && length <= l - 2 * fminv) {
                ++ans;
            }
        }
        cout << ans << "\n";
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    // test();
    work();
    return 0;
}