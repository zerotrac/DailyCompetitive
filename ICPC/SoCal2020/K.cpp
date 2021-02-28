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

int m, n, k, d, xx1, yy1, xx2, yy2, t, p;
int xx3, yy3, xx4, yy4, xx5, yy5, xx6, yy6, x, y;
static constexpr int base = 16;
static constexpr int lanemul = 4;
string s;

unordered_map<int, int> dist;
unordered_map<int, vector<int>> laneleft, lanestraight, laneright;

inline int encrypt(int a, int b, int c, int d) {
    return ((a * base + b) * base + c) * base + d;
}

inline int encrypt(int a, int b, int c, int d, int e) {
    return encrypt(a, b, c, d) * lanemul + e;
}

inline tuple<int, int, int, int> decrypt(int x) {
    int d = x % base;
    x /= base;
    int c = x % base;
    x /= base;
    int b = x % base;
    x /= base;
    return {x, b, c, d};
}

inline tuple<int, int, int, int, int> decrypt_2(int x) {
    int e = x % lanemul;
    x /= lanemul;
    auto [a, b, c, d] = decrypt(x);
    return {a, b, c, d, e};
}

inline tuple<int, int, int, int> getleft(int a, int b, int c, int d) {
    int dx = c - a, dy = d - b;
    tie(dx, dy) = make_tuple(-dy, dx);
    return {c, d, c + dx, d + dy};
}

inline tuple<int, int, int, int> getstraight(int a, int b, int c, int d) {
    return {c, d, c * 2 - a, d * 2 - b};
}

inline tuple<int, int, int, int> getright(int a, int b, int c, int d) {
    int dx = c - a, dy = d - b;
    tie(dx, dy) = make_tuple(dy, -dx);
    return {c, d, c + dx, d + dy};
}

// edges: x -> (y, dist, turn?, change lane?)
unordered_map<int, vector<tuple<int, int, int, int>>> edges;

inline void buildgraph() {
    for (const auto [idx, dcnt]: dist) {
        auto [xx1, yy1, xx2, yy2] = decrypt(idx);
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < k; ++j) {
                if (i != j && abs(i - j) == 1) {
                    edges[encrypt(xx1, yy1, xx2, yy2, i)].push_back({encrypt(xx1, yy1, xx2, yy2, j), 0, 0, 1});
                }
            }
        }

        int xx3, yy3, xx4, yy4, idy;
        tie(xx3, yy3, xx4, yy4) = getleft(xx1, yy1, xx2, yy2);
        idy = encrypt(xx3, yy3, xx4, yy4);
        if (0 <= xx3 && xx3 < m && 0 <= xx4 && xx4 < m && 0 <= yy3 && yy3 < n && 0 <= yy4 && yy4 < n && dist.count(idy)) {
            if (!laneleft[idx].empty()) {
                for (int i = 0, j = -1; i < k; ++i) {
                    if (j + 1 < laneleft[idx].size()) {
                        ++j;
                    }
                    edges[encrypt(xx1, yy1, xx2, yy2, laneleft[idx][j])].push_back({encrypt(xx3, yy3, xx4, yy4, i), (dcnt + dist[idy]) / 2, 1, 0});
                }
            }
        }

        tie(xx3, yy3, xx4, yy4) = getstraight(xx1, yy1, xx2, yy2);
        idy = encrypt(xx3, yy3, xx4, yy4);
        if (0 <= xx3 && xx3 < m && 0 <= xx4 && xx4 < m && 0 <= yy3 && yy3 < n && 0 <= yy4 && yy4 < n && dist.count(idy)) {
            if (!lanestraight[idx].empty()) {
                for (int i = 0, j = -1; i < k; ++i) {
                    if (j + 1 < lanestraight[idx].size()) {
                        ++j;
                    }
                    edges[encrypt(xx1, yy1, xx2, yy2, lanestraight[idx][j])].push_back({encrypt(xx3, yy3, xx4, yy4, i), (dcnt + dist[idy]) / 2, 0, 0});
                }
            }
        }

        tie(xx3, yy3, xx4, yy4) = getright(xx1, yy1, xx2, yy2);
        idy = encrypt(xx3, yy3, xx4, yy4);
        if (0 <= xx3 && xx3 < m && 0 <= xx4 && xx4 < m && 0 <= yy3 && yy3 < n && 0 <= yy4 && yy4 < n && dist.count(idy)) {
            if (!laneright[idx].empty()) {
                for (int i = k - 1, j = laneright[idx].size(); i >= 0; --i) {
                    if (j - 1 >= 0) {
                        --j;
                    }
                    edges[encrypt(xx1, yy1, xx2, yy2, laneright[idx][j])].push_back({encrypt(xx3, yy3, xx4, yy4, i), (dcnt + dist[idy]) / 2, 0, 0});
                }
            }
        }
    }
}

