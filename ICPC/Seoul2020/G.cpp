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

int n;
LL d;
LL a[1000010], b[1000010];

inline void work() {
    cin >> n >> d;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        b[i] = a[i] - d * (i - 1);
    }
    LL lb1 = *min_element(b + 1, b + n + 1);
    LL rb1 = *max_element(b + 1, b + n + 1);
    LL delta1 = rb1 - lb1;
    for (int i = 1; i <= n; ++i) {
        b[i] = a[i] - d * (n - i);
    }
    LL lb2 = *min_element(b + 1, b + n + 1);
    LL rb2 = *max_element(b + 1, b + n + 1);
    LL delta2 = rb2 - lb2;
 
    LL delta = min(delta1, delta2);
    if (delta % 2 == 0) {
        cout << delta / 2 << ".0" << "\n";
    }
    else {
        cout << delta / 2 << ".5" << "\n";
    };
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}