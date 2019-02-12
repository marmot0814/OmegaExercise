#include <bits/stdc++.h>
using namespace std;
void dfs(int u, vector<vector<int> > &G) {
    while (G[u].size()) {
        int v = G[u].back();
        G[u].pop_back();
        dfs(v, G);
    }
}
int main() {
    // ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        vector<int> deg(26, 0), vis(26, 1);
        vector<vector<int> > G(26);
        for (int i = 0 ; i < n ; i++) {
            string s; cin >> s;
            deg[s.front() - 'a']--; deg[s.back()  - 'a']++;
            G[s.front() - 'a'].push_back(s.back() - 'a');
            vis[s.front() - 'a'] = vis[s.back() - 'a'] = false;
        }
        bool legal = true; int cnt = 0, s = -1;
        for (int i = 0 ; i < 26 && legal ; i++) {
            if (abs(deg[i]) > 1) legal = false;
            else if (abs(deg[i]) == 1) cnt++;
        }
        if (cnt > 2) legal = false;
        for (int i = 0 ; i < 26 ; i++) {
            if (vis[i]) continue;
            if ((cnt == 2 && deg[i] == -1) || cnt == 0) {
                s = i; break;
            }
        }
        if (s != -1) dfs(s, G);
        for (int i = 0 ; i < 26 ; i++)
            if (G[i].size())
                legal = false;
        if (legal) cout << "Ordering is possible.\n";
        else cout << "The door cannot be opened.\n";
    }
}
