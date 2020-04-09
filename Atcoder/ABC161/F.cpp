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

LL n;

inline int alpha(LL n) {
    int ans = 0;
    for (LL i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            LL n0 = n;
            while (n0 % i == 0) {
                n0 /= i;
            }
            if ((n0 - 1) % i == 0) {
                ++ans;
            }
        }
    }
    ++ans; // n
    return ans;
}

inline int beta(LL n) {
    int ans = 0;
    for (LL i = 2; i * i <= n - 1; ++i) {
        if ((n - 1) % i == 0) {
            ++ans;
            if (i * i != n - 1) {
                ++ans;
            }
        }
    }
    if (n != 2) {
        ++ans; // n - 1
    }
    return ans;
}

inline void work() {
    cin >> n;
    cout << alpha(n) + beta(n) << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}