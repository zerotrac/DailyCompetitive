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

int m;
int p[110];
LL n[110];

static constexpr int LIMIT = 3500;

inline bool check(LL sum, int delta) {
    int used = 0;
    for (int i = 1; i <= m; ++i) {
        int cnt = 0;
        while (cnt < n[i] && sum % p[i] == 0) {
            ++cnt;
            used += p[i];
            sum /= p[i];
        }
        if (sum % p[i] == 0) {
            return false;
        }
    }
    return sum == 1 && used == delta;
}

inline void work() {
    cin >> m;
    LL sum = 0;
    for (int i = 1; i <= m; ++i) {
        cin >> p[i] >> n[i];
        sum += p[i] * n[i];
    }

    for (int l = 1; sum >= 2 && l <= LIMIT; ++l, --sum) {
        if (check(sum, l - 1)) {
            cout << sum << "\n";
            return;
        }
    }
    cout << 0 << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; ++_) {
        cout << "Case #" << _ << ": ";
        work();
    }
    return 0;
}