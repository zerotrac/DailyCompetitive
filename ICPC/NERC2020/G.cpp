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
const int mod = 1e9 + 7;
// const int mod = 998244353;

inline void quickread() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int xa, ya, xb, yb, xc, yc;

static constexpr int MAXK = 1000000;
int fac[MAXK + 10], inv[MAXK + 10], facinv[MAXK + 10];

inline void pre() {
    fac[0] = inv[0] = facinv[0] = 1;
    fac[1] = inv[1] = facinv[1] = 1;
    for (int i = 2; i <= MAXK + 5; ++i) {
        fac[i] = (LL)fac[i - 1] * i % mod;
        inv[i] = (LL)(mod - mod / i) * inv[mod % i] % mod;
        facinv[i] = (LL)facinv[i - 1] * inv[i] % mod;
    }
}

inline int comb(int n, int k) {
    if (n < k) {
        return 0;
    }
    if (!k) {
        return 1;
    }
    return (LL)fac[n] * facinv[k] % mod * facinv[n - k] % mod;
}

static constexpr long double eps = 1e-7;

struct Pointld {
    long double x, y;
    Pointld(long double _x, long double _y): x(_x), y(_y) {}
};

struct Point {
    LL x, y;
    Point(LL _x, LL _y): x(_x), y(_y) {}
    Point(const Point& that): x(that.x), y(that.y) {}
    Point operator+ (const Point& that) const {
        return {x + that.x, y + that.y};
    }
    Point operator- (const Point& that) const {
        return {x - that.x, y - that.y};
    }
    Point operator* (LL amp) const {
        return {x * amp, y * amp};
    }
    Pointld operator/ (LL amp) const {
        return Pointld{(long double)x / amp, (long double)y / amp};
    }
    friend ostream& operator<< (ostream& out, const Point& a) {
        out << "(" << a.x << "," << a.y << ")";
        return out;
    }
};

struct Line {
    Point a, b;
    Line(const Point& _a, const Point& _b): a(_a), b(_b) {}
    friend ostream& operator<< (ostream& out, const Line& l) {
        out << l.a << "-" << l.b;
        return out;
    }
};

LL det(const Point& a, const Point& b) {
    // cout << "det = " << a << " " << b << " " << a.x * b.y - b.x * a.y << endl;
    return a.x * b.y - b.x * a.y;
}

LL dot(const Point& a, const Point& b) {
    return a.x * b.x + a.y * b.y;
}

Pointld intersect(const Line& l1, const Line& l2) {
    LL s1 = det(l2.b - l2.a, l1.a - l2.a);
    LL s2 = -det(l2.b - l2.a, l1.b - l2.a);
    return (l1.a * s2 + l1.b * s1) / (s1 + s2);
}

bool parallel(const Line& l1, const Line& l2) {
    // cout << l1 << " " << l2 << endl;
    return det(l1.b - l1.a, l2.b - l2.a) == 0;
}

// int sign(long double x) {
//     if (fabs(x) < eps) {
//         return 0;
//     }
//     return x > 0 ? 1 : -1;
// }

// bool onseg(const Line& l, const Point& p) {
//     return sign(det(p - l.a, l.b - l.a)) == 0 && sign(dot(p - l.a, p - l.b)) <= 0;
// }

bool segcross(const Line& l, const Line& seg) {
    Point p = l.b - l.a;
    Point q1 = seg.a - l.a;
    Point q2 = seg.b - l.a;
    LL u = det(p, q1);
    LL v = det(p, q2);
    if (u > 0 && v > 0) {
        return false;
    }
    if (u < 0 && v < 0) {
        return false;
    }
    return true;
}

bool triinside(const Line& l1, const Line& l2, const Line& l3, const Point& p) {
    LL u = det(l1.b - l1.a, p - l1.a);
    LL v = det(l2.b - l2.a, p - l2.a);
    LL w = det(l3.b - l3.a, p - l3.a);
    if (u >= 0 && v >= 0 && w >= 0) {
        return true;
    }
    if (u <= 0 && v <= 0 && w <= 0) {
        return true;
    }
    return false;
}

inline void work() {
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    Line lab = {Point(xa, ya), Point(xb, yb)};
    Line lbc = {Point(xb, yb), Point(xc, yc)};
    Line lca = {Point(xc, yc), Point(xa, ya)};
    // C(n, k), iterate over k
    int ans = 0;
    for (int k = 0; k <= MAXK; ++k) {
    // for (int k = 0; k <= 2; ++k) {
        // cout << "k = " << k << endl;
        Line l = {Point(-k, k), Point(MAXK - k * 2 + 1, MAXK + 1)};
        vector<long double> rng;
        // cout << "p?" << parallel(l, lab) << " " << parallel(l, lac) << " " << parallel(l, lbc) << endl;
        if (!parallel(l, lab) && segcross(l, lab)) {
            Pointld u = intersect(l, lab);
            // cout << "lab = " << l << " " << lab << " " << u << " " << onseg(lab, u) << endl;
            rng.push_back(u.y - k);
        }
        if (!parallel(l, lbc) && segcross(l, lbc)) {
            Pointld u = intersect(l, lbc);
            // cout << "lac = " << l << " " << lac << " " << u << " " << onseg(lac, u) << endl;
            rng.push_back(u.y - k);
        }
        if (!parallel(l, lca) && segcross(l, lca)) {
            Pointld u = intersect(l, lca);
            // cout << "lbc = " << l << " " << lbc << " " << u << " " << onseg(lbc, u) << endl;
            rng.push_back(u.y - k);
        }

        if (rng.empty()) {
            continue;
        }

        sort(rng.begin(), rng.end());
        int r1 = floor(rng[0]);
        if (!triinside(lab, lbc, lca, Point(-k + r1, k + r1))) {
            ++r1;
        }

        int r2 = ceil(rng.back());
        if (!triinside(lab, lbc, lca, Point(-k + r2, k + r2))) {
            --r2;
        }

        if (r1 > r2) {
            continue;
        }

        ans += comb(k + r2 + 1, k + 1);
        if (ans >= mod) {
            ans -= mod;
        };
        ans -= comb(k + r1, k + 1);
        if (ans < 0) {
            ans += mod;
        }
    }
    cout << ans << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    pre();
    int T;
    cin >> T;
    while (T--) {
        work();
    }
    return 0;
}