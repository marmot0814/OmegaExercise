#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t, kase = 0; cin >> t; while (t--) {
        cout << "Test " << ++kase << '\n';
        int n, m; cin >> n >> m;
        vector<vector<char> > G(n, vector<char>(m));
        for (auto &vv : G)
            for (auto &v : vv)
                cin >> v;
        reverse(G.begin(), G.end());
        for (auto &vv : G)
            reverse(vv.begin(), vv.end());
        for (auto &vv : G) {
            for (auto &v : vv)
                cout << v;
            cout << '\n';
        }
    }
}
