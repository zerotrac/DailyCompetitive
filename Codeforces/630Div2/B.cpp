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

vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
int a[1010];
int T, n;

inline void work() {
    cin >> n;
    unordered_map<int, int> to;
    int m = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int j = 0; j < primes.size(); ++j) {
            if (a[i] % primes[j] == 0) {
                a[i] = primes[j];
                if (!to.count(primes[j])) {
                    to[primes[j]] = ++m;
                }
                a[i] = to[a[i]];
                break;
            }
        }
    }
    cout << m << "\n";
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    cin >> T;
    while (T--) {
        work();
    }
    return 0;
}