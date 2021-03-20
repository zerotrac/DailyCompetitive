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

int n, m, q, l, r;
int w[51], v[51], x[51];
bool used[51];

inline void work() {
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= m; ++i) {
        cin >> x[i];
    }
    for (int i = 1; i <= q; ++i) {
        cin >> l >> r;
        vector<int> valid;
        for (int j = 1; j <= m; ++j) {
            if (l <= j && j <= r) {
                continue;
            }
            valid.push_back(x[j]);
        }
        sort(valid.begin(), valid.end());
        memset(used, false, sizeof(used));
        int ans = 0;
        for (int sz: valid) {
            int best = 0;
            for (int j = 1; j <= n; ++j) {
                if (!used[j] && w[j] <= sz && (!best || v[j] > v[best])) {
                    best = j;
                }
            }
            if (best) {
                ans += v[best];
                used[best] = true;
            }
        }
        cout << ans << "\n";
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}