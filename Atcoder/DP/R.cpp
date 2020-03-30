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
const int mod = 1e9 + 7;
// const int mod = 998244353;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

struct Matrix {
    int** g;
    int N;

    Matrix(int _N) {
        N = _N;
        g = new int*[N];
        for (int i = 0; i < N; ++i) {
            g[i] = new int[N];
            for (int j = 0; j < N; ++j) {
                g[i][j] = (i == j);
            }
        }
    }

    Matrix(const Matrix& that) {
        N = that.N;
        g = new int*[N];
        for (int i = 0; i < N; ++i) {
            g[i] = new int[N];
            for (int j = 0; j < N; ++j) {
                g[i][j] = that.g[i][j];
            }
        }
    }
    
    Matrix(Matrix&& that) {
        N = that.N;
        g = that.g;
    }

    ~Matrix() {
        for (int i = 0; i < N; ++i) {
            delete[] g[i];
        }
        delete[] g;
    }

    Matrix& operator= (const Matrix& that) {
        if (this != &that) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    g[i][j] = that.g[i][j];
                }
            }
        }
        return *this;
    }

    Matrix& operator*= (const Matrix& that) {
        int tmp[N][N];
        memset(tmp, 0, sizeof(tmp));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                for (int k = 0; k < N; ++k) {
                    tmp[i][j] += (LL)g[i][k] * that.g[k][j] % mod;
                    tmp[i][j] %= mod;
                }
            }
        }
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                g[i][j] = tmp[i][j];
            }
        }
        return *this;
    }
};

int n;
LL k;

Matrix quickmul(const Matrix& g, LL y) {
    Matrix ret(n), mul = g;
    while (y) {
        if (y & 1) {
            ret *= mul;
        }
        mul *= mul;
        y >>= 1;
    }
    return ret;
}

inline void work() {
    cin >> n >> k;
    Matrix m(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> m.g[i][j];
        }
    }
    m = quickmul(m, k);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ans += m.g[i][j];
            ans %= mod;
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