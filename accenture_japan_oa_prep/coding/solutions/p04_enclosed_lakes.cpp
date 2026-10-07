// P04 - Enclosed Lakes (connected components with a border condition)
#include <bits/stdc++.h>
using namespace std;

int R, C;
vector<string> g;
vector<vector<bool>> seen;

// Iterative DFS (avoids stack overflow on 1000x1000 grids). Returns {size, touchesBorder}.
pair<int,bool> explore(int sr, int sc) {
    int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
    stack<pair<int,int>> st;
    st.push({sr, sc});
    seen[sr][sc] = true;
    int size = 0;
    bool border = false;
    while (!st.empty()) {
        auto [r, c] = st.top(); st.pop();
        size++;
        if (r == 0 || c == 0 || r == R - 1 || c == C - 1) border = true;
        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d], nc = c + dc[d];
            if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if (g[nr][nc] != 'W' || seen[nr][nc]) continue;
            seen[nr][nc] = true;
            st.push({nr, nc});
        }
    }
    return {size, border};
}

int main() {
    cin >> R >> C;
    g.resize(R);
    for (auto &row : g) cin >> row;
    seen.assign(R, vector<bool>(C, false));
    int lakes = 0, largest = 0;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (g[i][j] == 'W' && !seen[i][j]) {
                auto [sz, border] = explore(i, j);
                if (!border) { lakes++; largest = max(largest, sz); }
            }
    cout << lakes << " " << largest << "\n";
}
