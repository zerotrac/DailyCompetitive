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
const int mod = 1e9 + 7;
// const int mod = 998244353;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int f[100010];
int n, k, x;

inline void work() {
    cin >> n >> k;
    f[0] = 1;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        sum = min(sum + x, k);
        // f[i][j] = f[i - 1][j] + f[i - 1][j - 1] + ... + f[i - 1][j - x]
        int prev = 0;
        for (int j = sum; j >= max(0, sum - x); --j) {
            prev += f[j];
            prev %= mod;
        }
        for (int j = sum; j >= 0; --j) {
            int last_fj = f[j];
            f[j] = prev;
            if (j - x - 1 >= 0) {
                prev += f[j - x - 1];
            }
            prev -= last_fj;
            prev = (prev % mod + mod) % mod;
        }
    }
    cout << f[k] << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}