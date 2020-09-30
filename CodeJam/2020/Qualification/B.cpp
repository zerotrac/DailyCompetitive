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

string st;

inline void work() {
    cin >> st;
    int dep = 0;
    for (char ch: st) {
        if (dep < ch - 48) {
            for (int i = 0; i < ch - 48 - dep; ++i) {
                cout << "(";
            }
        }
        else {
            for (int i = 0; i < dep - ch + 48; ++i) {
                cout << ")";
            }
        }
        cout << ch;
        dep = ch - 48;
    }
    for (int i = 0; i < dep; ++i) {
        cout << ")";
    }
    cout << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; ++_) {
        cout << "Case #" << _ << ": ";
        work();
    }
    return 0;
}