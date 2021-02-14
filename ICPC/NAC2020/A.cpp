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
const int mod = 998244353;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int m, k;
int mu[1000010];

inline void init() {
    vector<int> isprime(k + 1, true);
    vector<int> primes;
    mu[1] = 1;
    for (int i = 2; i <= k; ++i) {
        if (isprime[i]) {
            primes.push_back(i);
            mu[i] = -1;
        }
        for (int prime: primes) {
            if (i * prime > k) {
                break;
            }
            isprime[i * prime] = false;
            if (i % prime == 0) {
                mu[i * prime] = 0;
                break;
            }
            else {
                mu[i * prime] = -mu[i];
            }
        }
    }
}

inline int quickmul(int x, int y) {
    int ret = 1, mul = x;
    while (y) {
        if (y & 1) {
            ret = (LL)ret * mul % mod;
        }
        mul = (LL)mul * mul % mod;
        y >>= 1;
    }
    return ret;
}

inline void work() {
    cin >> m >> k;
    // # of ways where: -k <= a1, a2, ..., am <= k && gcd(a1, a2, ..., am) = 1
    // gcd(0, ..., 0) = 1 && gcd(0, x) = x

    init();

    int ans = 0;
    for (int g = 1; g <= k; ++g) {
        if (!mu[g]) {
            continue;
        }
        int cnt = (k / g) * 2 + 1;
        int cntm = quickmul(cnt, m) - 1;
        if (mu[g] == 1) {
            ans += cntm;
            if (ans >= mod) {
                ans -= mod;
            }
        }
        else {
            ans -= cntm;
            if (ans < 0) {
                ans += mod;
            }
        }
    }
    cout << ans + 1 << endl;
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}