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

int a[51][51];
int n, k;

inline void work() {
    cin >> n >> k;
    unordered_map<int, vector<pair<int, int>>> pos;
    unordered_map<int, vector<int>> f;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
            pos[a[i][j]].emplace_back(i, j);
            f[a[i][j]].emplace_back(a[i][j] == 1 ? 0 : INT_MAX);
        }
    }

    if (!pos.count(1)) {
        cout << "-1\n";
        return;
    }

    for (int i = 2; i <= k; ++i) {
        if (!pos.count(i)) {
            cout << "-1\n";
            return;
        }
        for (int v = 0; v < pos[i].size(); ++v) {
            for (int u = 0; u < pos[i - 1].size(); ++u) {
                f[i][v] = min(f[i][v], f[i - 1][u] + abs(pos[i - 1][u].first - pos[i][v].first) + abs(pos[i - 1][u].second - pos[i][v].second));
            }
        }
    }

    cout << *min_element(f[k].begin(), f[k].end()) << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}