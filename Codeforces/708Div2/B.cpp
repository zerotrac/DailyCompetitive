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

int n, m, x;

inline void work() {
    cin >> n >> m;
    unordered_map<int, int> freq;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        x %= m;
        ++freq[x];
    }
    int ans = 0;
    for (int i = 0; i + i <= m; ++i) {
        if (i == 0 || i + i == m) {
            if (freq.count(i)) {
                ++ans;
            }
        }
        else {
            int p = freq[i];
            int q = freq[m - i];
            if (!p && !q) {
                continue;
            }
            if (p < q) {
                swap(p, q);
            }
            ans += (!q ? p : 1 + max(p - q - 1, 0));
        }
    }
    cout << ans << "\n";
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