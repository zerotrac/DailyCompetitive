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

LL a[200010];
int k;

inline void work() {
    cin >> k;
    for (int i = 1; i <= k; ++i) {
        a[i] = a[i - 1];
        for (int j = 1; j * j <= i; ++j) {
            if (i % j == 0) {
                ++a[i];
                if (j * j != i) {
                    ++a[i];
                }
            }
        }
    }
    LL ans = 0;
    for (int i = 1; i <= k; ++i) {
        ans += a[k / i];
    }
    cout << ans << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}