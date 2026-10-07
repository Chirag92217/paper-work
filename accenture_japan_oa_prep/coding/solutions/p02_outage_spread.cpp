// P02 - Outage Spread (multi-source BFS)
#include <bits/stdc++.h>
using namespace std;

int main() {
    int R, C;
    cin >> R >> C;
    vector<string> g(R);
    for (auto &row : g) cin >> row;

    vector<vector<int>> dist(R, vector<int>(C, -1));
    queue<pair<int,int>> q;
    int healthy = 0;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++) {
            if (g[i][j] == 'X') { dist[i][j] = 0; q.push({i, j}); }  // all sources start together
            else if (g[i][j] == 'S') healthy++;
        }

    int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
    int ans = 0;
    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d], nc = c + dc[d];
            if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if (g[nr][nc] != 'S' || dist[nr][nc] != -1) continue;
            dist[nr][nc] = dist[r][c] + 1;
            ans = max(ans, dist[nr][nc]);
            healthy--;
            q.push({nr, nc});
        }
    }
    cout << (healthy == 0 ? ans : -1) << "\n";
}
