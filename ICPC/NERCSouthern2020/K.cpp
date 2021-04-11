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

string s;

inline bool check(int obsx, int obsy) {
    int x = 0, y = 0;
    for (int ch: s) {
        if (ch == 'L') {
            --x;
        }
        else if (ch == 'R') {
            ++x;
        }
        else if (ch == 'D') {
            --y;
        }
        else {
            ++y;
        }
        if (x == obsx && y == obsy) {
            if (ch == 'L') {
                ++x;
            }
            else if (ch == 'R') {
                --x;
            }
            else if (ch == 'D') {
                ++y;
            }
            else {
                --y;
            }
        }
    }
    return x == 0 && y == 0;
}

inline void work() {
    cin >> s;
    int x = 0, y = 0;
    vector<pair<int, int>> pos;
    for (int ch: s) {
        if (ch == 'L') {
            --x;
        }
        else if (ch == 'R') {
            ++x;
        }
        else if (ch == 'D') {
            --y;
        }
        else {
            ++y;
        }
        if (!(x == 0 && y == 0)) {
            pos.emplace_back(x, y);
        }
    }
    sort(pos.begin(), pos.end());
    pos.erase(unique(pos.begin(), pos.end()), pos.end());
    for (const auto& [obsx, obsy]: pos) {
        if (check(obsx, obsy)) {
            cout << obsx << " " << obsy << "\n";
            return;
        }
    }
    cout << "0 0\n";
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