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
int a[100010], l[100010], r[100010], valid[100010];

inline void work() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        l[i] = (i == 1 ? n : i - 1);
        r[i] = (i == n ? 1 : i + 1);
        valid[i] = 1;
    }

    priority_queue<LL, vector<LL>, greater<LL>> q;
    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
        q.push(i);
    }

    while (!q.empty()) {
        LL base = q.top();
        int u = (q.top() - 1) % n + 1;
        q.pop();
        if (!valid[u]) {
            continue;
        }
        int v = r[u];
        if (gcd(a[u], a[v]) == 1) {
            valid[v] = false;
            ans.push_back(v);
            r[l[v]] = r[v];
            l[r[v]] = l[v];
            q.push(base + n);
        }
    }


    cout << ans.size();
    for (int o: ans) {
        cout << " " << o;
    }
    cout << "\n";
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