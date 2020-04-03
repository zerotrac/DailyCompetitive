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

string s;
int cnt[26];
int T, n, k;

inline void work() {
    cin >> n >> k;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < (k + 1) / 2; ++i) {
        memset(cnt, 0, sizeof(cnt));
        int j = k - 1 - i;
        for (int i0 = i, j0 = j; i0 < n; i0 += k, j0 += k) {
            ++cnt[s[i0] - 97];
            if (i0 != j0) {
                ++cnt[s[j0] - 97];
            }
        }
        int sum = 0, mx = 0;
        for (int l = 0; l < 26; ++l) {
            sum += cnt[l];
            mx = max(mx, cnt[l]);
        }
        ans += sum - mx;
    }
    cout << ans << "\n";
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