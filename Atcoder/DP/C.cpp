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

int n;
int x, y, z;

inline void work() {
    cin >> n;
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y >> z;
        tie(a, b, c) = forward_as_tuple(max(b, c) + x, max(a, c) + y, max(a, b) + z);
    }
    cout << max(a, max(b, c)) << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}