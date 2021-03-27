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

vector<int> edges[1001][26];
int dist[1001][1001];
int n, m, x, y;
string st;

inline void work() {
    cin >> n >> m;
    memset(dist, -1, sizeof(dist));

    queue<pair<int, int>> q;
    for (int i = 1; i <= n; ++i) {
        dist[i][i] = 0;
        q.emplace(i, i);
    }
    for (int i = 1; i <= m; ++i) {
        cin >> x >> y >> st;
        int z = st[0] - 'a';
        edges[x][z].push_back(y);
        edges[y][z].push_back(x);
        if (x != y) {
            dist[x][y] = dist[y][x] = 1;
        }
        q.emplace(x, y);
    }

    while (!q.empty()) {
        auto [u, v] = q.front();
        q.pop();
        for (int j = 0; j < 26; ++j) {
            if (!edges[u][j].empty() && !edges[v][j].empty()) {
                for (int u1: edges[u][j]) {
                    for (int v1: edges[v][j]) {
                        if (dist[u1][v1] == -1) {
                            dist[u1][v1] = dist[v1][u1] = dist[u][v] + 2;
                            q.emplace(u1, v1);
                        }
                    }
                }
            }
        }
    }

    cout << dist[1][n] << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}