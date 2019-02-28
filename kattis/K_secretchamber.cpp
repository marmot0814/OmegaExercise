#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;
const int SIGMA = 26;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    vector<pii> data;
    vector<vector<int> > d(SIGMA, vector<int>(SIGMA, INF));
    for (int i = 0 ; i < SIGMA ; i++)
        d[i][i] = 0;
    for (int i = 0 ; i < n ; i++) {
        char a, b; cin >> a >> b;
        d[a - 'a'][b - 'a'] = 1;
    }
    for (int k = 0 ; k < SIGMA ; k++)
        for (int i = 0 ; i < SIGMA ; i++)
            for (int j = 0 ; j < SIGMA ; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    while (q--) {
        string a, b; cin >> a >> b;
        if (a.size() != b.size()) {
            cout << "no\n";
            continue;
        }
        bool ok = true;
        for (int i = 0 ; i < (int)a.size() ; i++) {
            if (d[a[i] - 'a'][b[i] - 'a'] != INF)
                continue;
            ok = false;
            break;
        }
        if (ok)
            cout << "yes\n";
        else
            cout << "no\n";
    }
}
