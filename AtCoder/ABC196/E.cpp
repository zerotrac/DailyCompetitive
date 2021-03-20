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

int n, q;
int t[200010];
LL a[200010];
LL x;

inline void work() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> t[i];
    }
    LL l = INT_MIN, r = INT_MAX, delta = 0;
    for (int i = 1; i <= n; ++i) {
        if (t[i] == 1) {
            delta += a[i];
        }
        else if (t[i] == 2) {
            LL y = a[i] - delta;
            if (l < y) {
                l = y;
            }
            if (r < y) {
                r = y;
            }
        }
        else {
            LL y = a[i] - delta;
            if (l > y) {
                l = y;
            }
            if (r > y) {
                r = y;
            }
        }
    }
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        cin >> x;
        if (x < l) {
            x = l;
        }
        if (x > r) {
            x = r;
        }
        cout << x + delta << "\n";
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}