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
string a[110];

inline void work() {
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 2; i <= n; ++i) {
        if (a[i].size() > a[i - 1].size() || (a[i].size() == a[i - 1].size() && a[i] > a[i - 1])) {
            continue;
        }
        else {
            int lp = a[i - 1].size();
            int lq = a[i].size();
            // lp >= lq
            if (lp == lq) {
                ++ans;
                a[i].push_back('0');
            }
            else {
                string u = a[i - 1];
                for (int _ = 0; _ < lp - lq; ++_) {
                    u.pop_back();
                }
                if (u < a[i]) {
                    ans += lp - lq;
                    for (int _ = 0; _ < lp - lq; ++_) {
                        a[i].push_back('0');
                    }
                }
                else if (u == a[i]) {
                    int pos = -1;
                    for (int j = lp - 1; j >= lq; --j) {
                        if (a[i - 1][j] != '9') {
                            pos = j;
                            break;
                        }
                    }
                    if (pos != -1) {
                        ans += lp - lq;
                        string dum = a[i - 1];
                        ++dum[pos];
                        for (int j = pos + 1; j < lp; ++j) {
                            dum[j] = '0';
                        }
                        a[i] = move(dum);
                    }
                    else {
                        ans += lp - lq + 1;
                        for (int _ = 0; _ <= lp - lq; ++_) {
                            a[i].push_back('0');
                        }
                    }
                }
                else {
                    ans += lp - lq + 1;
                    for (int _ = 0; _ <= lp - lq; ++_) {
                        a[i].push_back('0');
                    }
                }
            }
        }
    }
    cout << ans << "\n";
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