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
const int mod = 1e9 + 7;
// const int mod = 998244353;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int n, k;
int f[1010][1010][2];

int dfs(int dec, int facing, int dir) {
    if (dec == 1) {
        return 1;
    }
    if (!facing) {
        return 1;
    }
    if (f[dec][facing][dir] != -1) {
        return f[dec][facing][dir];
    }

    return f[dec][facing][dir] = (dfs(dec, facing - 1, dir) + dfs(dec - 1, n - facing, dir ^ 1)) % mod;
}

inline void work() {
    cin >> n >> k;
    for (int i = 1; i <= k; ++i) {
        for (int j = 0; j <= n; ++j) {
            f[i][j][0] = f[i][j][1] = -1;
        }
    }
    cout << dfs(k, n, 1) << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    int T;
    cin >> T;
    while (T--) {
        work();
    }
    return 0;
}