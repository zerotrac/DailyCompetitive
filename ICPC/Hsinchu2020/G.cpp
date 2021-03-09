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

int n, k, x, y;
static constexpr LL base0 = 800000011;
static constexpr LL base1 = 800000027;
static constexpr LL base2 = 800000029;
static constexpr LL base3 = 800000041;
static constexpr LL mod0 = 800000083LL * 800000087LL;
static constexpr LL mod1 = 800000107LL * 800000147LL;
static constexpr LL mod2 = 800000153LL * 800000171LL;
static constexpr LL mod3 = 800000209LL * 800000233LL;
LL strange[1000010];

inline void init() {
    strange[0] = 1;
    for (int i = 1; i <= 1000000; ++i) {
        strange[i] = strange[i - 1] * base0 % mod0;
    }
}

inline vector<LL> minrep(const vector<LL>& v) {
    int n = v.size();
    int i = 0, j = 1, k = 0;
    while (i < n && j < n && k < n) {
        if (v[(i + k) % n] == v[(j + k) % n]) {
            ++k;
        }
        else if (v[(i + k) % n] < v[(j + k) % n]) {
            j += k + 1;
            if (i == j) {
                ++j;
            }
            k = 0;
        }
        else {
            i += k + 1;
            if (i == j) {
                ++i;
            }
            k = 0;
        }
    }
    int start = (k == n ? i : (i < n ? i : j));
    vector<LL> ret;
    for (int i = 0; i < n; ++i) {
        ret.push_back(v[(start + i) % n]);
    }
    return ret;
}

// node count + inner cycle count + hash value1 + hash value2
inline tuple<int, int, LL, LL> hashall() {
    cin >> k;
    vector<vector<int>> edges(k);
    vector<int> indeg(k);
    vector<int> dep(k, 1);
    vector<LL> hashv(k);
    for (int i = 1; i <= k; ++i) {
        cin >> x >> y;
        --x;
        --y;
        edges[x].push_back(y);
        edges[y].push_back(x);
        ++indeg[x];
        ++indeg[y];
    }

    queue<int> q;
    for (int i = 0; i < k; ++i) {
        if (indeg[i] == 1) {
            q.push(i);
        }
    }

    auto get_hash_value = [&](const vector<LL>& v, LL bb, LL mm) {
        int ret = 0;
        for (int o: v) {
            ret = (ret * bb + o) % mm;
        }
        return ret;
    };

    vector<vector<LL>> hash_child(k);
    vector<vector<LL>> dep_child(k);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        hash_child[u].push_back(strange[dep[u]]);
        if (!dep_child[u].empty()) {
            sort(dep_child[u].begin(), dep_child[u].end());
            hash_child[u].push_back(get_hash_value(dep_child[u], base1, mod1));
        }
        if (!dep_child[u].empty()) {
            for (int dd: dep_child[u]) {
                hash_child[u].push_back(strange[dd]);
            }
        }
        sort(hash_child[u].begin(), hash_child[u].end());
        hashv[u] = get_hash_value(hash_child[u], base2, mod2);
        for (int v: edges[u]) {
            if (indeg[v] != 1) {
                --indeg[v];
                dep[v] = max(dep[v], dep[u] + 1);
                dep_child[v].push_back(dep[u]);
                hash_child[v].push_back(hashv[u]);
                if (indeg[v] == 1) {
                    q.push(v);
                }
            }
        }
    }

    int circ_first = -1;
    for (int u = 0; u < k; ++u) {
        if (indeg[u] == 2) {
            if (circ_first == -1) {
                circ_first = u;
            }
            hash_child[u].push_back(strange[dep[u]]);
            if (!dep_child[u].empty()) {
                sort(dep_child[u].begin(), dep_child[u].end());
                hash_child[u].push_back(get_hash_value(dep_child[u], base1, mod1));
            }
            if (!dep_child[u].empty()) {
                for (int dd: dep_child[u]) {
                    hash_child[u].push_back(strange[dd]);
                }
            }
            sort(hash_child[u].begin(), hash_child[u].end());
            hashv[u] = get_hash_value(hash_child[u], base2, mod2);
        }
    }

    vector<int> circ = {circ_first};
    while (true) {
        int u = circ.back();
        bool found = false;
        for (int v: edges[u]) {
            if (v != circ_first && indeg[v] == 2) {
                if (circ.size() == 1 || circ[circ.size() - 2] != v) {
                    circ.push_back(v);
                    found = true;
                    break;
                }
            }
        }
        if (!found) {
            break;
        }
    }

    int m = circ.size();
    vector<LL> circ_hash1 = {hashv[circ_first]}, circ_hash2 = {hashv[circ_first]};
    for (int i = 1; i < m; ++i) {
        circ_hash1.push_back(hashv[circ[i]]);
        circ_hash2.push_back(hashv[circ[m - i]]);
    }
    
    circ_hash1 = minrep(circ_hash1);
    circ_hash2 = minrep(circ_hash2);
    LL h1 = get_hash_value(circ_hash1, base3, mod3);
    LL h2 = get_hash_value(circ_hash2, base3, mod3);
    if (h1 > h2) {
        swap(h1, h2);
    }

    return {k, m, h1, h2};
}

inline void work() {
    cin >> n;
    vector<tuple<int, int, LL, LL>> v;
    for (int i = 0; i < n; ++i) {
        auto [p, q, r, s] = hashall();
        v.emplace_back(p, q, r, s);
    }
    sort(v.begin(), v.end());
    int ans = 1;
    for (int i = 1; i < n; ++i) {
        if (v[i] != v[i - 1]) {
            ++ans;
        }
    }
    cout << ans << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    init();
    quickread();
    int T;
    cin >> T;
    while (T--) {
        work();
    }
    return 0;
}