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
LL dist, u;
static constexpr int BOUND = 1000000;

inline void work() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cout << "0 0" << endl;
        cin >> dist;
        if (dist == 0) {
            continue;
        }
        for (LL dx = 0; dx * dx * 2 <= dist && dx <= BOUND; ++dx) {
            LL dy2 = dist - dx * dx;
            LL dy = int(sqrt(dy2) + 0.5);
            if (dy * dy != dy2 || dy > BOUND) {
                continue;
            }
            cout << dx << " " << dy << endl;
            cin >> u;
            if (u == 0) {
                break;
            }
            if (dx != dy) {
                cout << dy << " " << dx << endl;
                cin >> u;
                if (u == 0) {
                    break;
                }
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