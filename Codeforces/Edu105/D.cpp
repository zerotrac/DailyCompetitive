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
#include <functional>

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
int a[510][510];

inline void work() {
    cin >> n;
    vector<tuple<int, int, int>> e;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
            if (i < j) {
                e.emplace_back(a[i][j], i, j);
            }
        }
    }
    sort(e.begin(), e.end());

    vector<int> fa(n + 1), value(n + 1), dsu(n + 1);
    for (int i = 1; i <= n; ++i) {
        fa[i] = dsu[i] = i;
        value[i] = a[i][i];
    }

    function<int(int)> findset = [&](int x) {
        return x == dsu[x] ? x : dsu[x] = findset(dsu[x]);
    };

    for (auto [v, x, y]: e) {
        int fx = findset(x), fy = findset(y);
        if (fx == fy) {
            continue;
        }
        if (value[fx] == v) {
            fa[fy] = fx;
            dsu[fy] = fx;
        }
        else {
            int sz = fa.size();
            fa.push_back(sz);
            dsu.push_back(sz);
            value.push_back(v);
            fa[fx] = fa[fy] = sz;
            dsu[fx] = dsu[fy] = sz;
        }
    }

    cout << fa.size() - 1 << "\n";
    int m = fa.size() - 1;
    for (int i = 1; i <= m; ++i) {
        cout << value[i] << " ";
    }
    cout << "\n";
    for (int i = 1; i <= m; ++i) {
        if (i == fa[i]) {
            cout << i << "\n";
            break;
        }
    }
    for (int i = 1; i <= m; ++i) {
        if (i != fa[i]) {
            cout << i << " " << fa[i] << "\n";
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}