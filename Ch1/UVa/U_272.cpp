#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; bool state = false;
    while (getline(cin, s)) {
        for (auto &c : s) {
            if (c == '\"' && !state) {
                cout << "``";
                state = true;
            } else if (c == '\"' && state) {
                cout << "\'\'";
                state = false;
            } else {
                cout << c;
            }
        }
        cout << '\n';
    }
}
