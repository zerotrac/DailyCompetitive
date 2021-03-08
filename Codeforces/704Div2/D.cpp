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

int a, b, k;

inline void work() {
    cin >> a >> b >> k;
    if (k == 0) {
        cout << "Yes\n";
        cout << string(b, '1') + string(a, '0') << "\n";
        cout << string(b, '1') + string(a, '0') << "\n";
    }
    else {
        if (!a) {
            cout << "No\n";
            return;
        }

        int sa = a - 1, sb = b;
        int ta = a, tb = b - 1;
        string s = "0", t = "1";
        for (int i = 2; i <= k; ++i) {
            if (sa > 0 && ta > 0) {
                --sa;
                --ta;
                s += '0';
                t += '0';
            }
            else if (sb > 0 && tb > 0) {
                --sb;
                --tb;
                s += '1';
                t += '1';
            }
            else {
                cout << "No\n";
                return;
            }
        }
        if (!sb || !ta) {
            cout << "No\n";
            return;
        }
        --sb;
        --ta;
        s += '1';
        t += '0';
        if (!sb) {
            cout << "No\n";
            return;
        }
        for (int i = 0; i < sa; ++i) {
            s += '0';
            t += '0';
        }
        for (int i = 0; i < sb; ++i) {
            s += '1';
            t += '1';
        }
        
        reverse(s.begin(), s.end());
        reverse(t.begin(), t.end());
        cout << "Yes\n";
        cout << s << "\n";
        cout << t << "\n";
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}