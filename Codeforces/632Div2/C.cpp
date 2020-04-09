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

map<LL, int> pos;
int n, x;

inline void work() {
    cin >> n;
    pos[0] = 0;
    int left = 1;
    LL sum = 0, ans = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        sum += x;
        if (pos.count(sum)) {
            left = max(left, pos[sum] + 2);
        }
        ans += i - left + 1;
        pos[sum] = i;
    }
    cout << ans << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}