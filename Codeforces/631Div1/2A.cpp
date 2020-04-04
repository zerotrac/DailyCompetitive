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

int T;
int n, k, x;

inline void work() {
    cin >> n >> k;
    unordered_set<int> rank;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        rank.insert(x);
    }
    int ans = 0;
    while (rank.count(ans + 1) || k > 0) {
        ++ans;
        if (!rank.count(ans)) {
            --k;
        }
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