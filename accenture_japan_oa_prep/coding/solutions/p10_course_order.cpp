// P10 - Course order (Kahn's topological sort, lexicographically smallest)
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> indeg(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;  // a must be completed before b
        adj[a].push_back(b);
        indeg[b]++;
    }
    priority_queue<int, vector<int>, greater<int>> pq;  // min-heap => smallest available course first
    for (int v = 1; v <= n; v++) if (indeg[v] == 0) pq.push(v);
    vector<int> order;
    while (!pq.empty()) {
        int v = pq.top(); pq.pop();
        order.push_back(v);
        for (int u : adj[v]) if (--indeg[u] == 0) pq.push(u);
    }
    if ((int)order.size() < n) { cout << "IMPOSSIBLE\n"; return 0; }  // leftover nodes => cycle
    for (int i = 0; i < n; i++) cout << order[i] << (i + 1 < n ? ' ' : '\n');
}
