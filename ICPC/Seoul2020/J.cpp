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
int a[510][510], a_inv[510][510];

inline void work() {
    cin >> n;
    for (int j = 1; j <= n; ++j) {
        for (int i = 1; i <= n; ++i) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; ++i) {
        a_inv[i][i] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        int choose = 0;
        for (int i0 = i; i0 <= n; ++i0) {
            if (a[i0][i] == 1) {
                choose = i0;
                break;
            }
        }
        if (!choose) {
            cout << "-1\n";
            return;
        }
        if (i != choose) {
            for (int j = 1; j <= n; ++j) {
                swap(a[i][j], a[choose][j]);
                swap(a_inv[i][j], a_inv[choose][j]);
            }
        }
        for (int i0 = 1; i0 <= n; ++i0) {
            if (i0 != i && a[i0][i]) {
                for (int j = 1; j <= n; ++j) {
                    a[i0][j] ^= a[i][j];
                    a_inv[i0][j] ^= a_inv[i][j];
                }
            }
        }
    }

    for (int j = 1; j <= n; ++j) {
        for (int i = 1; i <= n; ++i) {
            if (a_inv[i][j]) {
                cout << i << " ";
            }
        }
        cout << "\n";
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}