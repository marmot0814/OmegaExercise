#include <bits/stdc++.h>
using namespace std;
int main() {
    string s; cin >> s;
    for (int i = 1 ; i < (int)s.size() ; i++) {
        if (s[i - 1] == 's' && s[i] == 's') {
            cout << "hiss\n";
            return 0;
        }
    }
    cout << "no hiss\n";
}
