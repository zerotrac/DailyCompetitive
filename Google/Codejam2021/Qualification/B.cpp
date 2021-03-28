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

int x, y;
string st;
bool valid[1010][2];
int f[1010][2];

inline void work() {
    cin >> x >> y >> st;
    int n = st.size();
    memset(valid, false, sizeof(valid));
    memset(f, 0x3f, sizeof(f));

    if (st[0] != 'J') {
        valid[0][0] = true;
        f[0][0] = 0;
    }
    if (st[0] != 'C') {
        valid[0][1] = true;
        f[0][1] = 0;
    }

    for (int i = 1; i < n; ++i) {
        // CC
        if (st[i] != 'J' && valid[i - 1][0]) {
            valid[i][0] = true;
            f[i][0] = min(f[i][0], f[i - 1][0]);
        }
        // CJ
        if (st[i] != 'C' && valid[i - 1][0]) {
            valid[i][1] = true;
            f[i][1] = min(f[i][1], f[i - 1][0] + x);
        }
        // JC
        if (st[i] != 'J' && valid[i - 1][1]) {
            valid[i][0] = true;
            f[i][0] = min(f[i][0], f[i - 1][1] + y);
        }
        // JJ
        if (st[i] != 'C' && valid[i - 1][1]) {
            valid[i][1] = true;
            f[i][1] = min(f[i][1], f[i - 1][1]);
        }
    }

    int ans = INT_MAX;
    if (valid[n - 1][0]) {
        ans = min(ans, f[n - 1][0]);
    }
    if (valid[n - 1][1]) {
        ans = min(ans, f[n - 1][1]);
    }
    cout << ans << "\n";
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