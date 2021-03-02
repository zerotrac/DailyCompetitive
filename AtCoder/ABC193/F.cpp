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

#include <atcoder/maxflow>

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
int g[110][110];
string s;

inline void work() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> s;
        for (int j = 1; j <= n; ++j) {
            if (s[j - 1] == 'B') {
                g[i][j] = 1;
            }
            else if (s[j - 1] == 'W') {
                g[i][j] = -1;
            }
            if ((i + j) & 1) {
                g[i][j] = -g[i][j];
            }
        }
    }

    atcoder::mf_graph<int> graph(n * n + 2);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int idx = (i - 1) * n + j - 1;
            if (i + 1 <= n) {
                graph.add_edge(idx, idx + n, 1);
            }
            if (i - 1 > 0) {
                graph.add_edge(idx, idx - n, 1);
            }
            if (j + 1 <= n) {
                graph.add_edge(idx, idx + 1, 1);
            }
            if (j - 1 > 0) {
                graph.add_edge(idx, idx - 1, 1);
            }
            if (g[i][j] == 1) {
                graph.add_edge(n * n, idx, INT_MAX);
            }
            if (g[i][j] == -1) {
                graph.add_edge(idx, n * n + 1, INT_MAX);
            }
        }
    }

    int min_cut = graph.flow(n * n, n * n + 1);
    cout << 2 * (n - 1) * n - min_cut << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}