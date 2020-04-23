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

LL a[2010], f[2010][2010];
int id[2010];
int n;

inline void work() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        id[i] = i;
    }
    sort(id + 1, id + n + 1, [&](int i, int j) {return a[i] < a[j] || (a[i] == a[j] && i < j);});
    for (int i = n; i >= 1; --i) {
        f[i][i] = a[id[1]] * abs(id[1] - i);
        for (int j = i + 1; j <= n; ++j) {
            f[i][j] = max(f[i][j - 1] + a[id[j - i + 1]] * abs(id[j - i + 1] - j), f[i + 1][j] + a[id[j - i + 1]] * abs(id[j - i + 1] - i));
        }
    }
    cout << f[1][n] << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}