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

string x;
LL m;

inline void work() {
    cin >> x >> m;
    if (x.size() == 1) {
        int xx = stoi(x);
        cout << ((xx <= m) ? 1 : 0) << endl;
    }
    else {
        LL base = (*max_element(x.begin(), x.end())) - '0' + 1;
        LL l = base;
        LL r = m;
        LL ans = base - 1;
        while (l <= r) {
            LL mid = (l + r) / 2;
            LL num = 0;
            bool check = true;
            for (char ch: x) {
                if ((ch - '0') > m || num > (m - (ch - '0')) / mid) {
                    check = false;
                    break;
                }
                num = num * mid + (ch - '0');
            }
            if (check) {
                ans = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        cout << ans - base + 1 << "\n";
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}