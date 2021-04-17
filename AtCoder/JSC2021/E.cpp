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
#include <array>
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

class UF {
public:
    int n;
    int comp_cnt;
    vector<int> fa;
    vector<int> sz;
    vector<array<int, 26>> alph;
    
public:
    UF(int _n): n(_n), comp_cnt(_n), fa(_n), sz(_n, 1), alph(_n) {
        iota(fa.begin(), fa.end(), 0);
    }
    
    int findset(int x) {
        return fa[x] == x ? x : fa[x] = findset(fa[x]);
    }
    
    bool unite(int x, int y) {
        x = findset(x);
        y = findset(y);
        if (x == y) {
            return false;
        }
        if (x > y) {
            swap(x, y);
        }
        fa[y] = x;
        sz[x] += sz[y];
        for (int i = 0; i < 26; ++i) {
            alph[x][i] += alph[y][i];
        }
        --comp_cnt;
        return true;
    }
    
    bool connected(int x, int y) {
        x = findset(x);
        y = findset(y);
        return x == y;
    }
};

int k;
string s;

inline void work() {
    cin >> k >> s;
    int n = s.size(), r = n - 1;
    
    UF uf(n);
    for (int i = 0; i < n; ++i) {
        ++uf.alph[i][s[i] - 'a'];
    }

    for (int level = k; level >= 1; --level) {
        if (r == -1) {
            cout << "impossible\n";
            return;
        }
        // 0~r
        for (int i = 0, j = r; i < j; ++i, --j) {
            uf.unite(i, j);
        }
        if (r % 2 == 0) {
            r = r / 2 - 1;
        }
        else {
            r = r / 2;
        }
    }

    int ans = 0;

    // level 0 is 0~r
    if (r == 0) {
        cout << "impossible\n";
        return;
    }
    if (r != -1) {
        vector<int> fst(r + 1, -1), snd(r + 1, -1);
        for (int i = 0; i <= r; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (fst[i] == -1 || uf.alph[i][j] > uf.alph[i][fst[i]]) {
                    snd[i] = fst[i];
                    fst[i] = j;
                }
                else if (snd[i] == -1 || uf.alph[i][j] > uf.alph[i][snd[i]]) {
                    snd[i] = j;
                }
            }
        }

        bool check = false;
        for (int i = 0, j = r; i < j; ++i, --j) {
            if (fst[i] != fst[j]) {
                check = true;
                break;
            }
        }
        if (!check) {
            int best = 0;
            for (int i = 1; i <= r; ++i) {
                if (r % 2 == 0 && i * 2 == r) {
                    continue;
                }
                if (uf.alph[i][fst[i]] - uf.alph[i][snd[i]] < uf.alph[best][fst[best]] - uf.alph[best][snd[best]]) {
                    best = i;
                }
            }
            swap(fst[best], snd[best]);
        }
        for (int i = 0; i <= r; ++i) {
            ans += uf.sz[i] - uf.alph[i][fst[i]];
        }
    }

    for (int i = r + 1; i < n; ++i) {
        if (uf.findset(i) == i) {
            int best = 0;
            for (int j = 0; j < 26; ++j) {
                best = max(best, uf.alph[i][j]);
            }
            ans += uf.sz[i] - best;
        }
    }
    cout << ans << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}