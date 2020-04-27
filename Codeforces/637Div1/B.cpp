#include <iostream>
#include <iomanip>
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

static constexpr int digits[10] = {0b1110111, 0b0010010, 0b1011101, 0b1011011, 0b0111010, 0b1101011, 0b1101111, 0b1010010, 0b1111111, 0b1111011};

int f[2010][2010];
int a[2010];
string st;
int n, k;

// f[][] = 1: valid / -2: invalid / -1: not visited
inline int dfs(int pos, int k) {
    if (pos == n + 1) {
        return k == 0 ? 1 : -2;
    }
    if (k < 0) {
        return -2;
    }
    if (f[pos][k] != -1) {
        return f[pos][k];
    }
    bool check = false;
    for (int nxt = 9; nxt >= 0; --nxt) {
        if ((a[pos] | digits[nxt]) == digits[nxt]) {
            int dt = __builtin_popcount(a[pos] ^ digits[nxt]);
            if (dfs(pos + 1, k - dt) == 1) {
                check = true;
            }
        }
    }
    return f[pos][k] = (check ? 1 : -2);
}

inline void work() {
    memset(f, -1, sizeof(f));
    cin >> n >> k;
    f[n + 1][0] = 1;
    for (int i = 1; i <= n; ++i) {
        cin >> st;
        a[i] = stoi(st, 0, 2);
    }

    int check = dfs(1, k);
    if (check != 1) {
        cout << -1 << "\n";
        return;
    }

    string ans;
    int rest = k;
    for (int i = 2; i <= n + 1; ++i) {
        for (int j = 9; j >= 0; --j) {
            if ((a[i - 1] | digits[j]) == digits[j]) {
                int dt = __builtin_popcount(a[i - 1] ^ digits[j]);
                if (rest - dt >= 0 && f[i][rest - dt] == 1) {
                    if (ans.size() || j > 0) {
                        ans += to_string(j);
                    }
                    rest -= dt;
                    break;
                }
            }
        }
    }
    if (!ans.size()) {
        ans = "0";
    }
    cout << ans << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}