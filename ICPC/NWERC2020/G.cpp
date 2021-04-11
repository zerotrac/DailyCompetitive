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

int n, r, m;
int pos[60], fail[60];
double pr[60];

double f[60][5010];
bool used[60][5010];
double guess;

static constexpr double TRIAL = 100;

double dfs(int i, int j) {
    // currently before the i-th trick, and the extra time is j
    if (j >= r - n) {
        return 1e20;
    }
    if (i == m + 1) {
        return 0.;
    }
    if (used[i][j]) {
        return f[i][j];
    }

    used[i][j] = true;
    f[i][j] = pr[i] * (pos[i + 1] - pos[i] + dfs(i + 1, j)) + (1 - pr[i]) * (min(guess, fail[i] + pos[i + 1] - pos[i] + dfs(i + 1, j + fail[i])));
    return f[i][j];
}

inline void work() {
    cin >> n >> r >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> pos[i] >> pr[i] >> fail[i];
    }
    pos[0] = 0;
    pr[0] = 1.;
    fail[0] = 0;
    pos[m + 1] = n;

    double l = 0., r = 1e10;
    for (int _ = 1; _ <= TRIAL; ++_) {
        memset(used, false, sizeof(used));
        guess = (l + r) / 2.;
        double res = dfs(0, 0);
        if (res > guess) {
            l = guess;
        }
        else {
            r = guess;
        }
    }

    cout << fixed << setprecision(10) << l << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}