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

class SuffixArraySimple {
public:
    vector<int> sa, rank;
    string st;
 
public:
    SuffixArraySimple(const string& st_): st{st_}, sa(st_.size()), rank(st_.size()) {
        int n = st.size();
        vector<pair<pair<int, int>, int>> v(n);
        for (int i = 0; i < n; ++i) {
            v[i] = {{st[i], -1}, i};
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < n; ++i) {
            sa[i] = v[i].second;
            rank[sa[i]] = (i ? (v[i - 1].first == v[i].first ? rank[sa[i - 1]] : rank[sa[i - 1]] + 1) : 0);
        }
        for (int k = 0; (1 << k) < n; ++k) {
            for (int i = 0; i < n; ++i) {
                v[i] = {{rank[i], (i + (1 << k) < n ? rank[i + (1 << k)] : -1)}, i};
            }
            sort(v.begin(), v.end());
            for (int i = 0; i < n; ++i) {
                sa[i] = v[i].second;
                rank[sa[i]] = (i ? (v[i - 1].first == v[i].first ? rank[sa[i - 1]] : rank[sa[i - 1]] + 1) : 0);
            }
        }
    }
};

string st;

inline void work() {
    cin >> st;
    SuffixArraySimple o{st};
    cout << st.size();
    for (int x: o.sa) {
        cout << " " << x;
    }
    cout << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}
