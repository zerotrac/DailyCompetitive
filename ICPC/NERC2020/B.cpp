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

string a, b, t;
int n;
unordered_map<string, int> cnt;
unordered_map<char, LL> weight;
unordered_set<char> banzero;
char used[10];

void dfs(unordered_map<char, LL>::iterator it, LL sum) {
    if (it == weight.end()) {
        vector<int> v;
        while (sum) {
            v.push_back(sum % 10);
            sum /= 10;
        }
        reverse(v.begin(), v.end());
        string s;
        s.reserve(v.size());
        char extra = 'a';
        for (int x: v) {
            if (used[x] == '.') {
                used[x] = extra++;
            }
            s.push_back(used[x]);
        }
        ++cnt[move(s)];
        for (int i = 0; i < 10; ++i) {
            if ('a' <= used[i] && used[i] <= 'z') {
                used[i] = '.';
            }
        }
        return;
    }
    for (int i = (banzero.count(it->first) ? 1 : 0); i < 10; ++i) {
        if (used[i] == '.') {
            used[i] = it->first;
            dfs(next(it), sum + it->second * i);
            used[i] = '.';
        }
    }
}

inline bool pre() {
    LL w = 1;
    for (int i = a.size() - 1; i >= 0; --i) {
        weight[a[i]] += w;
        w *= 10;
    }
    w = 1;
    for (int i = b.size() - 1; i >= 0; --i) {
        weight[b[i]] += w;
        w *= 10;
    }
    for (int i = 0; i < 10; ++i) {
        used[i] = '.';
    }
    banzero.insert(a[0]);
    banzero.insert(b[0]);
    if (weight.size() > 10) {
        return false;
    }
    dfs(weight.begin(), 0);
    return true;
}

inline string getPattern(const string& word) {
    char extra = 'a';
    unordered_map<char, char> rela;
    string ret = word;
    for (char& ch: ret) {
        if (!weight.count(ch)) {
            if (!rela.count(ch)) {
                rela[ch] = extra++;
            }
            ch = rela[ch];
        }
    }
    return ret;
}

inline void work() {
    cin >> a >> b;
    if (!pre()) {
        cout << 0 << "\n";
        return;
    }

    cin >> n;
    vector<string> ans;
    for (int i = 1; i <= n; ++i) {
        cin >> t;
        string pattern = getPattern(t);
        if (cnt.count(pattern) && cnt[pattern] == 1) {
            ans.push_back(move(t));
        }
    }

    cout << ans.size() << "\n";
    for (string& o: ans) {
        cout << o << "\n";
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    work();
    return 0;
}