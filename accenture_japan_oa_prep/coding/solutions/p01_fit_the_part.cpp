// P01 - Fit the Part (grid + rotations + dedup)
// Count distinct placements of a rotatable part on free cells of a floor grid.
#include <bits/stdc++.h>
using namespace std;

typedef vector<pair<int,int>> Shape;

// Shift cells so the smallest row and column are 0, then sort -> canonical form.
Shape normalize(Shape s) {
    int mr = INT_MAX, mc = INT_MAX;
    for (auto &p : s) { mr = min(mr, p.first); mc = min(mc, p.second); }
    for (auto &p : s) { p.first -= mr; p.second -= mc; }
    sort(s.begin(), s.end());
    return s;
}

// 90 degree clockwise rotation: (r, c) -> (c, -r), then re-normalize.
Shape rotate90(const Shape &s) {
    Shape t;
    for (auto &p : s) t.push_back({p.second, -p.first});
    return normalize(t);
}

int main() {
    int R, C;
    cin >> R >> C;
    vector<string> g(R);
    for (auto &row : g) cin >> row;
    int h, w;
    cin >> h >> w;
    Shape base;
    for (int i = 0; i < h; i++) {
        string row; cin >> row;
        for (int j = 0; j < w; j++) if (row[j] == '*') base.push_back({i, j});
    }
    base = normalize(base);  // trims empty border rows/cols of the pattern

    // Distinct rotations only: a symmetric part must not be counted twice.
    set<Shape> rots;
    Shape cur = base;
    for (int k = 0; k < 4; k++) { rots.insert(cur); cur = rotate90(cur); }

    long long count = 0;
    for (const Shape &s : rots) {
        for (int r = 0; r < R; r++)
            for (int c = 0; c < C; c++) {
                bool ok = true;
                for (auto &p : s) {
                    int x = r + p.first, y = c + p.second;
                    if (x >= R || y >= C || g[x][y] != '.') { ok = false; break; }
                }
                if (ok) count++;
            }
    }
    cout << count << "\n";
}
