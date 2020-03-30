#include <iostream>
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

int f[3010][3010];
string s, t;

inline void work() {
    cin >> s >> t;
    for (int i = 1; i <= s.size(); ++i) {
        for (int j = 1; j <= t.size(); ++j) {
            f[i][j] = max(max(f[i][j - 1], f[i - 1][j]), f[i - 1][j - 1] + (s[i - 1] == t[j - 1]));
        }
    }
    string ans;
    int i = s.size(), j = t.size();
    while (i && j) {
        if (f[i][j] == f[i][j - 1]) {
            --j;
        }
        else if (f[i][j] == f[i - 1][j]) {
            --i;
        }
        else {
            ans += s[i - 1];
            --i;
            --j;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}