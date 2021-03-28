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

int n, k;
int a[110], u[110];

inline void work() {
    cin >> n >> k;
    if (k < n - 1 || k > n * (n + 1) / 2 - 1) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    for (int i = 1; i < n; ++i) {
        u[i] = 1;
        --k;
    }
    for (int i = 1; i < n && k; ++i) {
        int alloc = min(n - i, k);
        u[i] += alloc;
        k -= alloc;
    }

    for (int i = 1; i <= n; ++i) {
        a[i] = i;
    }
    for (int i = n - 1; i >= 1; --i) {
        reverse(a + i, a + i + u[i]);
    }
    for (int i = 1; i <= n; ++i) {
        cout << a[i] << " ";
    }
    cout << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; ++_) {
        cout << "Case #" << _ << ": ";
        work();
    }
    return 0;
}