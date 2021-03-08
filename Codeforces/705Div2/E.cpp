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
string l, r;

inline void work() {
    cin >> n >> l >> r;
    if (l[0] == '0' && r[0] == '1') {
        cout << string(n, '1') << '\n';
    }
    else if (r[0] == '0') {
        cout << "0\n";
    }
    else {
        string best = r;
        if (r.back() == '0') {
            string rm2 = r;
            if (rm2[n - 2] == '1') {
                rm2[n - 2] = '0';
            }
            else {
                for (int i = n - 3; i >= 0; --i) {
                    if (rm2[i] == '1') {
                        rm2[i] = '0';
                        for (int j = i + 1; j < n - 1; ++j) {
                            rm2[j] = '1';
                        }
                        break;
                    }
                }
            }
            if (rm2 >= l) {
                best.back() = '1';
            }
        }
        cout << best << '\n';
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}