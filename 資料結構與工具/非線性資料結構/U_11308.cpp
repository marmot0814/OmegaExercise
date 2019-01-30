#include <bits/stdc++.h>
using namespace std;
typedef pair<int, string> psi;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string name, tmp;
    int t; cin >> t; while (t--) {
        getline(cin, name); getline(cin, name);
        for (auto &c : name) c = toupper(c);
        cout << name << '\n';
        int n, m, b; cin >> n >> m >> b;
        map<string, int> ing;
        while (n--) {
            int val; cin >> name >> val;
            ing[name] = val;
        }
        vector<psi> data(m);
        while (m--) {
            getline(cin, name);
            getline(cin, name);
            data[m].second = name;
            int q; cin >> q;
            while (q--) {
                int val; cin >> name >> val;
                data[m].first += val * ing[name];
            }
        }
        sort(data.begin(), data.end());
        bool none = true;
        for (auto &p : data) {
            if (p.first > b) continue;
            cout << p.second << '\n';
            none = false;
        }
        if (none) cout << "Too expensive!\n";
        cout << '\n';
    }
}
