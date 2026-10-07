// P05 - Longest substring with at most K distinct characters (sliding window)
#include <bits/stdc++.h>
using namespace std;

int main() {
    int k;
    string s;
    cin >> k >> s;
    array<int, 256> freq{};
    int distinct = 0, best = 0, l = 0;
    for (int r = 0; r < (int)s.size(); r++) {
        if (freq[(unsigned char)s[r]]++ == 0) distinct++;
        while (distinct > k) {
            if (--freq[(unsigned char)s[l]] == 0) distinct--;
            l++;
        }
        best = max(best, r - l + 1);
    }
    cout << best << "\n";
}
