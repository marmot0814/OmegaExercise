#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        string a, b; cin >> a >> b;
        cout << a << '\n' << b << '\n';
        for (int i = 0 ; i < (int)a.size() ; i++)
            cout << "*."[a[i] == b[i]];
        cout << '\n' << '\n';
    }
}
