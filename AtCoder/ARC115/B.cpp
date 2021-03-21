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

int a[510], b[510], c[510][510];
int n;

inline void work() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> c[i][j];
        }
    }
    int rmin = INT_MAX;
    for (int j = 1; j <= n; ++j) {
        rmin = min(rmin, c[1][j]);
    }
    for (int j = 1; j <= n; ++j) {
        b[j] = c[1][j] - rmin;
    }
    int cmin = INT_MAX;
    for (int i = 1; i <= n; ++i) {
        cmin = min(cmin, c[i][1]);
    }
    for (int i = 1; i <= n; ++i) {
        a[i] = c[i][1] - cmin;
    }
    if (a[1] + b[1] > c[1][1]) {
        cout << "No\n";
        return;
    }

    int delta = c[1][1] - a[1] - b[1];
    for (int i = 1; i <= n; ++i) {
        a[i] += delta;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (c[i][j] != a[i] + b[j]) {
                cout << "No\n";
                return;
            }
        }
    }

    cout << "Yes\n";
    for (int i = 1; i <= n; ++i) {
        cout << a[i] << " ";
    }
    cout << "\n";
    for (int j = 1; j <= n; ++j) {
        cout << b[j] << " ";
    }
    cout << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}