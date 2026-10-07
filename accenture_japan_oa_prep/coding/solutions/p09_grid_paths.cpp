// P09 - Grid paths with obstacles, moving only right or down (DP mod 1e9+7)
#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1'000'000'007;

int main() {
    int R, C;
    cin >> R >> C;
    vector<string> g(R);
    for (auto &row : g) cin >> row;
    vector<long long> dp(C, 0);  // rolling 1-D row: dp[j] = ways to reach (i, j)
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++) {
            if (g[i][j] == '#') { dp[j] = 0; continue; }
            if (i == 0 && j == 0) { dp[j] = 1; continue; }
            if (j > 0) dp[j] = (dp[j] + dp[j - 1]) % MOD;  // dp[j] already holds the value from the row above
        }
    cout << dp[C - 1] << "\n";
}
