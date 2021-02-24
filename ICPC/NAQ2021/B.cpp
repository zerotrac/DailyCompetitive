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
LL x[2010], y[2010], r[2010];

const double pi = acos(-1.0);

inline void work() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i] >> r[i];
    }

    double ans = 0.;
    for (int i = n; i >= 1; --i) {
        vector<pair<double, double>> itvs;
        bool covered = false;
        for (int j = i + 1; j <= n; ++j) {
            LL dist2 = (x[j] - x[i]) * (x[j] - x[i]) + (y[j] - y[i]) * (y[j] - y[i]);
            if (r[j] >= r[i] && dist2 <= (r[j] - r[i]) * (r[j] - r[i])) {
                covered = true;
                break;
            }
            if (dist2 >= (r[j] + r[i]) * (r[j] + r[i])) {
                continue;
            }
            if (r[j] < r[i] && dist2 <= (r[i] - r[j]) * (r[i] - r[j])) {
                continue;
            }

            double ang = atan2(y[j] - y[i], x[j] - x[i]);
            if (ang < 0) {
                ang += pi * 2;
            }
            double da = acos((r[i] * r[i] + dist2 - r[j] * r[j]) / (2. * r[i] * sqrt(dist2)));
            double dl = ang - da, dr = ang + da;
            if (dl < 0.) {
                itvs.emplace_back(dl + pi * 2, pi * 2);
                itvs.emplace_back(0, dr);
            }
            else if (dr > pi * 2) {
                itvs.emplace_back(dl, pi * 2);
                itvs.emplace_back(0, dr - pi * 2);
            }
            else {
                itvs.emplace_back(dl, dr);
            }
        }
        if (covered) {
            continue;
        }

        if (itvs.empty()) {
            ans += pi * 2 * r[i];
            continue;    
        }

        sort(itvs.begin(), itvs.end());
        
        double len = itvs[0].first;
        auto [L, R] = itvs[0];
        for (int i = 1; i < itvs.size(); ++i) {
            auto [ll, rr] = itvs[i];
            if (ll > R) {
                len += ll - R;
                tie(L, R) = {ll, rr};
            }
            else {
                R = max(R, rr);
            }
        }
        len += pi * 2 - R;
        ans += len * r[i];
    }
    cout << fixed << setprecision(10) << ans << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}