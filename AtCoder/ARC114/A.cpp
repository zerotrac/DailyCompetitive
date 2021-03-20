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

static constexpr int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
static constexpr int pcount = sizeof(primes) / sizeof(primes[0]);

int n;
int a[50];

inline void work() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    LL ans = LLONG_MAX;
    for (int mask = 1; mask < (1 << pcount); ++mask) {
        vector<int> v;
        for (int i = 0; i < pcount; ++i) {
            if (mask & (1 << i)) {
                v.push_back(primes[i]);
            }
        }
        bool check = true;
        for (int i = 1; i <= n; ++i) {
            bool find = false;
            for (int o: v) {
                if (a[i] % o == 0) {
                    find = true;
                    break;
                }
            }
            if (!find) {
                check = false;
                break;
            }
        }
        if (check) {
            LL cur = 1;
            for (int o: v) {
                cur *= (LL)o;
            }
            ans = min(ans, cur);
        }
    }
    cout << ans << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}