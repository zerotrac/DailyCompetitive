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
LL dx1, dy1, dx2, dy2;

inline void work() {
    cin >> n >> dx1 >> dy1 >> dx2 >> dy2;
    if (dx1 * dy2 == dx2 * dy1) {
        cout << "NO\n";
        return;
    }
    if (dx1 < 0) {
        dx1 = -dx1;
        dy1 = -dy1;
    }
    if (dx2 < 0) {
        dx2 = -dx2;
        dy2 = -dy2;
    }
    while (dx1 != 0) {
        int g = dx2 / dx1;
        dx2 -= g * dx1;
        dy2 -= g * dy1;
        swap(dx1, dx2);
        swap(dy1, dy2);
    }
    if (dy1 < 0) {
        dy1 = -dy1;
    }
    if (dx2 > n || dy1 > n || n != dx2 * dy1) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
        for (int i = 0; i < dx2; ++i) {
            for (int j = 0; j < dy1; ++j) {
                cout << i << " " << j << "\n";
            }
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}