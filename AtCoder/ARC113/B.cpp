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

int a, b, c;

inline void work() {
    cin >> a >> b >> c;
    a %= 10;
    b %= 4;
    int up;
    if (b == 0) {
        cout << a * a * a * a % 10 << "\n";
    }
    else if (b == 1) {
        cout << a % 10 << "\n";
    }
    else if (b == 2) {
        if (c == 1) {
            cout << a * a % 10 << "\n";
        }
        else {
            cout << a * a * a * a % 10 << "\n";
        }
    }
    else {
        if (c & 1) {
            cout << a * a * a % 10 << "\n";
        }
        else {
            cout << a % 10 << "\n";
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}