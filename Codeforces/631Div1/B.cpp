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
// const int mod = 1e9 + 7;
// const int mod = 998244353;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int T, d, m;

inline void work() {
    cin >> d >> m;
    int ans = 1;
    for (int i = 0; i <= 29; ++i) {
        if ((1 << (i + 1)) - 1 < d) {
            ans = (LL)ans * ((1 << i) + 1) % m;
        }
        else {
            ans = (LL)ans * (d - (1 << i) + 2) % m;
            break;
        }
    }
    ans = (ans - 1 + m) % m;
    cout << ans << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    cin >> T;
    while (T--) {
        work();
    }
    return 0;
}