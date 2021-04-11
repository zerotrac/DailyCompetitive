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

int n, x;
vector<vector<int>> e;

inline vector<int> combine(const vector<int>& x, const vector<int>& y) {
    int m = x.size(), n = y.size();
    vector<int> ret;
    ret.reserve((m + 1) * (n + 1) - 1);
    for (int j = 0; j < n; ++j) {
        ret.push_back(y[j]);
    }
    for (int i = 0; i < m; ++i) {
        ret.push_back(x[i]);
        if (i & 1) {
            for (int j = 0; j < n; ++j) {
                ret.push_back(y[j]);
            }
        }
        else {
            for (int j = n - 1; j >= 0; --j) {
                ret.push_back(y[j]);
            }
        }
    }
    return ret;
}

vector<int> dfs(int u) {
    vector<int> ret;
    for (int v: e[u]) {
        vector<int> another = dfs(v);
        if (ret.empty()) {
            ret = another;
        }
        else {
            ret = combine(ret, another);
        }
    }
    if (u != 1) {
        ret.insert(ret.begin(), u);
    }
    return ret;
}

inline void work() {
    cin >> n;
    e.resize(n + 1);
    for (int i = 2; i <= n; ++i) {
        cin >> x;
        e[x].push_back(i);
    }
    vector<int> ans = dfs(1);
    cout << ans.size() << "\n";
    for (int o: ans) {
        cout << o << " ";
    }
    cout << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}