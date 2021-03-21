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

int n, m, x, y;
int a[100010];

inline void work() {
    cin >> n >> m;
    vector<vector<int>> v(m + 1);
    vector<int> cnt(n + 1);
    for (int i = 1; i <= m; ++i) {
        cin >> x;
        for (int j = 1; j <= x; ++j) {
            cin >> y;
            v[i].push_back(y);
            if (j == 1) {
                ++cnt[y];
                a[i] = y;
            }
        }
    }
    int bound = (m + 1) / 2;
    int found = 0;
    for (int i = 1; i <= n; ++i) {
        if (cnt[i] > bound) {
            found = i;
            break;
        }
    }
    bool check = true;
    if (found) {
        int cur = cnt[found];
        for (int i = 1; i <= m && cur > bound; ++i) {
            if (v[i].size() > 1 && v[i][0] == found) {
                --cur;
                a[i] = v[i][1];
            }
        }
        if (cur > bound) {
            check = false;
        }
    }
    if (check) {
        cout << "YES\n";
        for (int i = 1; i <= m; ++i) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    else {
        cout << "NO\n";
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