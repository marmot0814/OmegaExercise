#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        string s; cin >> s;
        if (s == "1" || s == "4" || s == "78")
            cout << "+\n";
        else if (s[s.size() - 1] == '5' && s[s.size() - 2] == '3')
            cout << "-\n";
        else if (s[s.size() - 1] == '4' && s[0] == '9')
            cout << "*\n";
        else if (s[0] == '1' && s[1] == '9' && s[2] == '0')
            cout << "?\n";
    }
}
