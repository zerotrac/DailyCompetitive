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
int a[100010], c[100010], id[100010];

inline void work() {
    cin >> n;
    LL ans = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> c[i];
        id[i] = i;
        ans += c[i];
    }
    sort(id + 1, id + n + 1, [&](int i, int j) {
        return a[i] < a[j] || (a[i] == a[j] && i > j);
    });

    int best = a[id[1]] + c[id[1]];
    for (int i = 2; i <= n; ++i) {
        if (a[id[i]] > best) {
            ans += a[id[i]] - best;
        }
        best = max(best, a[id[i]] + c[id[i]]);
    }

    cout << ans << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}