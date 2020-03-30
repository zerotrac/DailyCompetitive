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

bool visited[301][301][301];
double f[301][301][301];
int n, x;

double dp(int a, int b, int c) {
    if (a < 0 || b < 0 || c < 0) {
        return 0.;
    }
    if (visited[a][b][c]) {
        return f[a][b][c];
    }

    visited[a][b][c] = true;
    if (a + b + c == 0) {
        return f[a][b][c] = 0.;
    }
    
    // f[a][b][c] = 1 + a/n * f[a-1][b][c] + b/n * f[a+1][b-1][c] + c/n * f[a][b+1][c-1] + (n-a-b-c)/n * f[a][b][c]
    f[a][b][c] = 1.;
    if (a > 0) {
        f[a][b][c] += (double)a / n * dp(a - 1, b, c);
    }
    if (b > 0) {
        f[a][b][c] += (double)b / n * dp(a + 1, b - 1, c);
    }
    if (c > 0) {
        f[a][b][c] += (double)c / n * dp(a, b + 1, c - 1);
    }
    f[a][b][c] *= (double)n / (a + b + c);
    return f[a][b][c];
}

inline void work() {
    cin >> n;
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (x == 1) {
            ++a;
        }
        else if (x == 2) {
            ++b;
        }
        else {
            ++c;
        }
    }
    cout << setprecision(10) << dp(a, b, c) << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}