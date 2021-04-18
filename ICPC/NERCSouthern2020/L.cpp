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

static constexpr int MAXA = 1000000;
vector<int> primes;
bool isprime[MAXA + 10];

inline void init() {
    memset(isprime, true, sizeof(isprime));
    for (int i = 2; i <= MAXA; ++i) {
        if (isprime[i]) {
            primes.push_back(i);
        }
        for (int prime: primes) {
            if (i * prime > MAXA) {
                break;
            }
            isprime[i * prime] = false;
            if (i % prime == 0) {
                break;
            }
        }
    }
}

int n, k;
LL a[1010];
// 0 = nothing, 1 = p^q, 2 = \prod p
int type[1010];
vector<int> factors[1010];

inline bool checkPrime(LL x) {
    for (int prime: primes) {
        if ((LL)prime * prime > x) {
            return true;
        }
        if (x % prime == 0) {
            return false;
        }
    }
    return true;
}

inline void work() {
    cin >> n >> k;
    if (k == 1) {
        cout << "0\n";
        return;
    }

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    unordered_map<int, vector<LL>> cand_primes;
    for (int i = 1; i <= n; ++i) {
        // a[i] = p^q (q>=3)
        for (int prime: primes) {
            if (a[i] % prime == 0) {
                LL x = a[i];
                while (x % prime == 0) {
                    x /= prime;
                }
                if (x == 1) {
                    type[i] = 1;
                    cand_primes[prime].push_back(a[i]);
                }
                break;
            }
        }

        if (type[i] != 1) {
            // a[i] = p^2
            LL rt = sqrt(a[i] + 1);
            if (rt * rt == a[i] && checkPrime(rt)) {
                type[i] = 1;
                cand_primes[rt].push_back(a[i]);
            }
        }

        if (type[i] != 1 && a[i] <= 1e9) {
            // a[i] = p
            if (checkPrime(a[i])) {
                type[i] = 1;
                cand_primes[a[i]].push_back(a[i]);
            }
        }
    }

    unordered_map<int, vector<LL>> real_primes;
    for (auto&& [prime, cands]: cand_primes) {
        if (cands.size() >= 2) {
            real_primes[prime] = move(cands);
        }
    }

    if (real_primes.empty()) {
        cout << "0\n";
        return;
    }

    for (int i = 1; i <= n; ++i) {
        if (!type[i]) {
            LL x = a[i];
            for (auto&& [prime, _]: real_primes) {
                if (x % prime == 0) {
                    factors[i].push_back(prime);
                    while (x % prime == 0) {
                        x /= prime;
                    }
                }
            }
            if (x == 1) {
                type[i] = 2;
            }
        }
    }

    int type1cnt = 0, type1max = 0;
    for (auto&& [prime, reals]: real_primes) {
        type1cnt += reals.size();
        type1max = max(type1max, (int)reals.size());
    }
    int type2cnt = 0;
    for (int i = 1; i <= n; ++i) {
        type2cnt += (type[i] == 2);
    }

    if (type1cnt + type2cnt < k) {
        cout << "0\n";
        return;
    }
    if (type1cnt <= k) {
        for (auto&& [prime, reals]: real_primes) {
            for (auto&& p0: reals) {
                cout << p0 << " ";
            }
        }
        for (int i = 1, j = k - type1cnt; i <= n && j; ++i) {
            if (type[i] == 2) {
                cout << a[i] << " ";
                --j;
            }
        }
        cout << "\n";
    }
    else if (type1max > 2) {
        vector<LL> pp;
        for (auto&& [prime, _]: real_primes) {
            pp.push_back(prime);
        }
        sort(pp.begin(), pp.end(), [&](int p1, int p2) { return real_primes[p1].size() > real_primes[p2].size(); });
        vector<LL> ans;
        for (int p0: pp) {
            if (ans.size() + real_primes[p0].size() <= k) {
                for (auto&& u: real_primes[p0]) {
                    ans.push_back(u);
                }
                if (ans.size() == k) {
                    break;
                }
            }
            else {
                if (k - ans.size() >= 2) {
                    for (int i = 0, im = k - ans.size(); i < im; ++i) {
                        ans.push_back(real_primes[p0][i]);
                    }
                }
                else {
                    ans.push_back(real_primes[p0][0]);
                    ans.push_back(real_primes[p0][1]);
                    ans.erase(ans.begin());
                }
                break;
            }
        }
        for (auto&& u: ans) {
            cout << u << " ";
        }
        cout << "\n";
    }
    else {
        if (k % 2 == 0) {
            for (auto&& [prime, reals]: real_primes) {
                cout << reals[0] << " " << reals[1] << " ";
                k -= 2;
                if (!k) {
                    break;
                }
            }
            cout << "\n";
        }
        else {
            int pos = 0;
            for (int i = 1; i <= n; ++i) {
                if (type[i] == 2 && factors[i].size() * 2 + 1 <= k) {
                    pos = i;
                    break;
                }
            }
            if (!pos) {
                cout << "0\n";
            }
            else {
                cout << a[pos] << " ";
                for (int p0: factors[pos]) {
                    cout << real_primes[p0][0] << " " << real_primes[p0][1] << " ";
                    real_primes[p0].clear();
                    k -= 2;
                }
                --k;
                if (k) {
                    for (auto&& [prime, reals]: real_primes) {
                        if (reals.empty()) {
                            continue;
                        }
                        cout << reals[0] << " " << reals[1] << " ";
                        k -= 2;
                        if (!k) {
                            break;
                        }
                    }
                }
                cout << "\n";
            }
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    init();
    work();
    return 0;
}