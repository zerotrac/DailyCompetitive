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

int n;
int a[200010], b[200010], id[200010];

inline void work() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        id[i] = i;
    }
    a[0] = b[0] = 1;
    sort(id, id + n + 1, [&](int i, int j) {return a[i] < a[j];});
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int sx = a[id[i - 1]], sy = b[id[i - 1]];
        int ex = a[id[i]], ey = b[id[i]];
        if (sx == ex && sy == ey) {
            continue;
        }
        if (ex - sx == ey - sy) {
            if ((sx + sy) % 2 == 0) {
                ans += ex - sx;
            }
        }
        else {
            if ((sx + sy) % 2 == 0) {
                ++sx;
            }
            sx += ey - sy;
            sy = ey;
            if ((sx + sy) % 2 == 0) {
                ans += (ex - sx) / 2;
            }
            else {
                ans += (ex - sx + 1) / 2;
            }
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