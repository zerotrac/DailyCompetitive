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
const int mod = 1e9 + 7;
// const int mod = 998244353;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int a[1010][1010], f[1010][1010];
string st;
int h, w;

inline void work() {
    cin >> h >> w;
    for (int i = 1; i <= h; ++i) {
        cin >> st;
        for (int j = 1; j <= w; ++j) {
            a[i][j] = (st[j - 1] == '.');
        }
    }
    for (int i = 2; i <= h; ++i) {
        if (!a[i][1]) {
            break;
        }
        f[i][1] = 1;
    }
    for (int j = 2; j <= w; ++j) {
        if (!a[1][j]) {
            break;
        }
        f[1][j] = 1;
    }
    for (int i = 2; i <= h; ++i) {
        for (int j = 2; j <= w; ++j) {
            if (a[i][j]) {
                f[i][j] = (f[i][j - 1] + f[i - 1][j]) % mod;
            }
        }
    }
    cout << f[h][w] << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}