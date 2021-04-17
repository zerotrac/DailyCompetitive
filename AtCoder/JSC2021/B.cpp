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

int n, m;
int a[1010], b[1010];

inline void work() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i) {
        cin >> b[i];
    }

    int i = 1, j = 1;
    while (i <= n || j <= m) {
        if (i <= n && j <= m) {
            if (a[i] == b[j]) {
                ++i;
                ++j;
            }
            else if (a[i] < b[j]) {
                cout << a[i] << " ";
                ++i;
            }
            else {
                cout << b[j] << " ";
                ++j;
            }
        }
        else if (i <= n) {
            cout << a[i] << " ";
            ++i;
        }
        else {
            cout << b[j] << " ";
            ++j;
        }
    }
    cout << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}