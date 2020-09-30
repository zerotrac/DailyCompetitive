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

int valid[200010];
int l[200010], r[200010];
int b[200010];
int n, x;

inline void work() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        if (!l[x]) {
            l[x] = i;
        }
        r[x] = i;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        if (l[b[i]]) {
            // cout << "b[i] = " << b[i] << " " << l[b[i]] << " " << r[b[i]] << "\n";
            int lth = l[b[i]] - i;
            int rth = r[b[i]] - i;
            if (lth < 0) {
                lth += n;
            }
            if (rth < 0) {
                rth += n;
            }
            // cout << "l, r = " << lth << "," << rth << "\n";
            if (lth <= rth) {
                ++valid[lth];
                --valid[rth + 1];
            }
            else {
                ++valid[lth];
                ++valid[0];
                --valid[rth + 1];
            }
        }
    }
    bool find = false;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += valid[i];
        if (sum == 0) {
            cout << "Yes\n";
            for (int j = (i == 0 ? 1 : n - i + 1), cnt = 0; cnt < n; ++cnt) {
                cout << b[j] << " ";
                ++j;
                if (j == n + 1) {
                    j = 1;
                }
            }
            cout << "\n";
            find = true;
            break;
        }
    }
    if (!find) {
        cout << "No\n";
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}