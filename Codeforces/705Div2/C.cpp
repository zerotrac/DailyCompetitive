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

int n, k;
string st;
int cnt[26], extra[26];

inline void work() {
    cin >> n >> k >> st;
    if (n % k != 0) {
        cout << "-1\n";
    }
    else if (k == 1) {
        cout << st << "\n";
    }
    else {
        memset(cnt, 0, sizeof(cnt));
        string ans;
        for (char c: st) {
            ++cnt[c - 'a'];
        }
        for (int i = n - 1; i >= -1; --i) {
            int extra_cnt = 0;
            for (int j = 0; j < 26; ++j) {
                if (cnt[j] % k == 0) {
                    extra[j] = 0;
                }
                else {
                    extra[j] = k - cnt[j] % k;
                    extra_cnt += extra[j];
                }
            }
            if (i == n - 1 && !extra_cnt) {
                ans = st;
                break;
            }
            if (extra_cnt <= n - i - 1) {
                if (extra_cnt == n - i - 1) {
                    int large = -1;
                    for (int j = st[i + 1] - 'a' + 1; j < 26; ++j) {
                        if (extra[j]) {
                            large = j;
                            break;
                        }
                    }
                    if (large != -1) {
                        ans = st.substr(0, i + 1);
                        ans += large + 'a';
                        --extra[large];
                        for (int j = 0; j < 26; ++j) {
                            for (int o = 0; o < extra[j]; ++o) {
                                ans += j + 'a';
                            }
                        }
                        break;
                    }
                }
                else if (st[i + 1] != 'z') {
                    int batch = (n - i - 1 - extra_cnt) / k;
                    if (extra[st[i + 1] - 'a' + 1]) {
                        extra[0] += batch * k;
                    }
                    else {
                        extra[st[i + 1] - 'a' + 1] += k;
                        extra[0] += (batch - 1) * k;
                    }
                    ans = st.substr(0, i + 1);
                    ans += st[i + 1] + 1;
                    --extra[st[i + 1] - 'a' + 1];
                    for (int j = 0; j < 26; ++j) {
                        for (int o = 0; o < extra[j]; ++o) {
                            ans += j + 'a';
                        }
                    }
                    break;
                }
            }
            if (i != -1) {
                --cnt[st[i] - 'a'];
            }
        }
        cout << ans << "\n";
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    int T;
    cin >> T;
    while (T--) {
        work();
    }
    return 0;
}