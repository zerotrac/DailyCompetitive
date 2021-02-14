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

int n;
int a[200010];
// f[..][0] = copy, f[..][1] = prefix
int f[200010][2];

inline void work() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    LL sum = 0;
    int ptotal = 0;
    f[0][0] = 1;
    f[0][1] = 0;
    unordered_map<LL, int> mp;
    for (int i = 1; i <= n; ++i) {
        // copy
        f[i][0] = f[i - 1][0] + f[i - 1][1];
        if (f[i][0] >= mod) {
            f[i][0] -= mod;
        }
        // prefix
        f[i][1] = 0;
        // first p
        if (sum != 0) {
            ++f[i][1];
        }
        // non-first p
        f[i][1] += ptotal;
        if (f[i][1] >= mod) {
            f[i][1] -= mod;
        }
        if (mp.count(sum)) {
            f[i][1] -= mp[sum];
            if (f[i][1] < 0) {
                f[i][1] += mod;
            }
        }
        mp[sum] += f[i][1];
        if (mp[sum] >= mod) {
            mp[sum] -= mod;
        }
        ptotal += f[i][1];
        if (ptotal >= mod) {
            ptotal -= mod;
        }
        sum += a[i];
    }
    cout << (f[n][0] + f[n][1]) % mod << "\n";
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