#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    set<string> app;
    string s; while (getline(cin, s)) {
        stringstream ss; ss << s;
        string tmp; bool first = true;
        while (ss >> tmp) {
            if (first) first = false;
            else cout << ' ';
            string toLower = tmp;
            for (auto &c : toLower)
                c = tolower(c);
            if (app.count(toLower))
                cout << '.';
            else {
                cout << tmp;
                app.insert(toLower);
            }
        }
        cout << '\n';
    }
}
