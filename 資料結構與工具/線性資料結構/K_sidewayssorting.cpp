#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    bool first = true;
    int n, m; while (cin >> n >> m && (n || m)) {
        if (first) first = false; else cout << '\n';
        vector<string> data(m);
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                char c; cin >> c;
                data[j] += c;
            }
        }
        sort(data.begin(), data.end(), [](string a, string b) {
            for (auto &c : a) c = tolower(c);
            for (auto &c : b) c = tolower(c);
            return a < b;
        });
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++)
                cout << data[j][i];
            cout << '\n';
        }
    }
}
