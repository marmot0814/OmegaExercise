#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, kase = 0; while (cin >> n && n) {
        cout << "List " << ++kase << ":\n";
        string s; getline(cin, s);
        map<string, int> cnt;
        while (n--) {
            getline(cin, s);
            stringstream ss; ss << s;
            string name; while (ss >> name);
            for (auto &c : name)
                c = tolower(c);
            cnt[name]++;
        }
        for (auto &p : cnt)
            cout << p.first << " | " << p.second << '\n';
    }
}
