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

template<int M>
class Modint {
private:
    static int quickmul(int x, int y) {
        int ret = 1, mul = x;
        while (y) {
            if (y & 1) {
                ret = (LL)ret * mul % M;
            }
            mul = (LL)mul * mul % M;
            y >>= 1;
        }
        return ret;
    }

public:
    Modint(): x_(0) {}
    Modint(int x): x_(x > 0 ? x % M : (x % M + M) % M) {}
    Modint(const Modint& that) { x_ = that.x_; }
    Modint(Modint&& that) { x_ = that.x_; }

    int get() const { return x_; }

    Modint neg() const { return -x_; }

    Modint& operator= (const Modint& that) { if (this != &that) x_ = that.x_; return *this; }
    Modint& operator= (Modint&& that) { if (this != &that) x_ = that.x_; return *this; }

    Modint& operator+= (const Modint& that) { x_ += that.x_; if (x_ >= M) x_ -= M; return *this; }
    Modint& operator-= (const Modint& that) { x_ -= that.x_; if (x_ < 0) x_ += M; return *this; }
    Modint& operator*= (const Modint& that) { x_ = (LL)x_ * that.x_ % M; return *this; }
    Modint& operator/= (const Modint& that) { x_ = (LL)x_ * quickmul(that.x_, M - 2) % M; return *this; }

    bool operator== (const Modint& that) const { return x_ == that.x_; }
    bool operator!= (const Modint& that) const { return x_ != that.x_; }
    bool operator< (const Modint& that) const { return x_ < that.x_; }
    bool operator> (const Modint& that) const { return x_ > that.x_; }

    template<int U>
    friend Modint<U> operator+ (const Modint<U>& u, const Modint<U>& v);
    template<int U>
    friend Modint<U> operator- (const Modint<U>& u, const Modint<U>& v);
    template<int U>
    friend Modint<U> operator* (const Modint<U>& u, const Modint<U>& v);
    template<int U>
    friend Modint<U> operator/ (const Modint<U>& u, const Modint<U>& v);

private:
    int x_;
};

template<int M>
Modint<M> operator+ (const Modint<M>& u, const Modint<M>& v) {
    int w = u.x_ + v.x_;
    if (w >= M) w -= M;
    return w;
}

template<int M>
Modint<M> operator- (const Modint<M>& u, const Modint<M>& v) {
    int w = u.x_ - v.x_;
    if (w < 0) w += M;
    return w;
}

template<int M>
Modint<M> operator* (const Modint<M>& u, const Modint<M>& v) {
    int w = (LL)u.x_ * v.x_ % M;
    return w;
}

template<int M>
Modint<M> operator/ (const Modint<M>& u, const Modint<M>& v) {
    int w = (LL)u.x_ * Modint<M>::quickmul(v.x_, M - 2) % M;
    return w;
}

class UF {
public:
    int n;
    int comp_cnt;
    vector<int> fa;
    vector<int> sz;
    
public:
    UF(int _n): n(_n), comp_cnt(_n), fa(_n), sz(_n, 1) {
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
        if (sz[x] < sz[y]) {
            swap(x, y);
        }
        fa[y] = x;
        sz[x] += sz[y];
        --comp_cnt;
        return true;
    }
    
    bool connected(int x, int y) {
        x = findset(x);
        y = findset(y);
        return x == y;
    }
};

int n;
int a[310][310];

using mod107 = Modint<1000000007>;
mod107 lap[310][310];

inline void work() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }

    UF uf(n + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (a[i][j] == 1) {
                if (!uf.unite(i, j)) {
                    cout << "0\n";
                    return;
                }
            }
        }
    }

    unordered_map<int, int> rep;
    int m = 0;
    for (int i = 1; i <= n; ++i) {
        if (uf.findset(i) == i) {
            rep[i] = ++m;
        }
    }

    for (int i = 1; i <= n; ++i) {
        int fai = uf.findset(i);
        for (int j = i + 1; j <= n; ++j) {
            if (a[i][j] != -1) {
                continue;
            }
            int faj = uf.findset(j);
            if (fai == faj) {
                continue;
            }
            lap[rep[fai]][rep[faj]] -= 1;
            lap[rep[faj]][rep[fai]] -= 1;
            lap[rep[fai]][rep[fai]] += 1;
            lap[rep[faj]][rep[faj]] += 1;
        }
    }

    --m;
    mod107 ans = 1;

    for (int i = 1; i < m; ++i) {
        int row = 0;
        for (int j = i; j <= m; ++j) {
            if (lap[j][i] != 0) {
                row = j;
                break;
            }
        }
        if (!row) {
            cout << "0\n";
            return;
        }
        if (row != i) {
            ans = ans.neg();
            for (int j = i; j <= m; ++j) {
                swap(lap[i][j], lap[row][j]);
            }
        }
        for (int j = i + 1; j <= m; ++j) {
            mod107 portion = lap[j][i] / lap[i][i];
            for (int k = i; k <= m; ++k) {
                lap[j][k] -= portion * lap[i][k];
            }
        }
    }
    
    for (int i = 1; i <= m; ++i) {
        ans *= lap[i][i];
    }
    cout << ans.get() << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}