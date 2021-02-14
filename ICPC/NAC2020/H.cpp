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

string a, b, c;

inline vector<int> getFail(const string& a) {
    int n = a.size();
    vector<int> fail(n, -1);
    for (int i = 1; i < n; ++i) {
        int j = fail[i - 1];
        while (j != -1 && a[j + 1] != a[i]) {
            j = fail[j];
        }
        if (a[j + 1] == a[i]) {
            fail[i] = j + 1;
        }
    }
    return fail;
}  

inline int check(const string& a, const string& b, const string& c) {
    // keep a
    // move b
    // kmp match c

    int n = a.size();

    // len(c2) = 2n-1
    string c2 = c + c;
    c2.pop_back();

    int ret = INT_MAX;
    for (int i = 0; i < n; ++i) {
        // the first char of b
        string c_exp;
        bool flag = true;
        for (int j = 0; j < n; ++j) {
            char x = a[j];
            char y = (i + j >= n ? b[i + j - n] : b[i + j]);
            if (x == y) {
                flag = false;
                break;
            }
            char z = 3 - (x - 'A') - (y - 'A') + 'A';
            c_exp.push_back(z);
        }
        if (!flag) {
            continue;
        }

        vector<int> fail = getFail(c_exp);        

        int cost_b = min(i, n - i);
        // try to match c_exp (pattern) in c2=c+c (query)

        int pos = -1;
        for (int j = 0; j < n + n - 1; ++j) {
            while (pos != -1 && c_exp[pos + 1] != c2[j]) {
                pos = fail[pos];
            }
            if (c_exp[pos + 1] == c2[j]) {
                ++pos;
                if (pos == n - 1) {
                    int start_c = j - (n - 1);
                    int cost_c = min(start_c, n - start_c);
                    ret = min(ret, cost_b + cost_c);
                    pos = fail[pos];
                }
            }
        }
    }

    return ret;
}

inline void work() {
    cin >> a >> b >> c;
    int ans = min({check(a, b, c), check(b, a, c), check(c, a, b)});
    if (ans == INT_MAX) {
        ans = -1;
    }
    cout << ans << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}