#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int kase = 0;
    string s; while (cin >> s) {
        if (s[0] == '*')
            break;
        cout << "Case " << ++kase << ": ";
        if (s[0] == 'U') {
            cout << "Hajj-e-Asghar\n";
        } else {
            cout << "Hajj-e-Akbar\n";
        }
    }
}
