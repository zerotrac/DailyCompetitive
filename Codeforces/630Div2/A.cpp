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
int a, b, c, d;
int x, y, X0, Y0, X1, Y1;

inline void work() {
    cin >> a >> b >> c >> d;
    cin >> x >> y >> X0 >> Y0 >> X1 >> Y1;

    if (a > 0 || b > 0) {
        int pos = x - a + b;
        if (X0 == X1 || pos < X0 || pos > X1) {
            cout << "No\n";
            return;
        }
    }
    if (c > 0 || d > 0) {
        int pos = y - c + d;
        if (Y0 == Y1 || pos < Y0 || pos > Y1) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
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