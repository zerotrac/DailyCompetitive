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
#include <cassert>

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

// valid? show the pos
// invalid? (INT_MIN, INT_MIN)
pair<int, int> intersect[510][510];

// u=0, l=1, d=2, r=3
// valid? show the INTERSECT pos
// invlaid? (INT_MIN, INT_MIN)
pair<int, int> fwd[510][510][4];

int n;
LL t;
int bx[510], by[510], ex[510], ey[510];

inline void work() {
    cin >> n >> t;
    int startx = 1, starty = -1, dir = -1;
    for (int i = 1; i <= n; ++i) {
        cin >> bx[i] >> by[i] >> ex[i] >> ey[i];
        if (bx[i] == ex[i]) {
            if (by[i] > ey[i]) {
                swap(by[i], ey[i]);
                if (i == 1) {
                    starty = n + 2;
                    dir = 2;
                }
            }
            else if (i == 1) {
                starty = n + 1;
                dir = 0;
            }
        }
        else {
            if (bx[i] > ex[i]) {
                swap(bx[i], ex[i]);
                if (i == 1) {
                    starty = n + 2;
                    dir = 1;
                }
            }
            else if (i == 1) {
                starty = n + 1;
                dir = 3;
            }
        }
    }
    for (int i = 1; i <= n + 2; ++i) {
        for (int j = 1; j <= n + 2; ++j) {
            intersect[i][j] = {INT_MIN, INT_MIN};
            fwd[i][j][0] = fwd[i][j][1] = fwd[i][j][2] = fwd[i][j][3] = {INT_MIN, INT_MIN};
        }
    }

    for (int i = 1; i <= n; ++i) {
        intersect[i][n + 1] = intersect[n + 1][i] = {bx[i], by[i]};
        intersect[i][n + 2] = intersect[n + 2][i] = {ex[i], ey[i]};
    }

    auto fwdlr = [&](int a, int b, int c, int d) {
        // cout << "fwdlr: " << a << ", " << b << ", " << c << ", " << d << endl;
        fwd[min(a, b)][max(a, b)][3] = {min(c, d), max(c, d)};
        fwd[min(c, d)][max(c, d)][1] = {min(a, b), max(a, b)};
    };

    auto fwdud = [&](int a, int b, int c, int d) {
        // cout << "fwdud: " << a << ", " << b << ", " << c << ", " << d << endl;
        fwd[min(a, b)][max(a, b)][0] = {min(c, d), max(c, d)};
        fwd[min(c, d)][max(c, d)][2] = {min(a, b), max(a, b)};
    };

    for (int i = 1; i <= n; ++i) {
        // cout << "i = " << i << " " << n << endl;
        if (bx[i] == ex[i]) {
            // vertical
            vector<pair<int, int>> v;
            for (int j = 1; j <= n; ++j) {
                // cout << "j = " << j << endl;
                if (bx[j] == ex[j]) {
                    continue;
                }
                if (by[i] <= by[j] && by[j] <= ey[i] && bx[j] <= bx[i] && bx[i] <= ex[j]) {
                    intersect[i][j] = intersect[j][i] = {bx[i], by[j]};
                    v.emplace_back(by[j], j);
                }
            }
            sort(v.begin(), v.end());
            // cout << "v.size = " << v.size() << endl;
            if (!v.empty()) {
                for (int j = 0; j < v.size() - 1; ++j) {
                    fwdud(i, v[j].second, i, v[j + 1].second);
                }
                fwdud(i, n + 1, i, v[0].second);
                fwdud(i, v.back().second, i, n + 2);
            }
            else {
                fwdud(i, n + 1, i, n + 2);
            }
        }
        else {
            // horizontal
            vector<pair<int, int>> v;
            for (int j = 1; j <= n; ++j) {
                // cout << "j = " << j << endl;
                if (by[j] == ey[j]) {
                    continue;
                }
                if (bx[i] <= bx[j] && bx[j] <= ex[i] && by[j] <= by[i] && by[i] <= ey[j]) {
                    intersect[i][j] = intersect[j][i] = {bx[j], by[i]};
                    v.emplace_back(bx[j], j);
                }
            }
            sort(v.begin(), v.end());
            // cout << "v.size = " << v.size() << endl;
            if (!v.empty()) {
                for (int j = 0; j < v.size() - 1; ++j) {
                    fwdlr(i, v[j].second, i, v[j + 1].second);
                }
                fwdlr(i, n + 1, i, v[0].second);
                fwdlr(i, v.back().second, i, n + 2);
            }
            else {
                fwdlr(i, n + 1, i, n + 2);
            }
        }
    }

    // cout << "good" << endl;

    vector<tuple<int, int, int>> path;
    LL total_dist = 0;
    // int count = 0;
    while (true) {
        // cout << "road = " << startx << " " << starty << " " << dir << " " << total_dist << endl;
        // ++count; if (count >= 10) break;
        path.emplace_back(startx, starty, dir);
        if (path.size() > 1 && path[0] == path.back()) {
            break;
        }
        auto [u1, v1] = intersect[startx][starty];
        auto [nxtx, nxty] = fwd[startx][starty][dir];
        auto [u2, v2] = intersect[nxtx][nxty];
        total_dist += abs(u1 - u2) + abs(v1 - v2);
        if (nxty == n + 1 || nxty == n + 2) {
            dir = (dir + 2) % 4;
        }
        else {
            dir = (dir + 1) % 4;
        }
        startx = nxtx;
        starty = nxty;
    }

    t %= total_dist;
    bool find = false;
    for (int i = 0; i < path.size() - 1; ++i) {
        auto [u1, v1] = intersect[get<0>(path[i])][get<1>(path[i])];
        auto [u2, v2] = intersect[get<0>(path[i + 1])][get<1>(path[i + 1])];
        int d = abs(u1 - u2) + abs(v1 - v2);
        // cout << "d = " << u1 << " " << v1 << " " << u2 << " " << v2 << " " << d << endl;
        if (t > d) {
            t -= d;
        }
        else {
            if (u1 == u2) {
                if (v1 < v2) {
                    cout << u1 << " " << v1 + t << "\n";
                }
                else {
                    cout << u1 << " " << v1 - t << "\n";
                }
            }
            else {
                if (u1 < u2) {
                    cout << u1 + t << " " << v1 << "\n";
                }
                else {
                    cout << u1 - t << " " << v1 << "\n";
                }
            }
            find = true;
            break;
        }
    }
    assert(find);
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}