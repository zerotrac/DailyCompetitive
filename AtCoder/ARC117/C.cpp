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

int C(int n, int k) {
    if (k == 0) {
        return 1;
    }
    if (k == 1) {
        return n % 3;
    }
    if (k == 2) {
        return ((LL)n * (n - 1) / 2) % 3;
    }
    return (LL)C(n / 3, k / 3) * C(n % 3, k % 3) % 3;
}

int n;
int a[400010];
string s;

inline void work() {
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'B') {
            a[i + 1] = 0;
        }
        else if (s[i] == 'W') {
            a[i + 1] = 1;
        }
        else {
            a[i + 1] = 2;
        }
    }
    int tot = 0;
    for (int i = 1; i <= n; ++i) {
        tot = (tot + C(n - 1, i - 1) * a[i]) % 3;
    }
    if (n & 1) {
        if (tot == 0) {
            cout << "B\n";
        }
        else if (tot == 1) {
            cout << "W\n";
        }
        else {
            cout << "R\n";
        }
    }
    else {
        if (tot == 0) {
            cout << "B\n";
        }
        else if (tot == 1) {
            cout << "R\n";
        }
        else {
            cout << "W\n";
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}