#include <iostream>
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

int a[10][1000], b[10][1000];
int h, w, k;
string st;

inline void work() {
    cin >> h >> w >> k;
    for (int i = 0; i < h; ++i) {
        cin >> st;
        for (int j = 0; j < w; ++j) {
            a[i][j] = st[j] - 48;
        }
    }
    int ans = h * w;
    for (int mask = 0; mask < (1 << (h - 1)); ++mask) {
        memset(b, 0, sizeof(b));
        int rows = 0;
        bool flag = true;
        for (int i = 0; i < h; ++i) {
            if (i > 0 && (((mask >> i) & 1) != ((mask >> (i - 1)) & 1))) {
                ++rows;
            }
            for (int j = 0; j < w; ++j) {
                b[rows][j] += a[i][j];
                if (b[rows][j] > k) {
                    flag = false;
                    break;
                }
            }
            if (!flag) {
                break;
            }
        }
        if (flag) {
            int cnt = rows;
            for (int j = 1; j < w; ++j) {
                bool split = false;
                for (int i = 0; i <= rows; ++i) {
                    if (b[i][j - 1] + b[i][j] > k) {
                        split = true;
                        break;
                    }
                }
                if (split) {
                    ++cnt;
                }
                else {
                    for (int i = 0; i <= rows; ++i) {
                        b[i][j] += b[i][j - 1];
                    }
                }
            }
            ans = min(ans, cnt);
        }
    }
    cout << ans << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}