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

int f[2][10010];
int n, k;

inline void work() {
    cin >> n >> k;

    memset(f, 0, sizeof(f));
    f[0][0] = k;
    int pos = 0;
    for (int i = 0; i < n - 1; ++i) {
        // i -> i+1
        int x = i & 1;
        int y = x ^ 1;
        if (!(f[x][pos] & 1)) {
            ++pos;
        }
        memset(f[y], 0, sizeof(f[y]));
        for (int j = 0; j <= i; ++j) {
            f[y][j] += (f[x][j] + 1) / 2;
            f[y][j + 1] += f[x][j] / 2;
        }
        // cout << "pos = " << pos << "\n";
        // for (int j = 0; j <= i + 1; ++j) cout << f[y][j] << " "; cout << "\n";
    }
    cout << pos << "\n";
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