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

int m, n, x, y;
int a[110][110];
string st;
static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

inline void work() {
    cin >> m >> n >> x >> y;
    for (int i = 1; i <= m; ++i) {
        cin >> st;
        for (int j = 1; j <= n; ++j) {
            a[i][j] = (st[j - 1] == '#');
        }
    }
    int ans = 0;
    for (int i = 0; i < 4; ++i) {
        int xx = x, yy = y;
        while (xx >= 1 && xx <= m && yy >= 1 && yy <= n && a[xx][yy] == 0) {
            ++ans;
            xx += dirs[i][0];
            yy += dirs[i][1];
        }
    }
    cout << ans - 3 << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}