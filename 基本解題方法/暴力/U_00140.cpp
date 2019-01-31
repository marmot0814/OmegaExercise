#include <bits/stdc++.h>
using namespace std;
map<char, int> ID;
vector<int> NAME;
int getID(char c) {
    int sz = ID.size();
    if (!ID.count(c))
        ID[c] = sz, NAME.push_back(c);
    return ID[c];
}
char getName(int id) {
    return NAME[id];
}
const int INF = 0x3f3f3f3f;
int main() {
    string input; while (getline(cin, input)) {
        if (input[0] == '#') break;
        ID.clear(); NAME.clear();
        for (auto &c : input)
            if (!isalpha(c))
                c = ' ';
        stringstream ss; ss << input;
        vector<vector<int> > G(10);
        string node, adj;
        while (ss >> node >> adj) {
            for (auto &c : adj) {
                G[getID(node[0])].push_back(getID(c));
                G[getID(c)].push_back(getID(node[0]));
            }
        }
        G.resize(ID.size());
        vector<int> data(ID.size());
        int idx = 0;
        for (auto &v : data)
            v = idx++;
        vector<int> ans; int minV = INF;
        do {
            vector<int> rank(data.size());
            idx = 0;
            for (auto &v : data)
                rank[v] = idx++;
            int maxV = 0;
            for (int i = 0 ; i < (int)G.size() ; i++)
                for (auto &v : G[i])
                    maxV = max(maxV, abs(rank[i] - rank[v]));
            if (maxV < minV) {
                minV = maxV;
                ans = data;
            } else if (maxV == minV) {
                string cur;
                for (auto &v : ans)
                    cur += getName(v);
                string tar;
                for (auto &v : data)
                    tar += getName(v);
                if (tar < cur)
                    ans = data;
            }
        } while (next_permutation(data.begin(), data.end()));
        for (auto &v : ans)
            cout << getName(v) << ' ';
        cout << "-> " << minV << '\n';
    }
}
