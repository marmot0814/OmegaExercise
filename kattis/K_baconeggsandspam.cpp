#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; while (cin >> n && n) {
        string s; getline(cin, s);
        map<string, vector<string> > data;
        for (int i = 0 ; i < n ; i++) {
            getline(cin, s);
            stringstream ss; ss << s;
            string name; ss >> name;
            string tmp; while (ss >> tmp) data[tmp].push_back(name);
        }
        for (auto &p : data) {
            cout << p.first;
            sort(p.second.begin(), p.second.end());
            for (auto &str : p.second)
                cout << ' ' << str;
            cout << '\n';
        }
        cout << '\n';
    }
}
