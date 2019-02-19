#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; bool first = true; while (cin >> s) {
        if (first) first = false; else cout << ' ';
        for (int i = 0 ; i < (int)s.size() ; i++) {
            cout << s[i];
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                i += 2;
        }
    }
    cout << '\n';
}
