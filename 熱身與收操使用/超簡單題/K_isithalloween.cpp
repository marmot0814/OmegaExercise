#include <bits/stdc++.h>
using namespace std;
int main() {
    string s; int n; cin >> s >> n;
    if ((s[0] == 'O' && n == 31) || (s[0] == 'D' && n == 25)) {
        cout << "yup\n";
    } else {
        cout << "nope\n";
    }
}
