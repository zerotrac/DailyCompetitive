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

int a, b;
int ncnt = 0;
int ans[100010], l[100010], r[100010];
bool check = true;

int dfs(int val) {
    if (!val) {
        return 0;
    }

    int u = ++ncnt;
    if (val == 1) {
        if (!a) {
            check = false;
            return 0;
        }
        --a;
        ans[u] = 1;
        return u;
    }

    if (b) {
        --b;
        ans[u] = 2;
        l[u] = dfs((val - 1) / 2);
        r[u] = dfs((val - 2) / 2);
    }
    else {
        --a;
        ans[u] = 1;
        l[u] = dfs(val / 2);
        r[u] = dfs((val - 1) / 2);
    }
    return u;
}

inline void work() {
    cin >> a >> b;
    int value = a + b * 2;
    int aa = a, bb = b;
    dfs(value);
    if (check) {
        for (int i = 1; i <= aa + bb; ++i) {
            cout << ans[i] << " " << l[i] << " " << r[i] << "\n";
        }
    }
    else {
        cout << "-1\n";
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}