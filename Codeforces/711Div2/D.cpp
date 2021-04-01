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

int a[100010], ts[100010];
int n, m, t, y;
LL x;

static constexpr int base = 100000;

inline void work() {
    cin >> n >> m;
    memset(a, -1, sizeof(a));
    a[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> t >> x >> y;
        for (int j = m; j >= 0; --j) {
            if (a[j] == -1) {
                continue;
            }
            ts[j] = i;
            LL idx = j;
            for (int k = 1; k <= y; ++k) {
                if (t == 1) {
                    idx = (idx * base + x + base - 1) / base;
                }
                else {
                    idx = (idx * x + base - 1) / base;
                }
                if (idx > m) {
                    break;
                }
                if (a[idx] == -1) {
                    a[idx] = i;
                }
                if (ts[idx] == i) {
                    break;
                }
                ts[idx] = i;
            }
        }
    }
    for (int i = 1; i <= m; ++i) {
        cout << a[i] << " ";
    }
    cout << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}