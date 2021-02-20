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

int n, m, st, ed;
int a, b;
LL t, k;

vector<vector<tuple<int, LL, LL>>> edges;

inline void work() {
    cin >> n >> m >> st >> ed;
    edges.resize(n + 1);
    for (int i = 1; i <= m; ++i) {
        cin >> a >> b >> t >> k;
        edges[a].emplace_back(b, t, k);
        edges[b].emplace_back(a, t, k);
    }

    priority_queue<pair<LL, int>, vector<pair<LL, int>>, greater<pair<LL, int>>> q;
    q.emplace(0, st);

    vector<LL> dist(n + 1, LLONG_MAX / 2);
    dist[0] = 0;
    vector<int> used(n + 1);

    while (!q.empty()) {
        auto [d, u] = q.top();
        q.pop();
        if (used[u]) {
            continue;
        }
        used[u] = true;
        for (const auto& [v, tt, kk]: edges[u]) {
            LL timestamp = (d % kk == 0 ? d : (d / kk + 1) * kk) + tt;
            if (timestamp < dist[v]) {
                dist[v] = timestamp;
                q.emplace(timestamp, v);
            }
        }
    }

    cout << (dist[ed] == LLONG_MAX / 2 ? -1 : dist[ed]) << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}