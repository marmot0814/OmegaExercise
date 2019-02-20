#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    vector<vector<char> > G(8, vector<char>(8));
    for (auto &vv : G)
        for (auto &v : vv)
            cin >> v;
    vector<bool> r(8, false), c(8, false), add(15, false), minus(15, false);
    int cnt = 0;
    bool ok = true;
    for (int i = 0 ; i < 8 ; i++) {
        for (int j = 0 ; j < 8 ; j++) {
            if (G[i][j] == '.') 
                continue;
            cnt++;
            if (r[i] || c[j] || add[i + j] || minus[i - j + 7])
                ok = false;
            r[i] = c[j] = add[i + j] = minus[i - j + 7] = true;
        }
    }
    if (ok && cnt == 8)
        cout << "valid\n";
    else
        cout << "invalid\n";


}
