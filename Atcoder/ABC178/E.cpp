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
LL x, y;

inline void work() {
    cin >> n;
    cin >> x >> y;
    LL a = x + y;
    LL b = x - y;
    LL c = -x + y;
    LL d = -x - y;
    LL ans = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> x >> y;
        ans = max({ans, a - x - y, b - x + y, c + x - y, d + x + y});
        a = max(a, x + y);
        b = max(b, x - y);
        c = max(c, -x + y);
        d = max(d, -x - y);
    }
    cout << ans << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}