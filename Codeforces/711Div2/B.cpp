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

int n, w;
int a[100010];

inline void work() {
    cin >> n >> w;
    int best = 0;
    unordered_map<int, int> cnt;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ++cnt[a[i]];
        best = max(best, a[i]);
    }
    int ans = 0, rest = n;
    for (; rest; ++ans) {
        int cur = best, ww = w;
        while (cur) {
            int allocate = min(cnt[cur], ww / cur);
            if (allocate) {
                cnt[cur] -= allocate;
                ww -= cur * allocate;
                rest -= allocate;
            }
            cur >>= 1;
        }
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