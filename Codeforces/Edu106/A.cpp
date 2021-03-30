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

int n, w1, w2, w, b;

inline void work() {
    cin >> n >> w1 >> w2 >> w >> b;
    int b1 = n - w1, b2 = n - w2;
    int ww = w1 / 2 + w2 / 2 + ((w1 & 1) && (w2 & 1));
    int bb = b1 / 2 + b2 / 2 + ((b1 & 1) && (b2 & 1));
    cout << (ww >= w && bb >= b ? "YES" : "NO") << "\n";
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