inline int dijkstra(int start_pos, int end_pos, int x, int y) {
    auto hash_fn = [](const tuple<int, int, int>& o) {
        auto [x, y, z] = o;
        return x * 25 + y * 5 + z;
    };
    unordered_set<tuple<int, int, int>, decltype(hash_fn)> used(0, hash_fn);
    unordered_map<tuple<int, int, int>, int, decltype(hash_fn)> dd(0, hash_fn);
    // q: (dist, x, #turn, #change lane)
    using TIII = tuple<int, int, int, int>;
    priority_queue<TIII, vector<TIII>, greater<TIII>> q;
    q.emplace(0, start_pos, 0, 0);
    dd[{start_pos, 0, 0}] = 0;

    while (!q.empty()) {
        auto [dcnt, u, tcnt, ccnt] = q.top();
        q.pop();
        if (used.count({u, tcnt, ccnt})) {
            continue;
        }
        used.insert({u, tcnt, ccnt});
        for (auto [v, ddelta, tdelta, cdelta]: edges[u]) {
            int dall = dcnt + ddelta;
            int tall = tcnt + tdelta;
            int call = ccnt + cdelta;
            if (tall <= x && call <= y && (!dd.count({v, tall, call}) || dall < dd[{v, tall, call}])) {
                dd[{v, tall, call}] = dall;
                q.emplace(dall, v, tall, call);
            }
        }
    }

    int ans = INT_MAX;
    for (int i = 0; i <= x; ++i) {
        for (int j = 0; j <= y; ++j) {
            if (dd.count({end_pos, i, j})) {
                ans = min(ans, dd[{end_pos, i, j}]);
            }
        }
    }
    return (ans == INT_MAX ? -1 : ans);
}

inline void work() {
    cin >> m >> n >> k >> d;
    for (int i = 1; i <= d; ++i) {
        cin >> xx1 >> yy1 >> xx2 >> yy2 >> t;
        int enc = encrypt(xx1, yy1, xx2, yy2);
        dist[enc] = t;
        for (int j = 0; j < k; ++j) {
            cin >> s;
            for (int id = 0; id < s.size(); ++id) {
                char ch = s[id];
                if (ch == 'L') {
                    laneleft[enc].push_back(j);
                }
                else if (ch == 'S') {
                    lanestraight[enc].push_back(j);
                }
                else if (ch == 'R') {
                    laneright[enc].push_back(j);
                }
            }
        }
    }

    buildgraph();

    cin >> p;
    for (int i = 1; i <= p; ++i) {
        cin >> xx3 >> yy3 >> xx4 >> yy4 >> xx5 >> yy5 >> xx6 >> yy6 >> x >> y;
        int enc1 = encrypt(xx3, yy3, xx4, yy4, k - 1);
        int enc2 = encrypt(xx5, yy5, xx6, yy6, k - 1);
        cout << dijkstra(enc1, enc2, x, y) << "\n";
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}