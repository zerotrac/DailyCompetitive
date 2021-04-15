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

static constexpr int MAXA = 10000000;
vector<int> primes;
bool isprime[MAXA + 10];
int base[MAXA + 10];
LL d[MAXA + 10];
int ans[MAXA + 10];

inline void update(LL x, int y) {
    if (x > MAXA) {
        return;
    }
    if (ans[x] == -1 || y < ans[x]) {
        ans[x] = y;
    }
}

inline void init() {
    memset(isprime, true, sizeof(isprime));
    memset(ans, -1, sizeof(ans));
    d[1] = 1;
    ans[1] = 1;
    for (int i = 2; i <= MAXA; ++i) {
        if (isprime[i]) {
            primes.push_back(i);
            base[i] = 1;
            d[i] = i + 1;
            update(i + 1, i);
        }
        for (int prime: primes) {
            if (i * prime > MAXA) {
                break;
            }
            isprime[i * prime] = false;
            if (i % prime != 0) {
                base[i * prime] = i;
                d[i * prime] = (LL)d[i] * d[prime];
                update(d[i * prime], i * prime);
            }
            else {
                base[i * prime] = base[i];
                if (base[i] == 1) {
                    d[i * prime] = (LL)d[i] * prime + 1;
                }
                else {
                    d[i * prime] = (LL)d[base[i]] * d[i * prime / base[i]];
                }
                update(d[i * prime], i * prime);
                break;
            }
        }
    }
}

int c;

inline void work() {
    cin >> c;
    cout << ans[c] << "\n";
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