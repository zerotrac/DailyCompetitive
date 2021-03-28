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

static constexpr int N = 100;
static constexpr int M = 10000;

string exam[N + 1];
double difficulty[M + 1];
int pass[M + 1];

mt19937 gen{random_device{}()};
uniform_int_distribution<int> dis(0, INT_MAX);

inline void init() {
    double x = 3.0;
    double portion = x * 2 / (M - 1);
    for (int i = 1; i <= M; ++i) {
        difficulty[i] = x;
        x -= portion;
    }
}

inline void work() {
    memset(pass, 0, sizeof(pass));
    for (int i = 1; i <= N; ++i) {
        cin >> exam[i];
        for (int j = 0; j < M; ++j) {
            if (exam[i][j] == '1') {
                ++pass[j + 1];
            }
        }
    }

    // pass, random_value, index
    vector<tuple<int, int, int>> problems;
    for (int j = 1; j <= M; ++j) {
        problems.emplace_back(pass[j], dis(gen), j);
    }
    sort(problems.begin(), problems.end());
    unordered_map<int, double> scores;
    for (int j = 0; j < M; ++j) {
        scores[get<2>(problems[j])] = difficulty[j + 1];
    }

    double bad = -1.0;
    int ans = 0;

    for (int i = 1; i <= N; ++i) {
        int count0 = 0, count1 = 0;
        vector<pair<double, char>> v;
        for (int j = 0; j < M; ++j) {
            if (exam[i][j] == '0') {
                ++count0;
            }
            else {
                ++count1;
            }
            v.emplace_back(scores[j + 1], exam[i][j]);
        }
        sort(v.begin(), v.end());

        int count_inv = 0, pre0 = 0;
        for (auto [_, c]: v) {
            if (c == '0') {
                ++pre0;
            }
            else {
                count_inv += pre0;
            }
        }

        double evaluate = (double)count_inv / (count0 * count1);
        if (evaluate > bad) {
            bad = evaluate;
            ans = i;
        }
    }

    cout << ans << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    quickread();
    init();
    int T, P;
    cin >> T >> P;
    for (int _ = 1; _ <= T; ++_) {
        cout << "Case #" << _ << ": ";
        work();
    }
    return 0;
}