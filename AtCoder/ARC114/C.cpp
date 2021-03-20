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

/*
a[i] == a[j] (i<j) and min(a[i+1],...,a[j-1]) > a[j]

d = j-i-1
enumerate num (1<=num<=m-1) & d (0<=d<=n-2)
inner: (m-num)^d
outer: m^(n-d-2)
choices: (n-d-1)

= (m-num)^d * m^(n-d-2) * (n-d-1)
*/

int n, m;
int mul[5010];

inline void init() {
    mul[0] = 1;
    for (int i = 1; i <= n - 2; ++i) {
        mul[i] = (LL)mul[i - 1] * m % mod;
    }
}

inline void work() {
    cin >> n >> m;
    init();
    
    int ans = 0;
    for (int num = 1; num <= m; ++num) {
        int term = 1;
        for (int d = 0; d <= n - 2; ++d) {
            // ans += (LL)quickmul(m - num, d) * quickmul(m, n - d - 2) % mod * (n - d - 1) % mod;
            ans += (LL)term * mul[n - d - 2] % mod * (n - d - 1) % mod;
            if (ans >= mod) {
                ans -= mod;
            }
            term = (LL)term * (m - num) % mod;
        }
    }
    int total = n;
    for (int i = 1; i <= n; ++i) {
        total = (LL)total * m % mod;
    }
    // ans = (LL)quickmul(m, n) * n % mod - ans;
    ans = total - ans;
    if (ans < 0) {
        ans += mod;
    }
    cout << ans << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}