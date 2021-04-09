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
int a[200010], b[200010], rep[200010], rev[200010];

inline void work() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i];
        if (a[i] <= n && b[i] <= n) {
            cout << "-1\n";
            return;
        }
        if (a[i] > n && b[i] > n) {
            cout << "-1\n";
            return;
        }
        if (a[i] <= n) {
            rep[a[i]] = b[i];
            rev[a[i]] = false;
        }
        else {
            rep[b[i]] = a[i];
            rev[b[i]] = true;
        }
    }

    int u = n * 2 + 1, v = n * 2 + 1, least = n * 2 + 1;
    int ans = 0, cur = 0, cnt = 0;
    for (int i = 1; i <= n; ++i) {
        ++cnt;
        if (rep[i] <= u) {
            u = rep[i];
            if (rev[i]) {
                ++cur;
            }
        }
        else if (rep[i] <= v) {
            v = rep[i];
            if (!rev[i]) {
                ++cur;
            }
        }
        else {
            cout << "-1\n";
            return;
        }
        least = min(least, rep[i]);
        if (n * 2 - least + 1 == i) {
            ans += min(cur, cnt - cur);
            cur = cnt = 0;
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