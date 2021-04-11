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
int pos[100010], v[100010];
int l[100010], r[100010];
bool exist[100010];

using TIIII = tuple<int, int, int, int>;

inline void work() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> pos[i] >> v[i];
        l[i] = i - 1;
        r[i] = i + 1;
        exist[i] = true;
    }
    l[0] = 1;
    r[n + 1] = n;

    auto cmp = [](const TIIII& p, const TIIII& q) {
        LL dxp = get<0>(p), dvp = get<1>(p);
        LL dxq = get<0>(q), dvq = get<1>(q);
        return dxp * dvq > dxq * dvp;
    };

    priority_queue<TIIII, vector<TIIII>, decltype(cmp)> q(cmp);
    for (int i = 1; i < n; ++i) {
        if (v[i + 1] < v[i]) {
            q.emplace(pos[i + 1] - pos[i], v[i] - v[i + 1], i, i + 1);
        }
    }
    while (!q.empty()) {
        auto [_dx, _dv, x, y] = q.top();
        q.pop();
        if (!exist[x] || !exist[y]) {
            continue;
        }

        exist[x] = exist[y] = false;
        int nx = l[x], ny = r[y];
        if (nx != 0 && ny != n + 1 && v[ny] < v[nx]) {
            q.emplace(pos[ny] - pos[nx], v[nx] - v[ny], nx, ny);
        }
        r[nx] = ny;
        l[ny] = nx;
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += exist[i];
    }
    cout << ans << "\n";
    for (int i = 1; i <= n; ++i) {
        if (exist[i]) {
            cout << i << " ";
        }
    }
    cout << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}