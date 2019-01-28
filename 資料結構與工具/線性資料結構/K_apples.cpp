#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<char> > G(n, vector<char>(m));
    for (auto &vv : G)
        for (auto &c : vv)
            cin >> c;
    for (int j = 0 ; j < m ; j++) {
        int pos = n - 1;
        for (int i = n - 1 ; ~i ; i--) {
            if (G[i][j] == '#')
                pos = i - 1;
            else if (G[i][j] == 'a') {
                swap(G[i][j], G[pos][j]);
                pos--;
                while (pos - 1 >= 0 && G[pos - 1][j] == '#')
                    pos--;
            }
        }
    }
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) 
            cout << G[i][j];
        cout << '\n';
    }
}
