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

int f[10000][100][2];
string k;
int d;

int dp(int pos, int stats, int bound) {
    if (pos == k.size()) {
        return stats == 0;
    }
    if (f[pos][stats][bound] != -1) {
        return f[pos][stats][bound];
    }
    f[pos][stats][bound] = 0;
    for (int i = 0, im = (bound ? k[pos] - 48 : 9); i <= im; ++i) {
        f[pos][stats][bound] += dp(pos + 1, (stats + i) % d, bound && (i == im));
        f[pos][stats][bound] %= mod;
    }
    return f[pos][stats][bound];
}

inline void work() {
    cin >> k >> d;
    memset(f, -1, sizeof(f));
    cout << (dp(0, 0, 1) + mod - 1) % mod << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}