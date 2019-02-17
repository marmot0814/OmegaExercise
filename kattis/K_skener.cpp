#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<vector<char> > G(n, vector<char>(m));
    for (auto &vv : G)
        for (auto &v : vv)
            cin >> v;
    for (auto &vv : G) {
        for (int i = 0 ; i < x ; i++) {
            for (auto &v : vv) 
                for (int j = 0 ; j < y ; j++)
                    cout << v;
            cout << '\n';
        }
    }
}
