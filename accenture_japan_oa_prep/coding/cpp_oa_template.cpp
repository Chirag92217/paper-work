// Starter template to type out (or paste) at the start of the OA.
// Practice typing it from memory so it costs you nothing on the day.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int dr[4] = {-1, 1, 0, 0};  // grid moves: up, down, left, right
const int dc[4] = {0, 0, -1, 1};

bool inside(int r, int c, int R, int C) { return r >= 0 && r < R && c >= 0 && c < C; }

// Grid BFS from one start cell; returns distance matrix (-1 = unreachable). '#' is a wall.
vector<vector<int>> gridBfs(const vector<string> &g, int sr, int sc) {
    int R = g.size(), C = g[0].size();
    vector<vector<int>> d(R, vector<int>(C, -1));
    queue<pair<int,int>> q;
    d[sr][sc] = 0;
    q.push({sr, sc});
    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k], nc = c + dc[k];
            if (inside(nr, nc, R, C) && g[nr][nc] != '#' && d[nr][nc] == -1) {
                d[nr][nc] = d[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
    return d;
}

// Disjoint Set Union (connected components, Kruskal)
struct DSU {
    vector<int> p, sz;
    DSU(int n) : p(n), sz(n, 1) { iota(p.begin(), p.end(), 0); }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        p[b] = a; sz[a] += sz[b];
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // read input -> solve -> print
}
