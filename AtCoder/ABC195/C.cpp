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

LL n;

inline void work() {
    cin >> n;
    int num = 1;
    LL bound = 9, ans = 0;
    while (n >= bound) {
        LL cnt = bound - (bound + 1) / 10 + 1;
        ans += cnt * ((num - 1) / 3);
        ++num;
        bound = bound * 10 + 9;
    }
    bound = (bound + 1) / 10 - 1;
    ans += (n - bound) * ((num - 1) / 3);
    cout << ans << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}