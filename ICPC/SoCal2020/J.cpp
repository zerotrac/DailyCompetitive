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
double r, s, w, f, l1, l2, d;
double pi = acos(-1.0);

inline void work() {
    cin >> n >> r >> s >> w >> f >> l1 >> l2;
    while (cin >> d) {
        cout << fixed << setprecision(5) << d;
        for (int i = 1; i <= n; ++i) {
            double RR = r + (i - 1) * w;
            double RRAdd = RR + (i == 1 ? l1 : l2);
            double semi = pi * RRAdd;
            // cout << "RR = " << RR << " " << semi << endl;
            double complete = (s + semi) * 2.;
            
            double dd = d;
            while (dd >= complete) {
                dd -= complete;
            }

            double part1 = f + s / 2.;
            double part2 = semi;
            double part3 = s;
            double part4 = semi;
            double part5 = s / 2. - f;

            if (dd <= part1) {
                cout << " " << fixed << setprecision(5) << f - dd;
                cout << " " << fixed << setprecision(5) << -RR;
            }
            else if (dd <= part1 + part2) {
                dd -= part1;
                double ang = dd / semi * pi;
                ang = pi * 3 / 2 - ang;
                cout << " " << fixed << setprecision(5) << -s / 2 + RR * cos(ang);
                cout << " " << fixed << setprecision(5) << RR * sin(ang);
            }
            else if (dd <= part1 + part2 + part3) {
                dd -= part1 + part2;
                cout << " " << fixed << setprecision(5) << -s / 2 + dd;
                cout << " " << fixed << setprecision(5) << RR;
            }
            else if (dd <= part1 + part2 + part3 + part4) {
                dd -= part1 + part2 + part3;
                double ang = dd / semi * pi;
                ang = -ang + pi / 2;
                cout << " " << fixed << setprecision(5) << s / 2 + RR * cos(ang);
                cout << " " << fixed << setprecision(5) << RR * sin(ang);
            }
            else {
                dd = complete - dd;
                cout << " " << fixed << setprecision(5) << f + dd;
                cout << " " << fixed << setprecision(5) << -RR;
            }
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