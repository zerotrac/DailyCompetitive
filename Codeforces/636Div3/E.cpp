#include <iostream>
#include <iomanip>
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

int head[200010], edge[600010], nxt[600010];
LL w[200010];
int m, n, a, b, c, x, y;
int ecnt = 0;

inline void addedge(int x, int y) {
    ++ecnt;
    edge[ecnt] = y;
    nxt[ecnt] = head[x];
    head[x] = ecnt;
}

vector<int> bfs(int start) {
    vector<int> dist(n + 1, INT_MAX);
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i; i = nxt[i]) {
            int v = edge[i];
            if (dist[v] == INT_MAX) {
                q.push(v);
                dist[v] = dist[u] + 1;
            }
        }
    }
    return dist;
}

inline void work() {
    cin >> n >> m >> a >> b >> c;
    memset(head, 0, sizeof(int) * (n + 1));
    for (int i = 1; i <= m; ++i) {
        cin >> w[i];
    }
    sort(w + 1, w + m + 1);
    for (int i = 2; i <= m; ++i) {
        w[i] += w[i - 1];
    }
    for (int i = 1; i <= m; ++i) {
        cin >> x >> y;
        addedge(x, y);
        addedge(y, x);
    }

    vector<int> ans_a = bfs(a);
    vector<int> ans_b = bfs(b);
    vector<int> ans_c = bfs(c);
    LL ans = LLONG_MAX;
    for (int i = 1; i <= n; ++i) {
        int da = ans_a[i], db = ans_b[i], dc = ans_c[i];
        if (da + db + dc <= m) {
            ans = min(ans, w[da + db + dc] + w[db]);
        }
    }
    cout << ans << "\n";
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
