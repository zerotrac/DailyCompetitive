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

int n;
LL k;
int a[100010];

inline void work() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        // a[i] could choose in range [i..n]
        // there will be 2^{n-i-1} or 1 starting with a[i]=i0
        int choose = 0;
        LL tot = 0;
        for (int j = i; j <= n; ++j) {
            int diff = n - j - 1;
            if (diff >= 60) {
                choose = j;
                break;
            }
            LL add = (j == n ? 1 : (1LL << diff));
            // cout << "add = " << add << endl;
            if (tot + add >= k) {
                choose = j;
                break;
            }
            tot += add;
        }
        // cout << "choose = " << choose << " " << tot << endl;
        if (!choose) {
            break;
        }
        for (int u = i, v = choose; v >= i; ++u, --v) {
            a[u] = v;
        }
        i += (choose - i);
        k -= tot;
    }
    if (k > 1) {
        cout << "-1\n";
    }
    else {
        for (int i = 1; i <= n; ++i) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    int T;
    cin >> T;
    while (T--) {
        work();
    }
    return 0;
}