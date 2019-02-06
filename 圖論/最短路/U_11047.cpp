#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
void print(int s, int t, vector<vector<int> > &path, vector<string> &NAME) {
    if (path[s][t] == t)
        return ;
    print(s, path[s][t], path, NAME);
    cout << " " << NAME[path[s][t]];
    print(path[s][t], t, path, NAME);
}
int main() {
    int T; cin >> T; while (T--) {
        int n; cin >> n;
        map<string, int> ID;
        vector<string> NAME;
        for (int i = 0 ; i < n ; i++) {
            string name; cin >> name;
            ID[name] = i;
            NAME.push_back(name);
        }
        vector<vector<LL> > d(n, vector<LL>(n, INF));
        vector<vector<int> > path(n, vector<int>(n, -1));
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < n ; j++) {
                cin >> d[i][j]; path[i][j] = j;
                if (d[i][j] == -1)
                    d[i][j] = INF, path[i][j] = -1;
            }
        }
        for (int k = 0 ; k < n ; k++)
            for (int i = 0 ; i < n ; i++)
                for (int j = 0 ; j < n ; j++)
                    if (d[i][k] != INF && d[k][j] != INF)
                        if (d[i][k] + d[k][j] < d[i][j])
                            path[i][j] = k, d[i][j] = d[i][k] + d[k][j];
        int q; cin >> q; while (q--) {
            string name; cin >> name;
            string s, t; cin >> s >> t;
            if (d[ID[s]][ID[t]] == INF) {
                cout << "Sorry Mr " << name << " you can not go from " << s << " to " << t << "\n";
            } else {
                cout << "Mr " << name << " to go from " << s << " to " << t << ", you will receive " << d[ID[s]][ID[t]] << " euros\n";
                cout << "Path:";
                cout << s;
                print(ID[s], ID[t], path, NAME);
                cout << ' ' << t << '\n';
            }
        }
    }
}
