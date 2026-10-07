// P12 - Cheapest delivery route (Dijkstra) with path reconstruction
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    vector<vector<pair<int,long long>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b; long long w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});  // roads are two-way
    }
    const long long INF = LLONG_MAX;
    vector<long long> dist(n + 1, INF);
    vector<int> par(n + 1, -1);
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        auto [d, v] = pq.top(); pq.pop();
        if (d != dist[v]) continue;  // stale entry
        for (auto [u, w] : adj[v])
            if (d + w < dist[u]) { dist[u] = d + w; par[u] = v; pq.push({dist[u], u}); }
    }
    if (dist[t] == INF) { cout << -1 << "\n"; return 0; }
    vector<int> path;
    for (int v = t; v != -1; v = par[v]) path.push_back(v);
    reverse(path.begin(), path.end());
    cout << dist[t] << "\n";
    for (size_t i = 0; i < path.size(); i++) cout << path[i] << (i + 1 < path.size() ? ' ' : '\n');
}
