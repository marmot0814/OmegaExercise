#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;
    int ans = 0; char pos = s[0];
    for (int i = 1 ; i < (int)s.size() ; i++) {
        if (pos != s[i])
            ans++, pos = s[i];
        if (pos != 'U') pos = 'U', ans++;
    }
    cout << ans << '\n';
    ans = 0, pos = s[0];
    for (int i = 1 ; i < (int)s.size() ; i++) {
        if (pos != s[i])
            ans++, pos = s[i];
        if (pos != 'D') pos = 'D', ans++;
    }
    cout << ans << '\n';
    ans = 0, pos = s[0];
    for (int i = 1 ; i < (int)s.size() ; i++) {
        if (pos != s[i])
            ans++, pos = s[i];
    }
    cout << ans << '\n';
}
