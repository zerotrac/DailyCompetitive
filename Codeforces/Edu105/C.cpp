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

int n, m, x;

inline int get(const vector<int>& box, const vector<int>& spec) {
    if (box.empty() || spec.empty()) {
        return 0;
    }
    
    int n = box.size();
    int m = spec.size();

    unordered_set<int> m_spec(spec.begin(), spec.end());
    vector<int> extra(n);
    for (int i = n - 1; i >= 0; --i) {
        extra[i] = (i == n - 1 ? 0 : extra[i + 1]) + m_spec.count(box[i]);
    }

    int ans = extra[0];
    int j = 0;
    while (j < m && spec[j] < box[0]) {
        ++j;
    }
    for (int i = 0; i < n && j < m; ++i) {
        int limit = (i == n - 1 ? INT_MAX : box[i + 1] - 1);
        while (j < m && spec[j] <= limit) {
            int it = lower_bound(spec.begin(), spec.end(), spec[j] - i) - spec.begin();
            ans = max(ans, (j - it + 1) + (i != n - 1 ? extra[i + 1] : 0));
            ++j;
        }
    }
    
    return ans;
}

inline void work() {
    cin >> n >> m;
    vector<int> boxl, boxr;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        if (x < 0) {
            boxl.push_back(-x);
        }
        else {
            boxr.push_back(x);
        }
    }
    vector<int> specl, specr;
    for (int i = 1; i <= m; ++i) {
        cin >> x;
        if (x < 0) {
            specl.push_back(-x);
        }
        else {
            specr.push_back(x);
        }
    }

    reverse(boxl.begin(), boxl.end());
    reverse(specl.begin(), specl.end());
    cout << get(boxl, specl) + get(boxr, specr) << "\n";
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