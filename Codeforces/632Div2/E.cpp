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

inline void guess() {
    vector<int> perm(9);
    iota(perm.begin(), perm.end(), 0);
    vector<vector<int>> rook = {
        {1, 1, 1, 1, 0, 0, 1, 0, 0},
        {1, 1, 1, 0, 1, 0, 0, 1, 0},
        {1, 1, 1, 0, 0, 1, 0, 0, 1},
        {1, 0, 0, 1, 1, 1, 1, 0, 0},
        {0, 1, 0, 1, 1, 1, 0, 1, 0},
        {0, 0, 1, 1, 1, 1, 0, 0, 1},
        {1, 0, 0, 1, 0, 0, 1, 1, 1},
        {0, 1, 0, 0, 1, 0, 1, 1, 1},
        {0, 0, 1, 0, 0, 1, 1, 1, 1}
    };
    vector<vector<int>> queen = {
        {1, 1, 1, 1, 1, 0, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 0, 1, 0},
        {1, 1, 1, 0, 1, 1, 1, 0, 1},
        {1, 1, 0, 1, 1, 1, 1, 1, 0},
        {1, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 1, 1, 1, 1, 1, 0, 1, 1},
        {1, 0, 1, 1, 1, 0, 1, 1, 1},
        {0, 1, 0, 1, 1, 1, 1, 1, 1},
        {1, 0, 1, 0, 1, 1, 1, 1, 1}
    };

    auto checkstep = [](const vector<vector<int>>& g, const vector<int>& perm) -> int {
        bool visited[9];
        memset(visited, false, sizeof(visited));
        int rest = 9;
        for (int step = 0;; ++step) {
            int pos = 0, mx = 100;
            for (int i = 0; i < 9; ++i) {
                if (!visited[i] && perm[i] < mx) {
                    mx = perm[i];
                    pos = i;
                }
            }
            visited[pos] = true;
            --rest;
            while (pos != -1) {
                int nxt = -1, mx = 100;
                for (int i = 0; i < 9; ++i) {
                    if (!visited[i] && g[pos][i] && perm[i] < mx) {
                        mx = perm[i];
                        nxt = i;
                    }
                }
                if (nxt != -1) {
                    visited[nxt] = true;
                    --rest;
                }
                pos = nxt;
            }
            if (!rest) {
                return step;
            }
        }
    };

    do {
        int rook_step = checkstep(rook, perm);
        int queen_step = checkstep(queen, perm);
        // for (int i = 0; i < 9; ++i) cout << perm[i] + 1 << " "; cout << "\n";
        if (rook_step < queen_step && perm[6] == 0) {
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    cout << perm[i * 3 + j] + 1 << " ";
                }
                cout << "\n";
            }
            break;
        }
    } while (next_permutation(perm.begin(), perm.end()));
}

int a[510][510];
int n;

inline void work() {
    // guess();
    /*
     * 2 3 5
     * 7 4 8
     * 1 6 9
     */
    cin >> n;
    if (n < 3) {
        cout << "-1\n";
        return;
    }
    vector<vector<int>> v = {
        {2, 3, 5},
        {7, 4, 8},
        {1, 6, 9}
    };
    if (n & 1) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < i; ++j) {
                swap(v[i][j], v[j][i]);
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n - 3; ++i) {
        if (i & 1) {
            for (int j = n; j >= i; --j) {
                a[i][j] = ++cnt;
            }
            for (int j = i + 1; j <= n; ++j) {
                a[j][i] = ++cnt;
            }
        }
        else {
            for (int j = n; j >= i + 1; --j) {
                a[j][i] = ++cnt;
            }
            for (int j = i; j <= n; ++j) {
                a[i][j] = ++cnt;
            }
        }
    }
    for (int i = n - 2; i <= n; ++i) {
        for (int j = n - 2; j <= n; ++j) {
            a[i][j] = v[i - n + 2][j - n + 2] + n * n - 9;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}