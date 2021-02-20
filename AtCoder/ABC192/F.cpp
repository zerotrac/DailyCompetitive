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
LL x;
int a[110];

inline void work() {
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    LL ans = LLONG_MAX;

    for (int choose = n; choose >= 1; --choose) {
        int m = x % choose;
        
        // f[i][j] = 选了 i 个数，它们的和必须是 % choose = j，满足要求的和的最大值
        vector<vector<int>> f(choose + 1, vector<int>(choose, -1));
        f[0][0] = 0;
        for (int k = 1; k <= n; ++k) {
            int add = a[k] % choose;
            for (int i = min(k, choose) - 1; i >= 0; --i) {
                for (int j = 0; j < choose; ++j) {
                    if (f[i][j] != -1) {
                        f[i + 1][(j + add) % choose] = max(f[i + 1][(j + add) % choose], f[i][j] + a[k]);
                    }
                }
            }
        }
        if (f[choose][m] != -1) {
            ans = min(ans, (x - f[choose][m]) / choose);
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