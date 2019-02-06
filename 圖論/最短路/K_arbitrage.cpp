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
const double INF = 1e10;
const double EPS = 1e-8;
struct Edge { int v; double w; };
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; while (cin >> n && n) {
        ID.clear(); NAME.clear();
        for (int i = 0 ; i < n ; i++) {
            string name; cin >> name;
            getID(name);
        }
        vector<vector<double> > d(n, vector<double>(n, 0));
        for (int i = 0 ; i < n ; i++) d[i][i] = 1;
        int m; cin >> m; while (m--) {
            string A, B; cin >> A >> B;
            int a, b; char c; cin >> a >> c >> b;
            d[getID(A)][getID(B)] = max(d[getID(A)][getID(B)], double(b) / double(a));
        }
        for (int k = 0 ; k < n ; k++)
            for (int i = 0 ; i < n ; i++)
                for (int j = 0 ; j < n ; j++)
                    d[i][j] = max(d[i][j], d[i][k] * d[k][j]);
        bool legal = true;
        for (int i = 0 ; i < n ; i++)
            if (d[i][i] > 1) legal = false;
        if (legal)
            cout << "OK\n";
        else
            cout << "Arbitrage\n";
    }
}

