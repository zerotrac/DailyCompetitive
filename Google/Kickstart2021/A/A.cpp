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

int n, k;
string st;

inline void work() {
    cin >> n >> k >> st;
    int cnt = 0;
    for (int i = 0, j = st.size() - 1; i < j; ++i, --j) {
        if (st[i] != st[j]) {
            ++cnt;
        }
    }
    cout << abs(k - cnt) << "\n";
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