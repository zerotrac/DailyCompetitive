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
