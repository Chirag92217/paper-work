// P07 - Minimum meeting rooms (sweep line over sorted events)
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<long long,int>> ev;
    for (int i = 0; i < n; i++) {
        long long s, e; cin >> s >> e;
        ev.push_back({s, +1});
        ev.push_back({e, -1});
    }
    // At equal times, -1 sorts before +1: a meeting ending at 10 frees its room for one starting at 10.
    sort(ev.begin(), ev.end());
    int cur = 0, best = 0;
    for (auto &[t, d] : ev) { cur += d; best = max(best, cur); }
    cout << best << "\n";
}
