#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        string s; cin >> s;
        int n = sqrt(s.size()) + eps;
        vector<vector<char> > G(n, vector<char>(n));
        for (int i = 0 ; i < (int)s.size() ; i++)
            G[i / n][i % n] = s[i];
        for (int i = n - 1 ; ~i ; i--)
            for (int j = 0 ; j < n ; j++)
                cout << G[j][i];
        cout << '\n';
    }
}
