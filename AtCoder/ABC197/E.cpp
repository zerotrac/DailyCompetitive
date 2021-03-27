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
int a[200010], c[200010], l[200010], r[200010];
LL f[200010][2];
bool has[200010];

inline void work() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> c[i];
        l[i] = INT_MAX;
        r[i] = INT_MIN;
    }
    for (int i = 1; i <= n; ++i) {
        has[c[i]] = true;
        l[c[i]] = min(l[c[i]], a[i]);
        r[c[i]] = max(r[c[i]], a[i]);
    }
    l[0] = r[0] = 0;
    auto update = [](LL& x, LL prev, int prev_pos, int cur_pos_l, int cur_pos_r, int which) {
        if (cur_pos_r < prev_pos) {
            if (which == 0) {
                x = min(x, prev + (prev_pos - cur_pos_l));
            }
            else {
                x = min(x, prev + (prev_pos - cur_pos_l) + (cur_pos_r - cur_pos_l));
            }
        }
        else if (cur_pos_l > prev_pos) {
            if (which == 0) {
                x = min(x, prev + (cur_pos_r - prev_pos) + (cur_pos_r - cur_pos_l));
            }
            else {
                x = min(x, prev + (cur_pos_r - prev_pos));
            }
        }
        else {
            if (which == 0) {
                x = min(x, prev + (cur_pos_r - prev_pos) + (cur_pos_r - cur_pos_l));
            }
            else {
                x = min(x, prev + (prev_pos - cur_pos_l) + (cur_pos_r - cur_pos_l));
            }
        }
    };

    for (int i = 1; i <= n; ++i) {
        if (!has[i]) {
            l[i] = l[i - 1];
            r[i] = r[i - 1];
            f[i][0] = f[i - 1][0];
            f[i][1] = f[i - 1][1];
        }
        else {
            f[i][0] = f[i][1] = LLONG_MAX;
            update(f[i][0], f[i - 1][0], l[i - 1], l[i], r[i], 0);
            update(f[i][0], f[i - 1][1], r[i - 1], l[i], r[i], 0);
            update(f[i][1], f[i - 1][0], l[i - 1], l[i], r[i], 1);
            update(f[i][1], f[i - 1][1], r[i - 1], l[i], r[i], 1);
        }
    }
    cout << min(f[n][0] + abs(l[n]), f[n][1] + abs(r[n])) << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}