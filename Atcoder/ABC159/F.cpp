#include <iostream>
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

int a[3000], f[3010];
int n, s;

inline void work() {
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (s == a[i]) {
            f[s] += (i + 1) * (n - i);
            f[s] %= mod;
        }
        else if (s > a[i]) {
            f[s] += (LL)f[s - a[i]] * (n - i) % mod;
            f[s] %= mod;
            for (int j = s - 1; j > a[i]; --j) {
                f[j] += f[j - a[i]];
                f[j] %= mod;
            }
            f[a[i]] += i + 1;
            f[a[i]] %= mod;
        }
    }
    cout << f[s] << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}