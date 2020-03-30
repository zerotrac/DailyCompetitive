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
// const int mod = 1e9 + 7;
// const int mod = 998244353;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

LL f[100010];
int n, w, x, y;

inline void work() {
    memset(f, -1, sizeof(f));
    f[0] = 0;
    
    cin >> n >> w;
    int totv = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        totv += y;
        for (int j = totv; j >= y; --j) {
            if (f[j - y] != -1) {
                f[j] = min(f[j] == -1 ? LONG_MAX : f[j], f[j - y] + x);
            }
        }
    }
    int ans = 0;
    for (int i = totv; i > 0; --i) {
        if (f[i] != -1 && f[i] <= w) {
            ans = i;
            break;
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