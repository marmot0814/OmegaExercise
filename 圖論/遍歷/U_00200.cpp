#include <bits/stdc++.h>
using namespace std;
map<char, int> ID;
vector<char> name, topo;
int getID(char c) {
    int sz = ID.size();
    if (!ID.count(c))
        ID[c] = sz, name.push_back(c);
    return ID[c];
}
vector<vector<int> > G;
vector<bool> vis;
void dfs(int u) {
    vis[u] = true;
    for (auto &v : G[u])
        if (!vis[v])
            dfs(v);
    topo.push_back(name[u]);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; while (cin >> s) { 
        vector<string> data{s};
        while (cin >> s) {
            if (s[0] == '#') break;
            data.push_back(s);
        }
        ID.clear(); name.clear();
        G.clear(); G.resize(200);
        for (int i = 1 ; i < (int)data.size() ; i++) {
            string a = data[i - 1], b = data[i];
            for (int j = 0 ; j < (int)min(a.size(), b.size()) ; j++) {
                if (a[j] == b[j]) continue;
                G[getID(a[j])].push_back(getID(b[j]));
                break;
            }
        }
        G.resize(ID.size()); topo.clear();
        vis.clear(); vis.resize(ID.size(), false);
        for (int i = 0 ; i < (int)ID.size() ; i++) {
            if (vis[i]) continue;
            dfs(i);
        }
        reverse(topo.begin(), topo.end());
        for (auto &c : topo)
            cout << c;
        cout << '\n';
    }
}
