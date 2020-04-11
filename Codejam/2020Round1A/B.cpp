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

vector<PII> ans;
bool a[40];
int n;

inline void print(int& x, int& y) {
    ans.emplace_back(x, y);
}

inline void down(int& x, int& y) {
    if (y == 1) {
        ++x;
    }
    else {
        ++x;
        ++y;
    }
    print(x, y);
}

inline void drag(int& x, int& y) {
    if (y == 1) {
        for (int i = 2; i <= x; ++i) {
            ++y;
            print(x, y);
        }
    }
    else {
        for (int i = x - 1; i >= 1; --i) {
            --y;
            print(x, y);
        }
    }
}

inline void work() {
    cin >> n;
    ans.clear();
    int step;
    for (step = 1;; ++step) {
        if ((1 << (step - 1)) + (step - 1) > n) {
            --step;
            break;
        }
    }
    memset(a, false, sizeof(a));
    n -= step;
    for (int i = step; i >= 1; --i) {
        if (n >= (1 << (i - 1)) - 1) {
            a[i] = true;
            n -= (1 << (i - 1)) - 1;
        }
    }
    int x = 1, y = 1;
    print(x, y);
    for (int i = 2; i <= step; ++i) {
        down(x, y);
        if (a[i]) {
            drag(x, y);
        }
    }
    while (n--) {
        down(x, y);
    }
    for (auto& pr: ans) {
        cout << pr.first << " " << pr.second << " " << "\n";
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; ++_) {
        cout << "Case #" << _ << ":\n";
        work();
    }
    return 0;
}