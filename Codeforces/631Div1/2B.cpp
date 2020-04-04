#include <iostream>
#include <iomanip>
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

int a[200010];
int T, n;

inline bool check(int l, int r) {
    int span = r - l + 1;
    unordered_set<int> s;
    for (int i = l; i <= r; ++i) {
        if (a[i] > span || s.count(a[i])) {
            return false;
        }
        s.insert(a[i]);
    }
    return true;
}

inline void work() {
    cin >> n;
    int mx = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    bool p = false, q = false;
    if (check(1, mx) && check(mx + 1, n)) {
        p = true;
    }
    if (mx != n - mx && check(1, n - mx) && check(n - mx + 1, n)) {
        q = true;
    }
    cout << p + q << "\n";
    if (p) {
        cout << mx << " " << n - mx << "\n";
    }
    if (q) {
        cout << n - mx << " " << mx << "\n";
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    cin >> T;
    while (T--) {
        work();
    }
    return 0;
}