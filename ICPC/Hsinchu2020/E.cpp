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

string st;
int m;

unordered_map<char, int> color_to_id = {{'R', 0}, {'G', 1}, {'B', 2}, {'C', 3}, {'M', 4}, {'Y', 5}, {'K', 6}};

int f[7][510][510];
int a[510];
static constexpr int BAD = INT_MIN / 3;

int dfs(int l, int r, int c) {
    if (l > r) {
        return 0;
    }
    if (l == r) {
        if (a[l] == c) {
            return 1;
        }
        if (m == 1) {
            return 0;
        }
        return BAD;
    }
    if (f[c][l][r] != -1) {
        return f[c][l][r];
    }

    if (a[l] == c) {
        int o = dfs(l + 1, r, c);
        return f[c][l][r] = (o == BAD ? BAD : o + 1);
    }
    if (a[r] == c) {
        int o = dfs(l, r - 1, c);
        return f[c][l][r] = (o == BAD ? BAD : o + 1);
    }

    f[c][l][r] = BAD;

    for (int i = l - 1; i < r; ++i) {
        // [l, i] + [i+1, r]
        int cl = dfs(l, i, c);
        int cr = dfs(i + 1, r, a[r]);
        if (cl != BAD && cr >= m) {
            f[c][l][r] = max(f[c][l][r], cl);
        }
    }

    return f[c][l][r];
}

inline void work() {
    memset(f, -1, sizeof(f));

    cin >> st >> m;
    int n = st.size();
    for (int i = 0; i < n; ++i) {
        a[i] = color_to_id[st[i]];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (a[i] == a[j]) {
                f[a[i]][i][j] = j - i + 1;
            }
            else {
                break;
            }
        }
    }
    for (int i = 0; i < 7; ++i) {
        if (dfs(0, n - 1, i) >= m) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}