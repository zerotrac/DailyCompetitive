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

string s;

inline void work() {
    cin >> s;
    int n = s.size();
    int l = -1;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == '0' && s[i + 1] == '0') {
            l = i + 1;
        }
    }
    int r = n - 1;
    for (int i = n - 2; i >= 0; --i) {
        if (s[i] == '1' && s[i + 1] == '1') {
            r = i - 1;
        }
    }
    cout << (l <= r ? "YES" : "NO") << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    int T;
    cin >> T;
    while (T--) {
        work();
    }
    return 0;
}