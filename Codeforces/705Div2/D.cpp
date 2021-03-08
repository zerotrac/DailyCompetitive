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
const int mod = 1e9 + 7;
// const int mod = 998244353;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

auto pair_hash = [hash_fn = hash<int>()](const PII& o) {
    return (hash_fn(o.first) << 16) ^ hash_fn(o.second);
};

// (prime, idx) -> occ
unordered_map<pair<int, int>, int, decltype(pair_hash)> m1(0, pair_hash);
// prime -> min heap
unordered_map<int, priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>> m2;
// prime -> # of indices
unordered_map<int, int> m3;

static constexpr int MAXP = 450;
bool isprime[MAXP + 1];
vector<int> primes;

inline void init() {
    memset(isprime, true, sizeof(isprime));
    for (int i = 2; i <= MAXP; ++i) {
        if (isprime[i]) {
            primes.push_back(i);
            m3[i] = 0;
            for (int j = i + i; j <= MAXP; j += i) {
                isprime[j] = false;
            }
        }
    }
}

int n, q, x, y;
int ans;

inline unordered_map<int, int> factorize(int x) {
    if (x == 1) {
        return {};
    }

    unordered_map<int, int> ret;
    for (int prime: primes) {
        if (prime * prime > x) {
            break;
        }
        if (x % prime == 0) {
            int cnt = 0;
            while (x % prime == 0) {
                ++cnt;
                x /= prime;
            }
            ret[prime] = cnt;
        }
    }

    if (x != 1) {
        ret[x] = 1;
    }
    return ret;
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
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        unordered_map<int, int> factors = factorize(x);
        for (auto [prime, occ]: factors) {
            m1[{prime, i}] = occ;
            m2[prime].emplace(occ, i);
            ++m3[prime];
        }
        if (i == 1) {
            ans = x;
        }
        else {
            ans = gcd(ans, x);
        }
    }
    for (int i = 1; i <= q; ++i) {
        cin >> y >> x;
        unordered_map<int, int> factors = factorize(x);
        for (auto [prime, occ]: factors) {
            if (!m1.count({prime, y})) {
                m1[{prime, y}] = occ;
                m2[prime].emplace(occ, y);
                if (++m3[prime] == n) {
                    // cout << "good\n";
                    ans = (LL)ans * quickmul(prime, m2[prime].top().first) % mod;
                }
            }
            else {
                m1[{prime, y}] += occ;
                int prev = m2[prime].top().first;
                m2[prime].emplace(m1[{prime, y}], y);
                while (true) {
                    auto [odd, idx] = m2[prime].top();
                    if (m1[{prime, idx}] != odd) {
                        m2[prime].pop();
                    }
                    else {
                        break;
                    }
                }
                int curr = m2[prime].top().first;
                if (m3[prime] == n) {
                    ans = (LL)ans * quickmul(prime, curr - prev) % mod;
                }
            }
        }
        cout << ans << "\n";
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    init();
    work();
    return 0;
}