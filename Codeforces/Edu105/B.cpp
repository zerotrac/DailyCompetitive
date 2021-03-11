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

int n, u, r, d, l;

inline void work() {
    cin >> n >> u >> r >> d >> l;
    for (int i = 0; i < 16; ++i) {
        auto [uu, rr, dd, ll] = tuple{u, r, d, l};
        if (i & 1) {
            --uu; --rr;
        }
        if (i & 2) {
            --rr; --dd;
        }
        if (i & 4) {
            --dd; --ll;
        }
        if (i & 8) {
            --ll; --uu;
        }
        if (max({uu, rr, dd, ll}) <= n - 2 && min({uu, rr, dd, ll}) >= 0) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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