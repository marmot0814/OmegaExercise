#include <bits/stdc++.h>
using namespace std;
map<string, int> ID;
int getID(string s) {
    int sz = ID.size();
    if (!ID.count(s))
        ID[s] = sz;
    return ID[s];
}
int main() {
    int n, kase = 0; while (cin >> n) {
        if (kase++) cout << '\n';
        ID.clear();
        vector<string> IDs;
        for (int i = 0 ; i < n ; i++) {
            string s; cin >> s;
            getID(s);
            IDs.push_back(s);
        }
        vector<int> ans(n, 0);
        for (int i = 0 ; i < n ; i++) {
            string s; cin >> s;
            int total, m; cin >> total >> m;
            if (!m) continue;
            ans[getID(s)] -= (total / m) * m;
            for (int j = 0 ; j < m ; j++) {
                string t; cin >> t;
                ans[getID(t)] += total / m;
            }
        }
        for (int i = 0 ; i < n ; i++)
            cout << IDs[i] << ' ' << ans[i] << '\n';
        
    }
}
