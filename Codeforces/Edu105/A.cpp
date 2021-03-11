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

string st;

inline void work() {
    cin >> st;
    unordered_map<char, int> cnt;
    for (char ch: st) {
        ++cnt[ch];
    }

    unordered_map<char, char> rep;
    rep[st[0]] = '(';
    if (st[0] == st.back()) {
        cout << "NO\n";
        return;
    }
    rep[st.back()] = ')';
    char rest = 'A' + 'B' + 'C' - st[0] - st.back();
    if (cnt[rest] != abs(cnt[st[0]] - cnt[st.back()])) {
        cout << "NO\n";
        return;
    }
    rep[rest] = (cnt[st[0]] > cnt[st.back()] ? ')' : '(');

    int cur = 0;
    for (char ch: st) {
        cur = cur + (rep[ch] == '(' ? 1 : -1);
        if (cur < 0) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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