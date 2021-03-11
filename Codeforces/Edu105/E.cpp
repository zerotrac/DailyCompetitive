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

int n, q, x, y;
string st;

static constexpr LL base = 1 << 20;

inline LL enc(int x, int y) {
    return base * x + y;
}

inline pair<int, int> dec(LL u) {
    return {u / base, u % base};
}

inline void work() {
    cin >> n >> q;
    int rev_cnt = 0, same_cnt = 0;
    unordered_map<LL, char> s;
    for (int i = 1; i <= q; ++i) {
        cin >> st;
        if (st[0] == '+') {
            cin >> x >> y >> st;
            LL u = enc(x, y), v = enc(y, x);
            s[u] = st[0];
            if (s.count(v)) {
                ++rev_cnt;
                if (s[u] == s[v]) {
                    ++same_cnt;
                }
            }
        }
        else if (st[0] == '-') {
            cin >> x >> y;
            LL u = enc(x, y), v = enc(y, x);
            if (s.count(v)) {
                --rev_cnt;
                if (s[u] == s[v]) {
                    --same_cnt;
                }
            }
            s.erase(u);
        }
        else {
            cin >> x;
            if (x & 1) {
                cout << (rev_cnt ? "YES" : "NO") << "\n";
            }
            else {
                cout << (same_cnt ? "YES" : "NO") << "\n";
            }
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}