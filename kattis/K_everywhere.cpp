#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        set<string> app;
        for (int i = 0 ; i < n ; i++) {
            string name; cin >> name;
            app.insert(name);
        }
        cout << app.size() << '\n';
    }
}
