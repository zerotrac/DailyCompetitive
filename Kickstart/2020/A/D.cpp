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

int trie[3000010][26], cnt[3000010];
int N, K, tcnt = 0;
int ans = 0;
string st;

void dfs(int x) {
    if (!x) {
        return;
    }
    ans += cnt[x] / K;
    for (int i = 0; i < 26; ++i) {
        dfs(trie[x][i]);
    }
}

inline void work() {
    cin >> N >> K;
    int root = ++tcnt;
    for (int i = 0; i < N; ++i) {
        cin >> st;
        int node = root;
        for (char ch: st) {
            if (!trie[node][ch - 65]) {
                trie[node][ch - 65] = ++tcnt;
            }
            node = trie[node][ch - 65];
            ++cnt[node];
        }
    }

    ans = 0;
    dfs(root);
    cout << ans << "\n";
}

int main() {
    // freopen("D.txt", "r", stdin);
    quickread();
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; ++_) {
        cout << "Case #" << _ << ": ";
        work();
    }
    return 0;
}