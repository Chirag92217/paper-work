// P03 - Help Desk Simulation (event-driven simulation with heaps)
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<long long> arr(n), dur(n);
    vector<int> vip(n);
    for (int i = 0; i < n; i++) cin >> arr[i] >> dur[i] >> vip[i];

    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int a, int b) {
        return arr[a] != arr[b] ? arr[a] < arr[b] : a < b;
    });

    // waiting queue ordering: VIP first, then earlier arrival, then smaller index
    auto worse = [&](int a, int b) {
        if (vip[a] != vip[b]) return vip[a] < vip[b];
        if (arr[a] != arr[b]) return arr[a] > arr[b];
        return a > b;
    };
    priority_queue<int, vector<int>, decltype(worse)> waiting(worse);
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> busy; // (free time, counter)
    set<int> freeCounters;
    for (int j = 1; j <= k; j++) freeCounters.insert(j);

    vector<long long> finish(n);
    vector<int> counter(n);
    int next = 0, assigned = 0;
    long long t = 0;
    while (assigned < n) {
        while (!busy.empty() && busy.top().first <= t) { freeCounters.insert(busy.top().second); busy.pop(); }
        while (next < n && arr[order[next]] <= t) waiting.push(order[next++]);

        while (!freeCounters.empty() && !waiting.empty()) {
            int cust = waiting.top(); waiting.pop();
            int ctr = *freeCounters.begin(); freeCounters.erase(freeCounters.begin());
            finish[cust] = t + dur[cust];
            counter[cust] = ctr;
            busy.push({finish[cust], ctr});
            assigned++;
        }
        if (assigned == n) break;

        // jump to the next moment something can change
        long long nt = LLONG_MAX;
        if (!busy.empty()) nt = min(nt, busy.top().first);
        if (next < n) nt = min(nt, arr[order[next]]);
        t = nt;
    }
    for (int i = 0; i < n; i++) cout << counter[i] << " " << finish[i] << "\n";
}
