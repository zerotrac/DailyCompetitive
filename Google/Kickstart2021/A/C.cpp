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

int m, n;
int a[310][310], b[310][310];

using S = tuple<int, int, int>;

inline void work() {
    cin >> m >> n;
    priority_queue<S> q;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
            b[i][j] = -1;
            q.emplace(a[i][j], i, j);
        }
    }

    while (!q.empty()) {
        auto [h, x, y] = q.top();
        q.pop();
        if (x < 1 || x > m || y < 1 || y > n || b[x][y] != -1) {
            continue;
        }
        b[x][y] = h;
        q.emplace(h - 1, x - 1, y);
        q.emplace(h - 1, x + 1, y);
        q.emplace(h - 1, x, y - 1);
        q.emplace(h - 1, x, y + 1);
    }
    
    LL ans = 0;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            ans += b[i][j] - a[i][j];
        }
    }
    cout << ans << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; ++_) {
        cout << "Case #" << _ << ": ";
        work();
    }
    return 0;
}