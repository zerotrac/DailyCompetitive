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

int a[8], b[8], c[15], d[15];
string s;

inline void work() {
    for (int i = 0; i < 8; ++i) {
        cin >> s;
        for (int j = 0; j < 8; ++j) {
            char ch = s[j];
            if (ch == '*') {
                ++a[i];
                ++b[j];
                ++c[i + j];
                ++d[i - j + 7];
            }
        }
    }
    bool check = true;
    for (int i = 0; i < 8; ++i) {
        if (a[i] != 1 || b[i] != 1) {
            check = false;
        }
    }
    for (int i = 0; i < 15; ++i) {
        if (c[i] > 1 || d[i] > 1) {
            check = false;
        }
    }
    cout << (check ? "valid" : "invalid") << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}