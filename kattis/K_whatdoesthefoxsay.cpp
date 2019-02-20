#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; string sound; getline(cin, sound); while (t--) {
        getline(cin, sound);
        set<string> app;
        string sen;
        while (getline(cin, sen)) {
            if (sen == "what does the fox say?")
                break;
            stringstream ss; ss << sen;
            string tmp; ss >> tmp >> tmp >> tmp;
            app.insert(tmp);
        }
        stringstream ss; ss << sound;
        string tmp;
        bool first = true;
        while (ss >> tmp) {
            if (app.count(tmp))
                continue;
            if (first) first = false;
            else cout << ' ';
            cout << tmp;
        }
        cout << '\n';
    }
}
