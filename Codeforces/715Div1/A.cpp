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
string a, b, c;

inline void work() {
    cin >> n >> a >> b >> c;
    int ptra = 0, ptrb = 0, ptrc = 0;
    string ans;
    while (ptra < n * 2 && ptrb < n * 2 && ptrc < n * 2) {
        int cnt0 = (a[ptra] == '0') + (b[ptrb] == '0') + (c[ptrc] == '0');
        int cnt1 = (a[ptra] == '1') + (b[ptrb] == '1') + (c[ptrc] == '1');
        if (cnt0 > cnt1) {
            ans.push_back('0');
            if (a[ptra] == '0') {
                ++ptra;
            }
            if (b[ptrb] == '0') {
                ++ptrb;
            }
            if (c[ptrc] == '0') {
                ++ptrc;
            }
        }
        else {
            ans.push_back('1');
            if (a[ptra] == '1') {
                ++ptra;
            }
            if (b[ptrb] == '1') {
                ++ptrb;
            }
            if (c[ptrc] == '1') {
                ++ptrc;
            }
        }
    }
    if (ptra == n * 2) {
        ans += (ptrb > ptrc ? b.substr(ptrb, n * 2) : c.substr(ptrc, n * 2));
    }
    else if (ptrb == n * 2) {
        ans += (ptra > ptrc ? a.substr(ptra, n * 2) : c.substr(ptrc, n * 2));
    }
    else {
        ans += (ptra > ptrb ? a.substr(ptra, n * 2) : b.substr(ptrb, n * 2));
    }
    cout << ans << "\n";
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