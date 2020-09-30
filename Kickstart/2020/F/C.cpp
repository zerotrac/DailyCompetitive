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

map<PII, int> tto;
unordered_map<int, PII> ott;
unordered_map<int, vector<int>> nei;
map<tuple<LL, int, int>, int> cache;
int n, xa, ya, xb, yb, c, x, y;

int dfs(LL mask, int u, int v) {
    // cout << mask << " " << u << " " << v << "\n";
    if (cache.count({mask, u, v})) {
        return cache[{mask, u, v}];
    }
    cache[{mask, u, v}] = 0;
    bool valid = false;
    int ans = INT_MIN;
    for (int nxt: nei[u]) {
        LL m = 1LL << nxt;
        // cout << "nxt = " << u << " " << nxt << " " << m << " " << (mask & m) << "\n";
        if (!(mask & m)) {
            valid = true;
            ans = max(ans, 1 - dfs(mask | m, v, nxt));
        }
    }
    if (!valid) {
        ans = max(ans, -dfs(mask, v, u));
    }
    return cache[{mask, u, v}] = ans;
}

inline void work() {
    cin >> n >> xa >> ya >> xb >> yb >> c;
    tto.clear();
    ott.clear();
    nei.clear();
    int cnt = -1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < i * 2; ++j) {
            ++cnt;
            tto[{i, j}] = cnt;
            ott[cnt] = {i, j};
        }
    }
    cnt = -1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < i * 2; ++j) {
            ++cnt;
            if (j > 1) {
                nei[cnt].push_back(cnt - 1);
            }
            if (j < i * 2 - 1) {
                nei[cnt].push_back(cnt + 1);
            }
            if (j % 2 == 0 && i > 1) {
                nei[cnt].push_back(tto[{i - 1, j - 1}]);
            }
            if (j % 2 == 1 && i < n) {
                nei[cnt].push_back(tto[{i + 1, j + 1}]);
            }
        }
    }

    LL mask = 0;
    for (int i = 1; i <= c; ++i) {
        cin >> x >> y;
        mask |= (1LL << tto[{x, y}]);
    }
    mask |= (1LL << tto[{xa, ya}]);
    mask |= (1LL << tto[{xb, yb}]);

    cache.clear();
    cout << dfs(mask, tto[{xa, ya}], tto[{xb, yb}]) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    quickread();
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; ++_) {
        cout << "Case #" << _ << ": ";
        work();
    }
    return 0;
}