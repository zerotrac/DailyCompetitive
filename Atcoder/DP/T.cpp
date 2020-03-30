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

int f[3010][3010];
int n;
string s;

inline void work() {
    cin >> n >> s;
    f[1][1] = 1;
    for (int i = 2; i <= n; ++i) {
        int prev = 0;
        if (s[i - 2] == '<') {
            for (int j = 2; j <= i; ++j) {
                prev += f[i - 1][j - 1];
                prev %= mod;
                f[i][j] = prev;
            }
        }
        else {
            for (int j = i - 1; j >= 1; --j) {
                prev += f[i - 1][j];
                prev %= mod;
                f[i][j] = prev;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += f[n][i];
        ans %= mod;
    }
    cout << ans << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}