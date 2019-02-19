#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t, kase = 0; cin >> t; while (t--) {
        cout << "Case #" << ++kase << ": ";
        int n; cin >> n;
        set<int> app;
        for (int i = 0 ; i < n ; i++) {
            int v; cin >> v;
            if (app.count(v))
                app.erase(v);
            else
                app.insert(v);
        }
        cout << *app.begin() << '\n';
    }
}
