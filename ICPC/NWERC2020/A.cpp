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

int n, q, x;
int a[110];
LL f[20010];

inline void work() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; ++i) {
        f[i] = a[i];
    }
    for (int i = n + 1; i <= n * (n + 1); ++i) {
        f[i] = LLONG_MAX;
        for (int j = 1; j <= n; ++j) {
            f[i] = min(f[i], f[i - j] + a[j]);
        }
    }

    int best = 1;
    for (int i = 2; i <= n; ++i) {
        if ((LL)a[i] * best < (LL)a[best] * i) {
            best = i;
        }
    }

    for (int i = 1; i <= q; ++i) {
        cin >> x;
        if (x <= n * (n + 1)) {
            cout << f[x] << "\n";
        }
        else {
            int diff = x - n * (n + 1);
            int need = diff / best + (diff % best != 0);
            cout << (LL)f[x - need * best] + (LL)need * a[best] << "\n";
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}