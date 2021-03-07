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

unordered_map<int, int> cnt;

inline void init() {
    for (int i = 0; i < 16; ++i) {
        int row = 0, col = 0;
        for (int j = 0; j < 4; ++j) {
            if (i & (1 << j)) {
                int r = j / 2;
                int c = j % 2;
                row |= (1 << r);
                col |= (1 << c);
            }
        }
        ++cnt[row * 100 + col];
    }
}

int m, n, x;

inline void work() {
    cin >> m >> n;
    int row = 0, col = 0;
    for (int i = 1; i <= m; ++i) {
        cin >> x;
        row |= (1 << x);
    }
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        col |= (1 << x);
    }
    cout << cnt[row * 100 + col] << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    init();
    int T;
    cin >> T;
    while (T--) {
        work();
    }
    return 0;
}