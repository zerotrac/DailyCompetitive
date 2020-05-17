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

int T, B;
string dummy0, dummy1, dummy;

inline void work() {
    vector<int> mask(B / 2, -1);

    auto setmask = [&](int x, int ub, int lb) {
        mask[x] = ub * 2 + lb;
    };

    auto getmask = [&](int x, int y) {
        int m = mask[x];
        if (m == -1) while (1);
        if (m == 0b00) {
            return y == 0 ? 0b1010 : 0b0101;
        }
        else if (m == 0b01) {
            return y == 0 ? 0b1001 : 0b0110;
        }
        else if (m == 0b10) {
            return y == 0 ? 0b0110 : 0b1001;
        }
        else {
            return y == 0 ? 0b0101 : 0b1010;
        }
    };

    auto revmask = [&]() {
        for (int i = 0; i < B / 2; ++i) {
            if (mask[i] != -1) {
                mask[i] = ((mask[i] & 1) << 1) ^ (mask[i] >> 1);
            }
        }
    };

    auto compmask = [&]() {
        for (int i = 0; i < B / 2; ++i) {
            if (mask[i] != -1) {
                mask[i] ^= 0b11;
            }
        }
    };

    auto execute = [&](int poss) {
        if (!poss) {
            while (1);
        }
        if (poss & 0b1000) {
            // do nothing
        }
        else if (poss & 0b0100) {
            compmask();
        }
        else if (poss & 0b0010) {
            revmask();
        }
        else {
            compmask();
            revmask();
        }
    };

    int cnt = 0, barrier = 11;
    int querypos = 0;
    
    while (querypos < B / 2) {
        if (cnt + 2 < barrier) {
            cout << querypos + 1 << endl;
            cin >> dummy0;
            cout << B - querypos << endl;
            cin >> dummy1;
            
            // cerr << "N| " << querypos + 1 << " " << dummy0 << " " << B - querypos << " " << dummy1 << endl;

            setmask(querypos, dummy0[0] - 48, dummy1[0] - 48);
            ++querypos;
            cnt += 2;
        }
        else if (cnt + 2 == barrier) {
            cout << 1 << endl;
            cin >> dummy;

            // cerr << "D| " << 1 << " " << dummy << endl;

            ++cnt;
        }
        else {
            unordered_map<int, vector<int>> stats;
            for (int i = 0; i < B / 2; ++i) {
                stats[mask[i]].push_back(i);
            }
            if (!stats.count(0b00) && !stats.count(0b11)) {
                int fd = stats.count(0b01) ? stats[0b01][0] : stats[0b10][0];
                cout << fd + 1 << endl;
                cin >> dummy;

                // cerr << "K1| " << fd + 1 << " " << dummy << endl;

                int poss = getmask(fd, dummy[0] - 48);
                execute(poss);
                ++cnt;
            }
            else if (!stats.count(0b01) && !stats.count(0b10)) {
                int fd = stats.count(0b00) ? stats[0b00][0] : stats[0b11][0];
                cout << fd + 1 << endl;
                cin >> dummy;

                // cerr << "K2| " << fd + 1 << " " << dummy << endl;

                int poss = getmask(fd, dummy[0] - 48);
                execute(poss);
                ++cnt;
            }
            else {
                int fd0 = stats.count(0b01) ? stats[0b01][0] : stats[0b10][0];
                cout << fd0 + 1 << endl;
                cin >> dummy0;
                int poss0 = getmask(fd0, dummy0[0] - 48);
                int fd1 = stats.count(0b00) ? stats[0b00][0] : stats[0b11][0];
                cout << fd1 + 1 << endl;
                cin >> dummy1;

                // cerr << "K3| " << fd0 + 1 << " " << dummy0 << " " << fd1 + 1 << " " << dummy1 << endl;

                int poss1 = getmask(fd1, dummy1[0] - 48);
                int poss = poss0 & poss1;
                execute(poss);
                cnt += 2;
            }
            barrier += 10;
        }
    }

    string ans(B, '_');
    for (int i = 0; i < B / 2; ++i) {
        ans[i] = ((mask[i] >> 1) & 1) + 48;
        ans[B - i - 1] = (mask[i] & 1) + 48;
    }
    cout << ans << endl;
    cin >> dummy;
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    cin >> T >> B;
    for (int _ = 1; _ <= T; ++_) {
        work();
    }
    return 0;
}