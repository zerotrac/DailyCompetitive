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

int n, k, m;
int a[200010];

inline void work() {
    cin >> n >> k >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i];
    }
    if ((n - m) % (k - 1) != 0) {
        cout << "NO\n";
        return;
    }
    for (int i = 1; i <= m; ++i) {
        int left = a[i] - i;
        int right = (n - a[i]) - (m - i);
        if (left >= (k - 1) / 2 && right >= (k - 1) / 2) {
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