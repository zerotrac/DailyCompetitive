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
const int mod = 998244353;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int n;
int a[500010], f[500010];

inline void work() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    f[0] = 1;
    int total = 0;
    vector<pair<int, int>> v;

    auto update = [](int& x, int y) {
        x += y;
        if (x > mod) {
            x -= mod;
        }
        if (x < 0) {
            x += mod;
        }
    };

    for (int i = 1; i <= n; ++i) {
        int merge = 0;
        while (!v.empty() && a[v.back().first] >= a[i]) {
            update(total, -((LL)v.back().second * a[v.back().first] % mod));
            update(merge, v.back().second);
            v.pop_back();
        }
        update(merge, f[i - 1]);
        v.emplace_back(i, merge);
        update(total, (LL)merge * a[i] % mod);
        update(f[i], -total);
    }

    cout << (n & 1 ? (-f[n] + mod) % mod : f[n]) << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}