#include <chrono>
#include <unordered_set>
#include <unordered_map>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

auto pair_hash = [hash_fn = hash<int>()](const PII& o) {
    return hash_fn(o.first) ^ hash_fn(o.second);
};

// 自定义 hash 的 unordered_set
unordered_set<PII, decltype(pair_hash)> us(0, pair_hash);

// 自定义 hash 的 unordered_map
unordered_map<PII, int, decltype(pair_hash)> um(0, pair_hash);

// 防止卡 unordered_map
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};