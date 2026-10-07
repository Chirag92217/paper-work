// P06 - Count subarrays with sum exactly K (prefix sum + hash map; negatives allowed)
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;
    unordered_map<long long, long long> seen;
    seen.reserve(2 * n + 1);
    seen[0] = 1;  // empty prefix
    long long pre = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        long long x; cin >> x;
        pre += x;
        auto it = seen.find(pre - k);
        if (it != seen.end()) ans += it->second;
        seen[pre]++;
    }
    cout << ans << "\n";
}
