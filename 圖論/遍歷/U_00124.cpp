#include <bits/stdc++.h>
using namespace std;
map<char, int> ID;
vector<char> name;
int getID(char c) {
    int sz = ID.size();
    if (!ID.count(c))
        ID[c] = sz;
    return ID[c];
}
vector<vector<int> > G;
vector<int> ind, trace;
vector<bool> inTrace;
vector<string> ans;
void dfs(int u) {
    if (trace.size() == G.size()) {
        string output = "";
        for (auto &v : trace)
            output += name[v];
        ans.push_back(output);
        return ;
    }
    for (int i = 0 ; i < (int)name.size() ; i++) {
        if (inTrace[i] || ind[i]) continue;
        for (auto &v : G[i])
            ind[v]--;
        trace.push_back(i);
        inTrace[i] = true;
        dfs(i);
        for (auto &v : G[i])
            ind[v]++;
        trace.pop_back();
        inTrace[i] = false;
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    bool f = true;
    string input; while (getline(cin, input)) {
        if (f) f = false; else cout << '\n';
        ID.clear(); name.clear();
        stringstream ss; ss << input;
        char tmp_c; while (ss >> tmp_c) 
            name.push_back(tmp_c), getID(tmp_c);
        ss.clear(); getline(cin, input); ss << input;
        G.clear(); G.resize(name.size());
        ind.clear(); ind.resize(name.size(), 0);
        char u, v; while (ss >> u >> v) {
            G[getID(u)].push_back(getID(v));
            ind[getID(v)]++;
        }
        trace.clear(); ans.clear(); inTrace.clear();
        inTrace.resize(name.size(), false);
        for (int i = 0 ; i < (int)name.size() ; i++) {
            if (ind[i]) continue;
            for (auto &v : G[i])
                ind[v]--;
            trace.push_back(i);
            inTrace[i] = true;
            dfs(i);
            for (auto &v : G[i])
                ind[v]++;
            trace.pop_back();
            inTrace[i] = false;
        }
        sort(ans.begin(), ans.end());
        for (auto &s : ans)
            cout << s << '\n';
    }
}
