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

int n;
int p;
string st;

inline bool check(const string& s) {
    int c0 = 0, c1 = 0, c2 = 0;
    for (char ch: s) {
        if (ch == '0') {
            ++c0;
        }
        else if (ch == '1') {
            ++c1;
        }
        else if (ch == '2') {
            ++c2;
        }
    }
    return c0 >= 1 && c1 >= 1 && c2 >= 2;
}

inline void work() {
    cin >> n;
    int ans = 0;
    int cost = INT_MAX;
    for (int i = 1; i <= n; ++i) {
        cin >> p >> st;
        if (check(st)) {
            if (p < cost) {
                cost = p;
                ans = i;
            }
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