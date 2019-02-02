#include <bits/stdc++.h>
using namespace std;
map<string, int> ID;
vector<string> NAME;
int getID(string name) {
    int sz = ID.size();
    if (!ID.count(name))
        ID[name] = sz, NAME.push_back(name);
    return ID[name];
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; while (cin >> n && n) {
        ID.clear(); NAME.clear();
        string input; getline(cin, input);
        vector<vector<int> > G(n);
        vector<int> ind(n, 0);
        for (int i = 0 ; i < n ; i++) {
            getline(cin, input);
            stringstream ss; ss << input;
            string u_str; ss >> u_str;
            int u = getID(u_str);
            string v_str; while (ss >> v_str)
                G[u].push_back(getID(v_str));
            sort(G[u].begin(), G[u].end());
            G[u].erase(unique(G[u].begin(), G[u].end()), G[u].end());
            for (auto &v : G[u])
                ind[v]++;
        }
        vector<bool> inG(n, true);
        queue<int> q;
        for (int i = 0 ; i < n ; i++) {
            if (ind[i]) continue;
            q.push(i);
        }
        while (q.size()) {
            int p = q.front(); q.pop();
            inG[p] = false;
            for (auto &v : G[p]) {
                ind[v]--;
                if (ind[v]) continue;
                q.push(v);
            }
        }
        vector<string> ans;
        for (int i = 0 ; i < n ; i++) {
            if (!inG[i]) continue;
            ans.push_back(NAME[i]);
        }
        sort(ans.begin(), ans.end());
        cout << ans.size() << '\n';
        for (int i = 0 ; i < (int)ans.size() ; i++) 
            cout << ans[i] << " \n"[i == (int)ans.size() - 1];
    }
}
