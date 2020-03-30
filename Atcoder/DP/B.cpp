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

int f[100010], h[100010];
int n, k;

inline void work() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
    }
    for (int i = 2; i <= n; ++i) {
        f[i] = INT_MAX;
        for (int j = i - 1, jm = max(i - k, 1); j >= jm; --j) {
            f[i] = min(f[i], f[j] + abs(h[i] - h[j]));
        }
    }
    cout << f[n] << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}