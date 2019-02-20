#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        string s; cin >> s;
        int k = 1; while (k * k < (int)s.size()) k++;
        vector<vector<char> > G(k, vector<char>(k, 0));
        int idx = 0;
        for (auto &c : s)
            G[idx / k][idx % k] = c, idx++;
        for (int j = 0 ; j < k ; j++)
            for (int i = k - 1 ; ~i ; i--)
                if (G[i][j])
                    cout << G[i][j];
        cout << '\n';
    }
}
