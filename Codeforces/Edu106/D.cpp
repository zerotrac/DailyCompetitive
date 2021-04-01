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

static constexpr int MAXA = 20000000;
vector<int> primes;
bool isprime[MAXA + 10];
int divi[MAXA + 10];

inline void init() {
    memset(isprime, true, sizeof(isprime));
    divi[1] = 1;
    for (int i = 2; i <= MAXA; ++i) {
        if (isprime[i]) {
            primes.push_back(i);
            divi[i] = 2;
        }
        for (int p: primes) {
            if (i * p > MAXA) {
                break;
            }
            isprime[i * p] = false;
            if (i % p != 0) {
                divi[i * p] = divi[i] * 2;
            }
            else {
                divi[i * p] = divi[i];
                break;
            }
        }
    }
}

int c, d, x;

inline void work() {
    cin >> c >> d >> x;
    LL ans = 0;
    for (int g = 1; g * g <= x; ++g) {
        if (x % g == 0) {
            if ((x / g + d) % c == 0) {
                int u = (x / g + d) / c;
                ans += divi[u];
            }
            if (g * g != x && (g + d) % c == 0) {
                int u = (g + d) / c;
                ans += divi[u];
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    init();
    int T;
    cin >> T;
    while (T--) {
        work();
    }
    return 0;
}