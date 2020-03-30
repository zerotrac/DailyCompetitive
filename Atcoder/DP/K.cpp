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

int a[100], f[100010];
int n, k;

int dfs(int x) {
    if (f[x] != -1) {
        return f[x];
    }
    f[x] = 1;
    for (int i = 0; i < n; ++i) {
        if (x >= a[i]) {
            f[x] &= dfs(x - a[i]);
        }
    }
    return f[x] = 1 - f[x];
}

inline void work() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int bottom = *min_element(a, a + n);
    memset(f, -1, sizeof(f));
    // 0-lose 1-win
    for (int i = 0; i < bottom; ++i) {
        f[i] = 0;
    }
    cout << (dfs(k) ? "First" : "Second") << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}