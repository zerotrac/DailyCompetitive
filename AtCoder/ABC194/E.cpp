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

int n, m, x;
int last[1500010];

inline void work() {
    memset(last, 0, sizeof(last));
    cin >> n >> m;
    int ans = n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        if (i - last[x] > m) {
            ans = min(ans, x);
        }
        last[x] = i;
    }
    for (int i = 0; i < n; ++i) {
        if (n + 1 - last[i] > m) {
            ans = min(ans, i);
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