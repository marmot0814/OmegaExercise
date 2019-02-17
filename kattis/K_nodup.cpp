#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    set<string> app; int cnt = 0;
    string name; while (cin >> name) {
        app.insert(name);
        cnt++;
    }
    if ((int)app.size() == cnt)
        cout << "yes\n";
    else
        cout << "no\n";
}
