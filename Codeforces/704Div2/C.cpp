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

int m, n;
string s, t;
int l[200010], r[200010];

inline void work() {
    cin >> m >> n >> s >> t;
    int pt = 0;
    for (int i = 0; i < n; ++i) {
        while (s[pt] != t[i]) {
            ++pt;
        }
        l[i] = pt;
        ++pt;
    }
    pt = m - 1;
    for (int i = n - 1; i >= 0; --i) {
        while (s[pt] != t[i]) {
            --pt;
        }
        r[i] = pt;
        --pt;
    }

    int ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        ans = max(ans, r[i + 1] - l[i]);
    }
    cout << ans << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}