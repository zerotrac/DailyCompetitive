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
int a[100010], climbl[100010], climbr[100010], bestl[100010], bestr[100010];

inline void work() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    a[0] = a[n + 1] = -1;

    climbl[1] = bestl[1] = 0;
    int k = 1;
    while (k < n) {
        if (a[k] < a[k + 1]) {
            int j = k + 1;
            climbl[j] = 1;
            bestl[j] = max(bestl[j - 1], climbl[j]);
            while (j + 1 <= n && a[j] < a[j + 1]) {
                ++j;
                climbl[j] = climbl[j - 1] + 1;
                bestl[j] = max(bestl[j - 1], climbl[j]);
            }
            k = j;
        }
        else {
            int j = k + 1;
            climbl[j] = 1;
            bestl[j] = max(bestl[j - 1], climbl[j]);
            while (j + 1 <= n && a[j] > a[j + 1]) {
                ++j;
                climbl[j] = climbl[j - 1] + 1;
                bestl[j] = max(bestl[j - 1], climbl[j]);
            }
            k = j;
        }
    }

    climbr[n] = bestr[n] = 0;
    k = n;
    while (k > 1) {
        if (a[k - 1] < a[k]) {
            int j = k - 1;
            climbr[j] = 1;
            bestr[j] = max(bestr[j + 1], climbr[j]);
            while (j - 1 >= 1 && a[j - 1] < a[j]) {
                --j;
                climbr[j] = climbr[j + 1] + 1;
                bestr[j] = max(bestr[j + 1], climbr[j]);
            }
            k = j;
        }
        else {
            int j = k - 1;
            climbr[j] = 1;
            bestr[j] = max(bestr[j + 1], climbr[j]);
            while (j - 1 >= 1 && a[j - 1] > a[j]) {
                --j;
                climbr[j] = climbr[j + 1] + 1;
                bestr[j] = max(bestr[j + 1], climbr[j]);
            }
            k = j;
        }
    }

    int ans = 0;
    for (int i = 2; i < n; ++i) {
        if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
            int l = i;
            while (l - 1 >= 1 && a[l - 1] < a[l]) {
                --l;
            }
            int r = i;
            while (r + 1 <= n && a[r + 1] < a[r]) {
                ++r;
            }
            
            // l -- i -- r
            int d1 = i - l;
            int d2 = r - i;
            if (bestl[l] >= max(d1, d2)) {
                continue;
            }
            if (bestr[r] >= max(d1, d2)) {
                continue;
            }

            int dd1 = (d1 % 2 == 0 ? d1 - 1 : d1);
            int dd2 = (d2 % 2 == 0 ? d2 - 1 : d2);
            if (d1 > dd2 && d2 > dd1) {
                ++ans;
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}