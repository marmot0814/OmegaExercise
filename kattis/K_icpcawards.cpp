#include <bits/stdc++.h>
using namespace std;
typedef pair<string, string> pss;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    set<string> app;
    vector<pss> ans;
    int n; cin >> n; while (n--) {
        string u, name;
        cin >> u >> name;
        if (app.count(u)) continue;
        app.insert(u);
        ans.push_back({u, name});
        if ((int)app.size() == 12)
            break;
    }
    for (auto &p : ans)
        cout << p.first << ' ' << p.second << '\n';
}
