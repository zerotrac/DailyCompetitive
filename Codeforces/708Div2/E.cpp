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

int n, k;
int a[200010], span[200010][21], f[200010][21];

static constexpr int MAXA = 10000000;
vector<int> primes;
bool isprime[MAXA + 10];
int base[MAXA + 10];

inline void init() {
    memset(isprime, true, sizeof(isprime));
    base[1] = 1;
    for (int i = 2; i <= MAXA; ++i) {
        if (isprime[i]) {
            primes.push_back(i);
            base[i] = i;
        }
        for (int prime: primes) {
            if (i * prime > MAXA) {
                break;
            }
            isprime[i * prime] = false;
            if (i % prime != 0) {
                base[i * prime] = base[i] * prime;
            }
            else {
                base[i * prime] = base[i / prime];
                break;
            }
        }
    }
}

inline void work() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] = base[a[i]];
    }
    for (int j = 0; j <= k; ++j) {
        unordered_map<int, int> freq;
        int cnt = 0, used = 0, r = 0;
        for (int i = 1; i <= n; ++i) {
            if (i != 1) {
                if (--freq[a[i - 1]]) {
                    --cnt;
                }
            }
            while (r + 1 <= n && cnt + (freq[a[r + 1]] != 0) <= j) {
                ++r;
                if (++freq[a[r]] > 1) {
                    ++cnt;
                }
            }
            span[i][j] = r;
        }
    }

    for (int j = 0; j <= k; ++j) {
        f[n + 1][j] = 0;
    }

    for (int i = n; i >= 1; --i) {
        for (int j = 0; j <= k; ++j) {
            f[i][j] = INT_MAX / 2;
            if (j) {
                f[i][j] = min(f[i][j], f[i][j - 1]);
            }
            for (int u = 0; u <= j; ++u) {
                f[i][j] = min(f[i][j], f[span[i][u] + 1][j - u] + 1);
            }
        }
    }
    cout << f[1][k] << "\n";
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