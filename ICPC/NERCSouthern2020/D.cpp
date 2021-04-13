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

int n, m, a, b;
int s[200010];

inline void work() {
    cin >> n >> m >> a >> b;
    for (int i = 1; i <= m; ++i) {
        cin >> s[i];
    }
    sort(s + 1, s + m + 1, greater<int>());
    int run = (a < b ? a - 1 : n - a);
    int itv = abs(a - b);
    int ptr = 1, ans = 0;
    for (int i = itv - 1; i >= 1 && ptr <= m; --i) {
        int spent = i + run;
        while (ptr <= m && s[ptr] > spent) {
            ++ptr;
        }
        if (ptr <= m) {
            ++ans;
            ++ptr;
        }
    }
    cout << ans << "\n";
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