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

inline void doit() {
    unordered_set<int> s;
    int a = 1, b, c;
    while (a < 512) {
        for (b = a + 1; s.count(b) || s.count(a ^ b); ++b);
        c = a ^ b;
        cout << a << " " << b << " " << c << "\n";
        s.insert(a); s.insert(b); s.insert(c);
        while (s.count(a)) {
            ++a;
        }
    }
}

LL n;

inline void work() {
    cin >> n;
    LL group = (n - 1) / 3 + 1;
    LL base = 1;
    while (group > base) {
        group -= base;
        base <<= 2;
    }
    
    LL first = base + group - 1;
    unordered_map<LL, LL> spair = {{0, 0}, {1, 2}, {2, 3}, {3, 1}};
    unordered_map<LL, LL> tpair = {{0, 0}, {1, 3}, {2, 1}, {3, 2}};
    LL second = 0, third = 0;
    for (int i = 0; i < 30; ++i) {
        LL seg = (first >> (i * 2)) & 3;
        second |= (spair[seg] << (i * 2));
        third |= (tpair[seg] << (i * 2));
    }
    int choose = (n - 1) % 3;
    cout << (choose == 0 ? first : (choose == 1 ? second : third)) << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    // doit();
    int T;
    cin >> T;
    while (T--) {
        work();
    }
    return 0;
}