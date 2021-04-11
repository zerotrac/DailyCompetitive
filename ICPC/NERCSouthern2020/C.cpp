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

int q, op, x;
unordered_set<int> valid;
priority_queue<pair<int, int>> pq;

inline void work() {
    cin >> q;
    int id = 0;
    int cur = 0;
    for (int i = 1; i <= q; ++i) {
        cin >> op;
        if (op == 1) {
            cin >> x;
            ++id;
            valid.insert(id);
            pq.emplace(x, -id);
        }
        else if (op == 2) {
            while (true) {
                ++cur;
                if (valid.count(cur)) {
                    cout << cur << " ";
                    valid.erase(cur);
                    break;
                }
            }
        }
        else {
            while (true) {
                auto [_, oppid] = pq.top();
                pq.pop();
                oppid = -oppid;
                if (valid.count(oppid)) {
                    cout << oppid << " ";
                    valid.erase(oppid);
                    break;
                }
            }
        }
    }
    cout << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}