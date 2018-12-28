#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int kase = 0;
    string s; while (cin >> s) {
        if (s[0] == '#')
            break;
        cout << "Case " << ++kase << ": ";
        if (s == "HELLO")
            cout << "ENGLISH\n";
        else if (s == "HOLA")
            cout << "SPANISH\n";
        else if (s == "HALLO")
            cout << "GERMAN\n";
        else if (s == "BONJOUR")
            cout << "FRENCH\n";
        else if (s == "CIAO")
            cout << "ITALIAN\n";
        else if (s == "ZDRAVSTVUJTE")
            cout << "RUSSIAN\n";
        else
            cout << "UNKNOWN\n";
    }
}
