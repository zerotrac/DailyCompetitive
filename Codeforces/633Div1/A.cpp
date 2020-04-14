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

int a[100010];
int n;

inline void work() {
    cin >> n;
    int diff = 0, mx = INT_MIN;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mx = max(mx, a[i]);
        diff = max(diff, mx - a[i]);
    }
    for (int i = 0;; ++i) {
        if ((1LL << i) - 1 >= diff) {
            cout << i << "\n";
            break;
        }
    }
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