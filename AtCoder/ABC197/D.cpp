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

int n;
double xs, ys, xm, ym;

inline void work() {
    cin >> n >> xs >> ys >> xm >> ym;
    double xc = (xs + xm) / 2.;
    double yc = (ys + ym) / 2.;
    
    double xs0 = xs - xc;
    double ys0 = ys - yc;
    double pi = acos(-1.0);
    double ang = pi * 2. / n;

    double xs1 = xs0 * cos(ang) - ys0 * sin(ang) + xc;
    double ys1 = ys0 * cos(ang) + xs0 * sin(ang) + yc;

    cout << fixed << setprecision(10) << xs1 << " " << fixed << setprecision(10) << ys1 << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}