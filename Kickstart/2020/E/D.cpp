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

const LL THRESHOLD = 1000000000000LL;
int g[310][310];
LL best[310][310];
int rcp[310][5]; // [0] # [1..] recipe [-1] target
// n 300 m 500 s 300 r 300
int n, m, s, r, x, y;

bool used[310];
int store[310];

inline void work() {
    cin >> n >> m >> s >> r;
    memset(g, -1, sizeof(g));
    for (int i = 1; i <= n; ++i) {
        g[i][i] = 0;
    }

    vector<vector<int>> edges(n + 1);
    for (int i = 1; i <= m; ++i) {
        cin >> x >> y;
        g[x][y] = g[y][x] = 1;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    // for (int k = 1; k <= n; ++k) {
    //     for (int i = 1; i <= n; ++i) {
    //         for (int j = 1; j <= n; ++j) {
    //             if (g[i][k] != -1 && g[k][j] != -1) {
    //                 g[i][j] = (g[i][j] == -1 ? g[i][k] + g[k][j] : min(g[i][j], g[i][k] + g[k][j]));
    //             }
    //         }
    //     }
    // }
    memset(best, -1, sizeof(best));
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        for (int j = 1; j <= x; ++j) {
            cin >> y;
            best[i][y] = 0;
        }
    }
    for (int i = 1; i <= r; ++i) {
        cin >> rcp[i][0];
        for (int j = 1; j <= rcp[i][0]; ++j) {
            cin >> rcp[i][j];
        }
        cin >> rcp[i][rcp[i][0] + 1];
    }

    while (true) {
        bool modified = false;
        // transport
        for (int i = 1; i <= s; ++i) {
            // cout << "i = " << i << "\n";
            int pos = 0;
            for (int j = 1; j <= n; ++j) {
                if (best[j][i] != -1) {
                    store[++pos] = j;
                }
            }
            if (!pos) {
                continue;
            }
            sort(store + 1, store + pos + 1, [&](int u, int v) {
                return best[u][i] < best[v][i];
            });

            memset(used, false, sizeof(used));
            deque<int> q;
            q.push_back(store[1]);
            used[store[1]] = true;
            int ppos = 2;
            while (!q.empty() || ppos <= pos) {
                while (ppos <= pos && (q.empty() || best[store[ppos]][i] <= best[q.front()][i])) {
                    if (!used[store[ppos]]) {
                        q.push_front(store[ppos]);
                        used[store[ppos]] = true;
                    }
                    ++ppos;
                }
                int u = q.front();
                q.pop_front();
                // cout << "u = " << u << "\n";
                for (int v: edges[u]) {
                    if (!used[v]) {
                        if (best[v][i] == -1 || best[u][i] + 1 < best[v][i]) {
                            // cout << "expand v = " << v << "\n";
                            best[v][i] = best[u][i] + 1;
                            if (best[v][i] >= THRESHOLD) {
                                best[v][i] = -1;
                            }
                            else {
                                q.push_back(v);
                                modified = true;
                            }
                            used[v] = true;
                        }
                    }
                }
            }
        }
        // recipe
        for (int i = 1; i <= n; ++i) {
            // for (int j = 1; j <= n; ++j) {
            //     for (int k = 1; k <= s; ++k) {
            //         if (best[j][k] != -1 && (best[i][k] == -1 || best[j][k] + g[i][j] < best[i][k])) {
            //             best[i][k] = best[j][k] + g[i][j];
            //             modified = true;
            //         }
            //     }
            // }
            for (int j = 1; j <= r; ++j) {
                bool valid = true;
                LL cost = 0;
                for (int k = 1; k <= rcp[j][0]; ++k) {
                    if (best[i][rcp[j][k]] == -1) {
                        valid = false;
                        break;
                    }
                    cost += best[i][rcp[j][k]];
                }
                if (valid && cost <= THRESHOLD) {
                    int target = rcp[j][rcp[j][0] + 1];
                    if (best[i][target] == -1 || cost < best[i][target]) {
                        best[i][target] = cost;
                        modified = true;
                    }
                }
            }
        }
        if (!modified) {
            break;
        }
    }

    LL ans = -1;
    for (int i = 1; i <= n; ++i) {
        if (ans == -1 || best[i][1] < ans) {
            ans = best[i][1];
        }
    }
    cout << ans << "\n";
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