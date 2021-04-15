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

int n, c;
int a[200010], b[200010];

inline void work() {
    cin >> n >> c;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
        cin >> b[i];
    }
    int ans = (c + a[1] - 1) / a[1];
    int ts = 0;
    int money = 0;
    for (int i = 2; i <= n; ++i) {
        int t = (b[i - 1] - money + a[i - 1] - 1) / (a[i - 1]);
        if (ts + t + 1 > ans) {
            break;
        }
        ts += t + 1;
        money = money + t * a[i - 1] - b[i - 1];
        int t2 = (c - money + a[i] - 1) / a[i];
        ans = min(ans, ts + t2);
    }
    cout << ans << "\n";
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