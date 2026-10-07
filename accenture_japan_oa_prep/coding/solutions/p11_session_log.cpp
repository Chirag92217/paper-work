// P11 - Session log (parsing + per-user state)
#include <bits/stdc++.h>
using namespace std;

int toSec(const string &t) {
    return stoi(t.substr(0, 2)) * 3600 + stoi(t.substr(3, 2)) * 60 + stoi(t.substr(6, 2));
}

int main() {
    int n;
    cin >> n;
    map<string, long long> total;   // map keeps names sorted for output
    map<string, int> openAt;        // user -> login time of the open session
    for (int i = 0; i < n; i++) {
        string t, user, action;
        cin >> t >> user >> action;
        int s = toSec(t);
        total[user];  // make sure every user appears, even with 0 seconds
        if (action == "LOGIN") {
            if (!openAt.count(user)) openAt[user] = s;  // repeated LOGIN while online is ignored
        } else if (action == "LOGOUT") {
            auto it = openAt.find(user);
            if (it != openAt.end()) { total[user] += s - it->second; openAt.erase(it); }
            // LOGOUT without an open session is ignored
        }
    }
    const int END_OF_DAY = toSec("23:59:59");
    for (auto &[user, start] : openAt) total[user] += END_OF_DAY - start;
    for (auto &[user, secs] : total) cout << user << " " << secs << "\n";
}
