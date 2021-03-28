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

int n, m;
int f[200010], base[200010];
bool isprime[200010];
vector<int> primes;

int fac[200030], facinv[200030];

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

inline void init() {
    fac[0] = facinv[0] = 1;
    for (int i = 1; i <= 200020; ++i) {
        fac[i] = (LL)fac[i - 1] * i % mod;
        facinv[i] = quickmul(fac[i], mod - 2);
    }
}

inline void work() {
    memset(isprime, true, sizeof(isprime));
    cin >> n >> m;
    f[1] = 1;
    for (int i = 2; i <= m; ++i) {
        if (isprime[i]) {
            primes.push_back(i);
            base[i] = i;
        }
        for (int prime: primes) {
            if (i * prime > m) {
                break;
            }
            base[i * prime] = prime;
            isprime[i * prime] = false;
            if (i % prime == 0) {
                break;
            }
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= m; ++i) {
        int cur = 1;
        int x = i;
        while (x != 1) {
            int pr = base[x];
            int cnt = 0;
            while (base[x] == pr) {
                ++cnt;
                x /= pr;
            }
            // C(n+cnt-1,cnt)
            cur = (LL)cur * fac[n + cnt - 1] % mod * facinv[cnt] % mod * facinv[n - 1] % mod;
        }

        ans = (ans + cur) % mod;
    }
    cout << ans << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    init();
    quickread();
    work();
    return 0;
}