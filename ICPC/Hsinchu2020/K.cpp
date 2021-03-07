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

inline int char_to_int(char ch) {
    if (ch >= '0' && ch <= '9') {
        return ch - '0';
    }
    return ch - 'a' + 10;
}

inline char int_to_char(int x) {
    if (x < 10) {
        return x + '0';
    }
    return x - 10 + 'a';
}

inline ULL hex_str_to_int(const string& s) {
    ULL ret = 0;
    for (char ch: s) {
        if (ch >= '0' && ch <= '9') {
            ret = ret * 16 + (ch - '0');
        }
        else {
            ret = ret * 16 + (ch - 'a' + 10);
        }
    }
    return ret;
}

inline ULL dec_str_to_int(const string& s) {
    return stoull(s);
}

inline string int_to_hex_str(ULL x) {
    if (x == 0) {
        return "0";
    }

    string ret;
    while (x) {
        int d = x % 16;
        if (d < 10) {
            ret += d + '0';
        }
        else {
            ret += d - 10 + 'a';
        }
        x /= 16;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

inline string int_to_dec_str(ULL x) {
    return to_string(x);
}

inline bool num_greater_than(const string& s, const string& t) {
    if (s.size() > t.size()) {
        return true;
    }
    if (s.size() < t.size()) {
        return false;
    }
    return s > t;
}

bool found[16];

inline bool is_good(const string& s) {
    memset(found, 0, sizeof(found));
    for (char ch: s) {
        int o = char_to_int(ch);
        if (found[o]) {
            return false;
        }
        found[o] = true;
    }
    return true;
}

ULL dec_full[11], hex_full[17];
ULL fac[17];
ULL dec_total, hex_total;

inline void init() {
    dec_full[1] = 10;
    dec_full[2] = 9 * 9;
    for (int i = 3; i <= 10; ++i) {
        dec_full[i] = dec_full[i - 1] * (11 - i);
    }

    hex_full[1] = 16;
    hex_full[2] = 15 * 15;
    for (int i = 3; i <= 16; ++i) {
        hex_full[i] = hex_full[i - 1] * (17 - i);
    }

    fac[0] = fac[1] = 1;
    for (int i = 2; i <= 16; ++i) {
        fac[i] = fac[i - 1] * i;
    }

    for (int i = 1; i <= 10; ++i) {
        dec_total += dec_full[i];
    }
    for (int i = 1; i <= 16; ++i) {
        hex_total += hex_full[i];
    }
}

inline ULL perm(int n, int k) {
    return fac[n] / fac[n - k];
}

inline ULL get_full(int span, int base) {
    return base == 10 ? dec_full[span] : hex_full[span];
}

inline ULL get_less_than(const string& s, int base) {
    if (s.size() == 1) {
        return hex_str_to_int(s);
    }
    
    ULL ans = 0;
    for (int i = 1; i < s.size(); ++i) {
        ans += get_full(i, base);
    }

    memset(found, false, sizeof(found));

    for (int i = 0; i < s.size(); ++i) {
        int o = char_to_int(s[i]);

        ULL mult = 0;
        if (i == 0) {
            mult = o - 1;
        }
        else {
            mult = 0;
            for (int j = 0; j < o; ++j) {
                if (!found[j]) {
                    ++mult;
                }
            }
        }
        ans += mult * perm(base - i - 1, s.size() - i - 1);

        if (found[o]) {
            break;
        }
        found[o] = true;
    }

    return ans;
}

bool used[16];

inline string get_rank(ULL x, int base) {
    if (base == 10) {
        if (x <= 10) {
            return int_to_dec_str(x - 1);
        }
    }
    else {
        if (x <= 16) {
            return int_to_hex_str(x - 1);
        }
    }

    memset(used, false, sizeof(used));
    string ret;

    int sz = 1;
    while (x > get_full(sz, base)) {
        x -= get_full(sz, base);
        ++sz;
    }

    for (int i = sz; i >= 1; --i) {
        int order;

        if (i == 1) {
            order = x;
        }
        else {
            for (int j = 1; j <= base; ++j) {
                if (x > perm(base - (sz - i) - 1, i - 1)) {
                    x -= perm(base - (sz - i) - 1, i - 1);
                }
                else {
                    order = j;
                    break;
                }
            }
        }

        for (int j = (i == sz ? 1 : 0), cnt = 0; j < base; ++j) {
            if (!used[j]) {
                ++cnt;
                if (cnt == order) {
                    ret.push_back(int_to_char(j));
                    used[j] = true;
                    break;
                }
            }
        }
    }

    return ret;
}

string type, l, r, id;
int op;

inline void work() {
    cin >> type >> op;
    if (op == 0) {
        cin >> l >> r;
        string bound = (type[0] == 'd' ? "9876543210" : "fedcba9876543210");
        if (num_greater_than(l, bound)) {
            cout << "0\n";
            return;
        }
        if (num_greater_than(r, bound)) {
            r = bound;
        }

        ULL count_r = get_less_than(r, type[0] == 'd' ? 10 : 16);
        ULL count_l = get_less_than(l, type[0] == 'd' ? 10 : 16);
        ULL ans = count_r - count_l;
        if (is_good(r)) {
            ++ans;
        }
        cout << (type[0] == 'd' ? int_to_dec_str(ans) : int_to_hex_str(ans)) << "\n";
    }
    else {
        cin >> id;
        ULL id_num = (type[0] == 'd' ? dec_str_to_int(id) : hex_str_to_int(id));
        if (type[0] == 'd') {
            if (id_num > dec_total) {
                cout << "-\n";
                return;
            }
        }
        else {
            if (id_num > hex_total) {
                cout << "-\n";
                return;
            }
        }

        cout << get_rank(id_num, type[0] == 'd' ? 10 : 16) << "\n";
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    init();
    quickread();
    int T;
    cin >> T;
    while (T--) {
        work();
    }
    return 0;
}