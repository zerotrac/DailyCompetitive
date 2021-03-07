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
string s;
int f[510][510][510];

bool dfs(int l, int r, int k) {
    if (l > r) {
        return true;
    }
    if (f[l][r][k]) {
        return f[l][r][k] == 1;
    }
    if (l == r) {
        f[l][r][k] = (k + 1 >= m ? 1 : -1);
        return f[l][r][k] == 1;
    }

    if (k + 1 >= m) {
        f[l][r][k] |= dfs(l, r - 1, 0);
    }

    for (int i = r - 1; i >= l; --i) {
        if (s[i] == s[r]) {
            f[l][r][k] |= (dfs(i + 1, r - 1, 0) && dfs(l, i, k + 1));
        }
    }
    
    if (!f[l][r][k]) {
        f[l][r][k] = -1;
    }
    return f[l][r][k] == 1;
}

inline void work() {
    cin >> s >> m;
    n = s.size();
    cout << (dfs(0, n - 1, 0) ? "Yes" : "No") << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}