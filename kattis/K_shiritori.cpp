#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<string> data(n);
    for (auto &s : data)
        cin >> s;
    set<string> app;
    app.insert(data[0]);
    for (int i = 1 ; i < (int)data.size() ; i++) {
        if (data[i - 1].back() != data[i].front()) {
            cout << "Player " << i % 2 + 1 << " lost\n";
            return 0;
        }
        if (app.count(data[i])) {
            cout << "Player " << i % 2 + 1 << " lost\n";
            return 0;
        }
        app.insert(data[i]);
    }
    cout << "Fair Game\n";
}
