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

int a[50][30];
int f[1510], g[1510];
int N, K, P;

inline void work() {
    cin >> N >> K >> P;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < K; ++j) {
            cin >> a[i][j];
        }
    }
    memset(f, 0, sizeof(f));
    memset(g, 0, sizeof(g));
    for (int i = 0; i < N; ++i) {
        int sum = 0;
        for (int j = 0; j < K; ++j) {
            sum += a[i][j];
            for (int l = P; l >= j + 1; --l) {
                g[l] = max(g[l], f[l - j - 1] + sum);
            }
        }
        memcpy(f, g, sizeof(int) * (P + 1));
    }
    cout << f[P] << "\n";
}

int main() {
    // freopen("B.txt", "r", stdin);
    quickread();
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; ++_) {
        cout << "Case #" << _ << ": ";
        work();
    }
    return 0;
}