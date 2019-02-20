#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    set<string> app;
    int t; cin >> t; while (t--) {
        string op, name; cin >> op >> name;
        if ((int)op.size() == 5) {
            cout << name << " entered";
            if (app.count(name))
                cout << " (ANOMALY)";
            app.insert(name);
        } else {
            cout << name << " exited";
            if (app.count(name))
                app.erase(name);
            else
                cout << " (ANOMALY)";
        }
        cout << '\n';
    }
}
