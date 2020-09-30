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

double f[233333333];
int up[100], cur[100], ex[100];
int n, m, k;

void dfs(int pos, int baseline) {
    // cout << "pos = " << pos << " " << baseline << endl;
    if (pos == k + 1) {
        bool final = true;
        int status = 0;
        for (int i = 1; i <= k; ++i) {
            if (cur[i] != up[i]) {
                final = false;
            }
            status += cur[i] * ex[i];
        }
        // cout << "status = " << status << endl;
        if (final) {
            f[status] = 0.0;
        }
        else {
            int bad = 0;
            double total = 0.0;
            for (int i = 1; i <= k;) {
                // if (cur[i] == up[i]) {
                //     ++bad;
                //     ++i;
                //     continue;
                // }
                int j = i;
                while (j + 1 <= k && cur[j + 1] == cur[i]) {
                    ++j;
                }
                int delta = j - i + 1;
                if (cur[i] == 0) {
                    delta = m - (k - j);
                }
                if (cur[j] == up[j]) {
                    bad += delta;
                    i = j + 1;
                    continue;
                }
                // cout << "delta = " << delta << " " << cur[i] << " " << i << " " << j << "\n";
                total += static_cast<double>(delta) / m * f[status + ex[j]];
                i = j + 1;
            }
            if (cur[1] > 0) {
                bad += m - k;
            }
            f[status] = (total + 1) / (1.0 - static_cast<double>(bad) / m);
            // cout << "st = " << status << " " << total << " " << bad << " " << f[status] << "\n";
        }
        return;
    }
    for (int i = up[pos]; i >= baseline; --i) {
        // cout << "i = " << pos << " " << i << "\n";
        cur[pos] = i;
        dfs(pos + 1, i);
    }
}

inline void work() {
    cin >> n >> m >> k;
    for (int i = 1; i <= k; ++i) {
        cin >> up[i];
        cur[i] = 0;
    }
    ex[k] = 1;
    for (int i = k - 1; i >= 1; --i) {
        ex[i] = ex[i + 1] * up[i + 1];
        // cout << "ex = " << i << " " << ex[i] << endl;
    }
    // cout << "good" << endl;
    dfs(1, 0);
    cout << setprecision(10) << f[0] << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; ++_) {
        cout << "Case #" << _ << ": ";
        work();
    }
    return 0;
}