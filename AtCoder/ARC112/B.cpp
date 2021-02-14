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

LL b, c;

inline void work() {
    cin >> b >> c;
    vector<pair<LL, LL>> itvs;
    itvs.emplace_back(b - c / 2, b);
    itvs.emplace_back(-b - (c - 1) / 2, -b);
    if (c >= 1) {
        itvs.emplace_back(-b, -b + (c - 1) / 2);
    }
    if (c >= 2) {
        itvs.emplace_back(b, b + (c - 2) / 2);
    }

    // for (const auto& [u, v]: itvs) cout << "(" << u << ", " << v << ")" << endl;

    sort(itvs.begin(), itvs.end());
    LL ans = 0;
    LL l = itvs[0].first, r = itvs[0].second;
    for (int i = 1; i < itvs.size(); ++i) {
        LL ll = itvs[i].first, rr = itvs[i].second;
        if (ll > r || rr < l) {
            ans += r - l + 1;
            tie(l, r) = {ll, rr};
        }
        else {
            r = max(r, rr);
        }
    }
    ans += r - l + 1;
    cout << ans << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}