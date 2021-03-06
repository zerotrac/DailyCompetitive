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
const int mod = 1e9 + 7;
// const int mod = 998244353;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

string s;
int add[200010], keep[200010], has[200010];
int f[200010][2][17];
int k;

inline int tonum(char c) {
    return (c <= '9' ? c - '0' : c - 'A' + 10);
}

inline int dfs(int pos, bool bound, int diff) {
    if (pos == s.size()) {
        return diff == k;
    }
    if (diff > k) {
        return 0;
    }

    if (f[pos][bound][diff] != -1) {
        return f[pos][bound][diff];
    }
    f[pos][bound][diff] = 0;
    
    if (!diff) {
        f[pos][bound][diff] = dfs(pos + 1, false, 0);
    }
    if (bound) {
        f[pos][bound][diff] += dfs(pos + 1, true, has[pos]);
        f[pos][bound][diff] %= mod;
        f[pos][bound][diff] += (LL)(diff ? add[pos] : add[pos] - 1) * dfs(pos + 1, false, diff + 1) % mod;
        f[pos][bound][diff] %= mod;
        f[pos][bound][diff] += (LL)keep[pos] * dfs(pos + 1, false, diff) % mod;
        f[pos][bound][diff] %= mod;
    }
    else {
        f[pos][bound][diff] += (LL)((diff ? 16 : 15) - diff) * dfs(pos + 1, false, diff + 1) % mod;
        f[pos][bound][diff] %= mod;
        f[pos][bound][diff] += (LL)diff * dfs(pos + 1, false, diff) % mod;
        f[pos][bound][diff] %= mod;
    }

    return f[pos][bound][diff];
}

inline void work() {
    cin >> s >> k;
    unordered_set<int> o; 
    for (int i = 0; i < s.size(); ++i) {
        int jm = tonum(s[i]);
        for (int j = 0; j < jm; ++j) {
            if (!o.count(j)) {
                ++add[i];
            }
            else {
                ++keep[i];
            }
        }
        o.insert(jm);
        has[i] = o.size();
    }

    memset(f, -1, sizeof(f));
    int ans = dfs(0, 1, 0);
    cout << ans << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}