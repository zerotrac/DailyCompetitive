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
LL x, y;

inline void work() {
    cin >> n;
    vector<LL> u, v;
    for (int i = 1; i <= n * 2; ++i) {
        cin >> x >> y;
        if (x == 0) {
            u.push_back(abs(y));
        }
        else {
            v.push_back(abs(x));
        }
    }
    sort(u.begin(), u.end());
    sort(v.begin(), v.end());
    double ans = 0.;
    for (int i = 0; i < n; ++i) {
        ans += sqrt(u[i] * u[i] + v[i] * v[i]);
    }
    cout << fixed << setprecision(20) << ans << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    int T;
    cin >> T;
    while (T--) {
        work();
    }
    return 0;
}