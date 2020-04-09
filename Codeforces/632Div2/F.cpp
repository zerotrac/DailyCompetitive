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

bool isprime[500010];
int ans[500010];
vector<int> primes;
int n;

inline void work() {
    memset(isprime, true, sizeof(isprime));
    cin >> n;
    for (int i = 2; i <= n; ++i) {
        if (isprime[i]) {
            primes.push_back(i);
            ans[i] = 1;
        }
        for (int prime: primes) {
            if (i * prime > n) {
                break;
            }
            isprime[i * prime] = false;
            ans[i * prime] = i;
            if (i % prime == 0) {
                break;
            }
        }
    }
    
    vector<int> id(n - 1);
    iota(id.begin(), id.end(), 2);
    sort(id.begin(), id.end(), [&](int u, int v) {return ans[u] < ans[v];});
    for (int i: id) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}