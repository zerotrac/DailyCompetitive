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

int a, b;

inline void work() {
    cin >> a >> b;
    if (a >= b) {
        for (int i = 1; i <= a; ++i) {
            cout << i << " ";
        }
        for (int i = 1; i < b; ++i) {
            cout << -i << " ";
        }
        cout << -(a * (a + 1) / 2 - b * (b - 1) / 2) << "\n";
    }
    else {
        for (int i = 1; i < a; ++i) {
            cout << i << " ";
        }
        for (int i = 1; i <= b; ++i) {
            cout << -i << " ";
        }
        cout << b * (b + 1) / 2 - a * (a - 1) / 2 << "\n";
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}