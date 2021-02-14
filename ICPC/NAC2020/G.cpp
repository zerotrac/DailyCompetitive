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

int n, p, q, s;
int a[200010], b[200010];
bool useda[200010], usedb[200010];

inline void work() {
    cin >> n >> p >> q >> s;
    for (int i = 1; i <= p; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= q; ++i) {
        cin >> b[i];
    }

    sort(a + 1, a + p + 1);
    sort(b + 1, b + q + 1);

    int l = 0, r = 1000000000, ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;

        // multiset<int> u(a + 1, a + p + 1);
        // multiset<int> v(b + 1, b + q + 1);
        
        // while (!u.empty() && !v.empty()) {
        //     if (*u.rbegin() >= *v.rbegin()) {
        //         auto it = v.upper_bound(s - *u.rbegin());
        //         if (it != v.begin() && *u.rbegin() - *prev(it) <= mid) {
        //             ++choose;
        //             v.erase(prev(it));
        //         }
        //         u.erase(prev(u.end()));
        //     }
        //     else {
        //         auto it = u.upper_bound(s - *v.rbegin());
        //         if (it != u.begin() && *v.rbegin() - *prev(it) <= mid) {
        //             ++choose;
        //             u.erase(prev(it));
        //         }
        //         v.erase(prev(v.end()));
        //     }

        //     if (choose >= n) {
        //         break;
        //     }
        // }

        memset(useda, false, sizeof(useda));
        memset(usedb, false, sizeof(usedb));

        int aptr_1 = p, bptr_1 = q;
        int aptr_2 = 1, bptr_2 = 1;

        stack<int> ac, bc;
        int choose = 0;

        while (choose < n) {
            while (aptr_1 >= 1 && useda[aptr_1]) {
                --aptr_1;
            }
            if (!aptr_1) {
                break;
            }

            while (bptr_1 >= 1 && usedb[bptr_1]) {
                --bptr_1;
            }
            if (!bptr_1) {
                break;
            }

            if (a[aptr_1] >= b[bptr_1]) {
                while (bptr_2 <= q && a[aptr_1] + b[bptr_2] <= s) {
                    bc.push(bptr_2++);
                }
                while (!bc.empty() && (usedb[bc.top()] || a[aptr_1] < b[bc.top()])) {
                    bc.pop();
                }
                if (!bc.empty() && a[aptr_1] - b[bc.top()] <= mid) {
                    ++choose;
                    useda[aptr_1] = true;
                    usedb[bc.top()] = true;
                    bc.pop();
                }
                --aptr_1;
            }
            else {
                while (aptr_2 <= p && a[aptr_2] + b[bptr_1] <= s) {
                    ac.push(aptr_2++);
                }
                while (!ac.empty() && (useda[ac.top()] || b[bptr_1] < a[ac.top()])) {
                    ac.pop();
                }
                if (!ac.empty() && b[bptr_1] - a[ac.top()] <= mid) {
                    ++choose;
                    useda[ac.top()] = true;
                    usedb[bptr_1] = true;
                    ac.pop();
                }
                --bptr_1;
            }
        }

        if (choose >= n) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
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