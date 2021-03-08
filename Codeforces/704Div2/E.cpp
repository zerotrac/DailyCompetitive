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

int m, n;
vector<vector<int>> a;

inline void show(const vector<int>& v) {
    cout << "Yes\n";
    for (int num: v) {
        cout << num << " ";
    }
    cout << "\n";
}

inline bool check(const vector<int>& v) {
    for (int i = 0; i < m; ++i) {
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            if (a[i][j] != v[j]) {
                ++cnt;
            }
        }
        if (cnt > 2) {
            return false;
        }
    }
    return true;
}

inline int checkhalf(const vector<int>& v, int pos) {
    int o = 0;
    for (int i = 0; i < m; ++i) {
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            if (j == pos) {
                continue;
            }
            if (a[i][j] != v[j]) {
                ++cnt;
            }
        }
        if (cnt > 2) {
            return 0;
        }
        if (cnt == 2) {
            if (o && a[i][pos] != o) {
                return 0;
            }
            o = a[i][pos];
        }
    }
    return o;
}

inline void work() {
    cin >> m >> n;
    a.assign(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i < m; ++i) {
        vector<int> diff;
        for (int j = 0; j < n; ++j) {
            if (a[0][j] != a[i][j]) {
                diff.push_back(j);
            }
        }
        if (diff.size() > 4) {
            cout << "No\n";
            return;
        }
        if (diff.size() == 4) {
            int p = diff[0], q = diff[1], r = diff[2], s = diff[3];
            vector<int> standard;
            standard = a[0]; standard[p] = a[i][p]; standard[q] = a[i][q];
            if (check(standard)) { show(standard); return; }
            standard = a[0]; standard[p] = a[i][p]; standard[r] = a[i][r];
            if (check(standard)) { show(standard); return; }
            standard = a[0]; standard[p] = a[i][p]; standard[s] = a[i][s];
            if (check(standard)) { show(standard); return; }
            standard = a[0]; standard[q] = a[i][q]; standard[r] = a[i][r];
            if (check(standard)) { show(standard); return; }
            standard = a[0]; standard[q] = a[i][q]; standard[s] = a[i][s];
            if (check(standard)) { show(standard); return; }
            standard = a[0]; standard[r] = a[i][r]; standard[s] = a[i][s];
            if (check(standard)) { show(standard); return; }
            cout << "No\n";
            return;
        }
        else if (diff.size() == 3) {
            int p = diff[0], q = diff[1], r = diff[2];
            vector<int> standard;
            standard = a[0]; standard[p] = a[i][p]; standard[q] = a[i][q];
            if (check(standard)) { show(standard); return; }
            standard = a[0]; standard[p] = a[i][p]; standard[r] = a[i][r];
            if (check(standard)) { show(standard); return; }
            standard = a[0]; standard[q] = a[i][q]; standard[r] = a[i][r];
            if (check(standard)) { show(standard); return; }
            standard = a[i]; standard[p] = a[0][p]; standard[q] = a[0][q];
            if (check(standard)) { show(standard); return; }
            standard = a[i]; standard[p] = a[0][p]; standard[r] = a[0][r];
            if (check(standard)) { show(standard); return; }
            standard = a[i]; standard[q] = a[0][q]; standard[r] = a[0][r];
            if (check(standard)) { show(standard); return; }

            standard = a[i]; standard[q] = a[0][q];
            if (int o = checkhalf(standard, r); o) { standard[r] = o; show(standard); return; }
            standard = a[i]; standard[r] = a[0][r];
            if (int o = checkhalf(standard, q); o) { standard[q] = o; show(standard); return; }
            standard = a[i]; standard[p] = a[0][p];
            if (int o = checkhalf(standard, r); o) { standard[r] = o; show(standard); return; }
            standard = a[i]; standard[p] = a[0][p];
            if (int o = checkhalf(standard, q); o) { standard[q] = o; show(standard); return; }
            standard = a[i]; standard[r] = a[0][r];
            if (int o = checkhalf(standard, p); o) { standard[p] = o; show(standard); return; }
            standard = a[i]; standard[q] = a[0][q];
            if (int o = checkhalf(standard, p); o) { standard[p] = o; show(standard); return; }

            cout << "No\n";
            return;
        }
    }

    show(a[0]);
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}