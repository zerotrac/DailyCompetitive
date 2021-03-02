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

int u, v;

inline bool check() {
    if (u > v) {
        return false;
    }

    vector<int> bitsu, bitsv;
    for (int i = 0; i < 30; ++i) {
        if (u & (1 << i)) {
            bitsu.push_back(i);
        }
        if (v & (1 << i)) {
            bitsv.push_back(i);
        }
    }
    if (bitsu.size() < bitsv.size()) {
        return false;
    }
    for (int i = 0; i < bitsv.size(); ++i) {
        if (bitsu[i] > bitsv[i]) {
            return false;
        }
    }
    return true;
}

inline void work() {
    cin >> u >> v;
    bool c = check();
    cout << (c ? "YES" : "NO") << "\n";    
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