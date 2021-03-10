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

int m, n;
int a[510][510], b[510][510];
string s;

inline void work() {
    cin >> m >> n;

    for (int i = 1; i <= m + 2; ++i) {
        for (int j = 1; j <= n + 2; ++j) {
            a[i][j] = b[i][j] = 0;
        }
    }

    for (int i = 1; i <= m; ++i) {
        cin >> s;
        for (int j = 1; j <= n; ++j) {
            a[i][j] = (s[j - 1] == 'X');
        }
    }
    
    for (int j = 1; j <= n; j += 3) {
        for (int i = 1; i <= m; ++i) {
            b[i][j] = 1;
        }
    }

    for (int j = 1; j <= n; j += 3) {
        if (a[2][j + 1] == 1 || a[2][j + 2] == 1) {
            b[2][j + 1] = b[2][j + 2] = 1;
        }
        else {
            b[1][j + 1] = b[1][j + 2] = 1;
        }
    }

    for (int i = 3; i <= m; ++i) {
        for (int j = 2; j <= n; ++j) {
            if (j % 3 == 1) {
                continue;
            }
            if (a[i][j]) {
                b[i][j] = 1;
                if (j % 3 == 0 && j == n) {
                    b[i][j - 1] = 1;
                }
            }
        }
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << (b[i][j] ? 'X' : '.');
        }
        cout << "\n";
    }
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