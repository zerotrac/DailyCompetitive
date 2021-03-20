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

static constexpr int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71};
static constexpr int sz = sizeof(primes) / sizeof(primes[0]);

LL l, r;

inline void work() {
    cin >> l >> r;
    vector<int> masks;
    for (LL i = l; i <= r; ++i) {
        int mask = 0;
        for (int j = 0; j < sz; ++j) {
            if (i % primes[j] == 0) {
                mask |= (1 << j);
            }
        }
        masks.push_back(mask);
    }

    vector<LL> f(1 << sz);
    f[0] = 1;
    for (int mask: masks) {
        for (int i = (1 << sz) - 1; i >= 0; --i) {
            if ((i & mask) == mask) {
                f[i] += f[i ^ mask];
            }
        }
    }
    cout << accumulate(f.begin(), f.end(), 0LL) << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}