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
int a[300010], f[300010][256], transit[300010];
string st;

int dfs(int i, int mask) {
    if (f[i][mask] != -1) {
        return f[i][mask];
    }
    int bit = (transit[i] & mask) != transit[i];
    if (i == 1) {
        return f[i][mask] = bit;
    }
    else {
        return f[i][mask] = dfs(i - 1, ((mask << 1) | bit) & 0xff);
    }
}

inline void work() {
    cin >> n;
    memset(f, -1, sizeof(f));
    for (int i = 1; i <= n; ++i) {
        cin >> st;
        for (char ch: st) {
            a[i] = a[i] * 2 + (ch == 'R');
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int dt = 1; dt <= 8 && i + dt <= n; ++dt) {
            int j = i + dt;
            int diff = __builtin_popcount(~(a[i] ^ a[j]) & 0xff);
            if (dt <= diff) {
                transit[i] |= (1 << (dt - 1));
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        int judge = dfs(i, 0xff);
        cout << 2 - judge;
    }
    cout << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}