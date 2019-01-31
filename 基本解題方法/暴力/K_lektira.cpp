#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s; string ans = s;
    for (int i = 1 ; i < (int)s.size() ; i++) {
        for (int j = i + 1 ; j < (int)s.size() ; j++) {
            string a1 = s.substr(0, i);
            string a2 = s.substr(i, j - i);
            string a3 = s.substr(j, (int)s.size() - j);
            reverse(a1.begin(), a1.end());
            reverse(a2.begin(), a2.end());
            reverse(a3.begin(), a3.end());
            ans = min(ans, a1 + a2 + a3);
        }
    }
    cout << ans << '\n';
}
