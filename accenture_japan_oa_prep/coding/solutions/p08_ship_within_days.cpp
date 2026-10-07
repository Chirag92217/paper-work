// P08 - Minimum truck capacity to ship all packages, in order, within D days (binary search on answer)
#include <bits/stdc++.h>
using namespace std;

int n, D;
vector<long long> w;

bool feasible(long long cap) {
    int days = 1;
    long long load = 0;
    for (long long x : w) {
        if (load + x > cap) { days++; load = 0; }
        load += x;
    }
    return days <= D;
}

int main() {
    cin >> n >> D;
    w.resize(n);
    long long lo = 0, hi = 0;
    for (auto &x : w) { cin >> x; lo = max(lo, x); hi += x; }
    // smallest cap in [max weight, total] that is feasible; feasibility is monotonic in cap
    while (lo < hi) {
        long long mid = lo + (hi - lo) / 2;
        if (feasible(mid)) hi = mid; else lo = mid + 1;
    }
    cout << lo << "\n";
}
