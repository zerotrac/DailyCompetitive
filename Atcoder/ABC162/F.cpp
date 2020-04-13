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

auto pair_hash = [hash_fn = hash<int>()](const PII& o) {
    return hash_fn(o.first) ^ hash_fn(o.second);
};

unordered_map<PII, LL, decltype(pair_hash)> s(0, pair_hash);
int a[200010], premax[200010];
int n;

LL dfs(int n, int k) {
    if (!k) {
        return 0;
    }
    if (s.count({n, k})) {
        return s[{n, k}];
    }
    if (k == 1) {
        return s[{n, k}] = premax[n];
    }
    LL opt = LONG_MIN;
    for (int i = n; (k - 1) * 2 - 1 <= i - 2; --i) {
        opt = max(opt, dfs(i - 2, k - 1) + a[i]);
    }
    return s[{n, k}] = opt;
}

inline void work() {
    cin >> n;
    premax[0] = INT_MIN;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        premax[i] = max(premax[i - 1], a[i]);
    }
    cout << dfs(n, n / 2) << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}