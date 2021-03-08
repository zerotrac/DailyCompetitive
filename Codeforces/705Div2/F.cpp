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

int m, n, pm, pn, test;

map<int, int> factorize(int x) {
    map<int, int> ret;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            int cnt = 0;
            while (x % i == 0) {
                ++cnt;
                x /= i;
            }
            ret[i] = cnt;
        }
    }
    if (x != 1) {
        ret[x] = 1;
    }
    return ret;
}

int getnum(int x) {
    int ret = 0;
    for (int i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            ++ret;
            if (i * i != x) {
                ++ret;
            }
        }
    }
    return ret;
}

inline void work() {
    cin >> m >> n;

    // partition m
    if (m == 1) {
        pm = 1;
    }
    else {
        auto fac = factorize(m);
        int cur = 1, best = -1;
        for (auto [prime, occ]: fac) {
            for (int i = 0; i < occ; ++i) {
                int length = m / (cur * prime);
                if (best == -1) {
                    cout << "? " << length << " " << n << " " << 1 << " " << 1 << " " << length + 1 << " " << 1 << endl;
                }
                else {
                    cout << "? " << length * (prime - 1) << " " << n << " " << 1 << " " << 1 << " " << length * (prime - 1) + 1 << " " << 1 << endl;
                }
                cin >> test;
                if (test) {
                    cur *= prime;
                    if (best == -1) {
                        best = length;
                    }
                }
                else {
                    break;
                }
            }
        }
        if (best == -1) {
            pm = 1;
        }
        else {
            bool good = true;
            best *= 2;
            while (best * 2 <= m) {
                cout << "? " << best << " " << n << " " << 1 << " " << 1 << " " << best + 1 << " " << 1 << endl;
                cin >> test;
                if (!test) {
                    good = false;
                    break;
                }
                else {
                    best *= 2;
                }
            }
            if (good && best < m) {
                cout << "? " << m - best << " " << n << " " << 1 << " " << 1 << " " << best + 1 << " " << 1 << endl;
                cin >> test;
                if (!test) {
                    good = false;
                }
            }
            if (good) {
                pm = cur;
            }
            else {
                pm = 1;
            }
        }
    }

    // partition n
    if (n == 1) {
        pn = 1;
    }
    else {
        auto fac = factorize(n);
        int cur = 1, best = -1;
        for (auto [prime, occ]: fac) {
            for (int i = 0; i < occ; ++i) {
                int length = n / (cur * prime);
                if (best == -1) {
                    cout << "? " << m << " " << length << " " << 1 << " " << 1 << " " << 1 << " " << length + 1 << endl;
                }
                else {
                    cout << "? " << m << " " << length * (prime - 1) << " " << 1 << " " << 1 << " " << 1 << " " << length * (prime - 1) + 1 << endl;
                }
                cin >> test;
                if (test) {
                    cur *= prime;
                    if (best == -1) {
                        best = length;
                    }
                }
                else {
                    break;
                }
            }
        }
        if (best == -1) {
            pn = 1;
        }
        else {
            bool good = true;
            best *= 2;
            while (best * 2 <= n) {
                cout << "? " << m << " " << best << " " << 1 << " " << 1 << " " << 1 << " " << best + 1 << endl;
                cin >> test;
                if (!test) {
                    good = false;
                    break;
                }
                else {
                    best *= 2;
                }
            }
            if (good && best < n) {
                cout << "? " << m << " " << n - best << " " << 1 << " " << 1 << " " << 1 << " " << best + 1 << endl;
                cin >> test;
                if (!test) {
                    good = false;
                }
            }
            if (good) {
                pn = cur;
            }
            else {
                pn = 1;
            }
        }
    }

    cout << "! " << getnum(pm) * getnum(pn) << endl;
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}