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
const int mod = 998244353;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

unordered_map<LL, int> memo;
LL n;
int t;

int dfs(LL n, int t) {
    if (memo.count(n)) {
        return memo[n];
    }
    if (!n) {
        return memo[n] = 1;
    }
    int ret = 0;
    for (int i = 0; i <= t && i <= n; ++i) {
        if ((n - i) % 2 == 0) {
            ret += dfs((n - i) >> 1, t);
            if (ret >= mod) {
                ret -= mod;
            }
        }
    }
    return memo[n] = ret;
}

inline void work() {
    cin >> n >> t;
    int ans = dfs(n, t);
    cout << ans << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}