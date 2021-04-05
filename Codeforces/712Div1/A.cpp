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
string s;

inline void work() {
    cin >> n >> s;
    int cnt1 = 0;
    for (int i = 0; i < n; ++i) {
        cnt1 += (s[i] == '1');
    }
    if (cnt1 % 2 == 1 || s[0] != '1' || s.back() != '1') {
        cout << "NO\n";
    }
    else {
        string p, q;
        int cur = 0, turn = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                ++cur;
                if (cur * 2 <= cnt1) {
                    p.push_back('(');
                    q.push_back('(');
                }
                else {
                    p.push_back(')');
                    q.push_back(')');
                }
            }
            else {
                if (turn == 0) {
                    p.push_back('(');
                    q.push_back(')');
                }
                else {
                    p.push_back(')');
                    q.push_back('(');
                }
                turn ^= 1;
            }
        }
        cout << "YES\n";
        cout << p << "\n";
        cout << q << "\n";
    }
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