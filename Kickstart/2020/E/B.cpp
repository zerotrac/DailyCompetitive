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

int s[110];
int n, a, b, c;

inline void work() {
    cin >> n >> a >> b >> c;
    if (a + b - c > n) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    if (n == 1) {
        cout << "1\n";
        return;
    }
    if (a == 1 && b == 1) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    if (n == 2) {
        if (a == 2 && b == 2) {
            cout << "1 1\n";
        }
        else if (a == 1 && b == 2) {
            cout << "2 1\n";
        }
        else if (a == 2 && b == 1) {
            cout << "1 2\n";
        }
        else {
            while (1);
        }
        return;
    }
    for (int i = 1; i <= n; ++i) {
        s[i] = 1;
    }
    for (int i = 1; i <= a - c; ++i) {
        s[i] = 2;
    }
    for (int i = n - (b - c) + 1; i <= n; ++i) {
        s[i] = 2;
    }
    int l = a - c + 1, r = n - (b - c);
    int cc = c;
    if (b == c) {
        s[r] = 3;
        --r;
        --cc;
    }
    for (; cc > 0;) {
        s[l] = 3;
        ++l;
        --cc;
        if (cc > 0) {
            s[r] = 3;
            --r;
            --cc;
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << s[i];
        if (i != n) cout << " "; else cout << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    quickread();
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; ++_) {
        cout << "Case #" << _ << ": ";
        work();
    }
    return 0;
}