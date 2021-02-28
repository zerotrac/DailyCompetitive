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

LL n;
bool mu[100010];

inline void work() {
    cin >> n;
    int ans = 0;
    memset(mu, true, sizeof(mu));
    for (LL i = 2; i * i <= n; ++i) {
        if (mu[i]) {
            for (LL j = i * i; j <= n && j * i <= n && j * j <= n; j *= i) {
                mu[j] = false;
            }
            LL u = i * i;
            while (u <= n) {
                ++ans;
                u *= i;
            }
        }
    }
    cout << n - ans << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}