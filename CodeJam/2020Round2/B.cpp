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

int a[2000], b[2000];
int g[200][200], h[200][200];
int stats[200], dist[200];
bool pending[200], used[200];
int n, m, x, y;

inline void work() {
    cin >> n >> m;
    for (int i = 2; i <= n; ++i) {
        cin >> stats[i];
    }
    memset(g, 0, sizeof(g));
    memset(h, 0, sizeof(h));
    for (int i = 1; i <= m; ++i) {
        cin >> x >> y;
        g[x][y] = g[y][x] = 1;
        a[i] = x;
        b[i] = y;
    }

    memset(pending, false, sizeof(pending));
    memset(used, false, sizeof(used));
    used[1] = true;
    for (int i = 2; i <= n; ++i) {
        if (g[1][i]) {
            pending[i] = true;
        }
    }

    dist[1] = 0;
    for (int i = 2; i <= n; ++i) {
        dist[i] = INT_MAX;
    }
    int last_dis = 0, last_ts = 0;
    for (int timestamp = 1; timestamp < n; ++timestamp) {
        bool judge = false;
        for (int i = 2; i <= n; ++i) {
            if (pending[i] && stats[i] < 0 && -stats[i] <= timestamp) {
                int prev = -1;
                for (int j = 1; j <= n; ++j) {
                    if (used[j] && g[j][i] && (prev == -1 || dist[j] < dist[prev])) {
                        prev = j;
                    }
                }
                dist[i] = max(dist[prev] + 1, (-stats[i] == last_ts ? last_dis : last_dis + 1));
                h[prev][i] = h[i][prev] = dist[i] - dist[prev];
                last_dis = dist[i];
                last_ts = -stats[i];
                pending[i] = false;
                used[i] = true;
                for (int j = 2; j <= n; ++j) {
                    if (!used[j] && g[i][j]) {
                        pending[j] = true;
                    }
                }
                judge = true;
                break;
            }
        }
        if (!judge) {
            int i = -1;
            for (int i0 = 2; i0 <= n; ++i0) {
                if (pending[i0] && stats[i0] > 0 && (i == -1 || stats[i0] < stats[i])) {
                    i = i0;
                }
            }
            int prev = -1;
            for (int j = 1; j <= n; ++j) {
                if (used[j] && g[j][i] && (prev == -1 || dist[j] < dist[prev])) {
                    prev = j;
                }
            }
            dist[i] = stats[i];
            h[prev][i] = h[i][prev] = dist[i] - dist[prev];
            last_dis = dist[i];
            last_ts = timestamp;
            pending[i] = false;
            used[i] = true;
            for (int j = 2; j <= n; ++j) {
                if (!used[j] && g[i][j]) {
                    pending[j] = true;
                }
            }
        }
    }

    for (int i = 1; i <= m; ++i) {
        if (h[a[i]][b[i]] > 0) {
            cout << h[a[i]][b[i]] << " ";
        }
        else {
            cout << 1000000 << " ";
        }
    }
    cout << "\n";
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