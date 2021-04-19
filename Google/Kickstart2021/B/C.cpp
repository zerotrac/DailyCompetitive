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

LL z;

inline bool isprime(int x) {
    for (LL i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

inline void work() {
    cin >> z;
    if (z < 15) {
        cout << "6\n";
        return;
    }

    LL root = sqrt(z + 1);
    LL a = 0, b = 0, c = 0, d = 0;
    for (int i = root + 1;; ++i) {
        if (isprime(i)) {
            if (!c) {
                c = i;
            }
            else {
                d = i;
                break;
            }
        }
    }
    for (int i = root;; --i) {
        if (isprime(i)) {
            if (!b) {
                b = i;
            }
            else {
                a = i;
                break;
            }
        }
    }

    LL ans = a * b;
    if (c * d <= z) {
        ans = c * d;
    }
    else if (b * c <= z) {
        ans = b * c;
    }
    cout << ans << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; ++_) {
        cout << "Case #" << _ << ": ";
        work();
    }
    return 0;
}