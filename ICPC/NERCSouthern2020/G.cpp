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

int n, h;
LL x[200010], y[200010];
static constexpr double eps = 1e-7;

// counter-clockwise > 0
// clockwise < 0
// parallel = 0
inline LL det(LL x1, LL y1, LL x2, LL y2) {
    return x1 * y2 - x2 * y1;
}

inline void work() {
    cin >> n >> h;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i];
    }
    LL xeye = x[n], yeye = y[n] + h;
    LL xview = 0, yview = -1;

    double ans = 0.;
    for (int i = n; i > 1; --i) {
        // deal with [x(i-1), y(i-1)] - [x(i), y(i)]
        LL dx = x[i - 1] - x[i];
        LL dy = y[i - 1] - y[i];
        if (det(xview, yview, dx, dy) > 0) {
            continue;
        }
        if (det(xview, yview, dx, dy) == 0) {
            if (det(xview, yview, x[i] - xeye, y[i] - yeye) == 0) {
                ans += sqrt(dx * dx + dy * dy);
            }
        }
        else {
            double slope = (double)(y[i] - y[i - 1]) / (x[i] - x[i - 1]);
            double t = (slope * (xeye - x[i - 1]) + (y[i - 1] - yeye)) / (yview - slope * xview);
            double xinter = xeye + t * xview;
            if (x[i - 1] < xinter + eps) {
                xinter = min(xinter, (double)x[i]);
                ans += (xinter - x[i - 1]) * sqrt(1. + slope * slope);
            }
            if (det(xview, yview, x[i - 1] - xeye, y[i - 1] - yeye) < 0) {
                xview = x[i - 1] - xeye;
                yview = y[i - 1] - yeye;
            }
        }
    }
    cout << fixed << setprecision(10) << ans << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}