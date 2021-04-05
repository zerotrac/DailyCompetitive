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

int n, x;
int a[110][110];

inline void work() {
    cin >> n;
    queue<pair<int, int>> black, white;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if ((i + j) % 2 == 0) {
                black.emplace(i, j);
            }
            else {
                white.emplace(i, j);
            }
        }
    }
    int bcolor, wcolor;
    for (int i = 1; i <= n * n; ++i) {
        cin >> x;
        if (i == 1) {
            if (x == 1) {
                bcolor = 2;
                wcolor = 3;
            }
            else if (x == 2) {
                bcolor = 1;
                wcolor = 3;
            }
            else {
                bcolor = 2;
                wcolor = 3;
            }
        }
        if (!black.empty() && (white.empty() || x != bcolor)) {
            // put on black
            auto [xx, yy] = black.front();
            black.pop();
            if (x != bcolor) {
                cout << bcolor << " " << xx << " " << yy << endl;
            }
            else {
                cout << 6 - bcolor - wcolor << " " << xx << " " << yy << endl;
            }
        }
        else {
            // put on white
            auto [xx, yy] = white.front();
            white.pop();
            if (x != wcolor) {
                cout << wcolor << " " << xx << " " << yy << endl;
            }
            else {
                cout << 6 - bcolor - wcolor << " " << xx << " " << yy << endl;
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