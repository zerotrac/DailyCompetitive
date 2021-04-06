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
int a[510];
string s;

inline void work() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<pair<int, int>> choices;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i != j && a[i] > a[j] || (a[i] == a[j] && i < j)) {
                choices.emplace_back(i, j);
            }
        }
    }

    sort(choices.begin(), choices.end(), [&](const auto& u, const auto& v) {
        const auto& [i1, j1] = u;
        const auto& [i2, j2] = v;
        return a[i1] - a[j1] > a[i2] - a[j2];
    });

    for (auto [p, q]: choices) {
        cout << "? " << p << " " << q << endl;
        cin >> s;
        if (s[0] == 'Y') {
            cout << "! " << p << " " << q << endl;
            return;
        }
    }
    cout << "! 0 0" << endl;
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}