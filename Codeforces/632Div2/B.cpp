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

int a[100010], b[100010];
int n;

inline void work() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    bool p = false, m = false;
    bool ans = true;
    for (int i = 0; i < n; ++i) {
        int delta = b[i] - a[i];
        if (delta > 0 && !p) {
            ans = false;
            break;
        }
        else if (delta < 0 && !m) {
            ans = false;
            break;
        }
        if (a[i] == 1) {
            p = true;
        }
        if (a[i] == -1) {
            m = true;
        }
    }
    cout << (ans ? "YES" : "NO") << "\n";
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