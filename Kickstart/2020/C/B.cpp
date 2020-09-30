#include <iostream>
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

int a[31][31];
int g[31][31], indeg[31];
string s;
int m, n;

inline void work() {
    memset(indeg, -1, sizeof(indeg));
    memset(g, 0, sizeof(g));

    cin >> m >> n;
    for (int i = 0; i < m; ++i) {
        cin >> s;
        for (int j = 0; j < n; ++j) {
            a[i][j] = s[j] - 'A';
            indeg[a[i][j]] = 0;
        }
    }
    
    for (int i = 0; i < m - 1; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] != a[i + 1][j]) {
                if (!g[a[i + 1][j]][a[i][j]]) {
                    ++indeg[a[i][j]];
                }
                g[a[i + 1][j]][a[i][j]] = 1;
            }
        }
    }
    
    string ans;
    queue<int> q;
    for (int i = 0; i < 26; ++i) {
        if (!indeg[i]) {
            q.push(i);
        }
        // else if (indeg[i] != -1) {
        //     cout << i << " " << indeg[i] << "\n";
        // }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans.push_back(u + 'A');
        for (int v = 0; v < 26; ++v) {
            if (g[u][v]) {
                --indeg[v];
                if (!indeg[v]) {
                    q.push(v);
                }
            }
        }
    }

    bool fin = true;
    for (int i = 0; i < 26; ++i) {
        if (indeg[i] > 0) {
            fin = false;
            break;
        }
    }

    cout << (fin ? ans : "-1") << "\n";
}

int main() {
    // freopen("B.txt", "r", stdin);
    quickread();
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; ++_) {
        cout << "Case #" << _ << ": ";
        work();
    }
    return 0;
}