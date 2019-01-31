#include <bits/stdc++.h>
using namespace std;
map<char, int> ID;
int getID(char c) {
    int sz = ID.size();
    if (!ID.count(c))
        ID[c] = sz;
    return ID[c];
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int r, c; while (cin >> r >> c && (r || c)) {
        ID.clear(); int n; cin >> n;
        vector<vector<int> > G(r, vector<int>(c + 1, false));
        for (int i = 0 ; i < n ; i++) {
            string pos, dir; cin >> pos >> dir;
            int r_idx = getID(pos[0]);
            pos = pos.substr(1, pos.size() - 1);
            stringstream ss; ss << pos;
            int c_idx; ss >> c_idx;
            G[r_idx][c_idx - (dir[0] == '-')] = true;
        }
        int m; cin >> m;
        vector<vector<int> > target(r);
        for (int i = 0 ; i < m ; i++) {
            string pos; cin >> pos;
            int r_idx = getID(pos[0]);
            pos = pos.substr(1, pos.size() - 1);
            stringstream ss; ss << pos;
            int c_idx; ss >> c_idx;
            target[r_idx].push_back(c_idx - 1);
        }
        for (auto &vv : target)
            sort(vv.begin(), vv.end());
        bool legal = true;
        for (int r_idx = 0 ; r_idx < r ; r_idx++) {
            for (auto &v : target[r_idx]) {
                if (G[r_idx][v] && G[r_idx][v + 1]) {
                    legal = false;
                    break;
                }
                if (!legal) break;
                if (!G[r_idx][v]) G[r_idx][v] = true;
                else G[r_idx][v + 1] = true;
            }
            if (!legal) break;
        }
        if (legal) cout << "YES\n";
        else cout << "NO\n";
    }
}
