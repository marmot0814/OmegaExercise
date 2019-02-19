#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t, ans = 0; cin >> t; while (t--) {
        string s; cin >> s; ans++;
        for (int i = 1 ; i < (int)s.size() ; i++) {
            if (s[i - 1] == 'C' && s[i] == 'D') {
                ans--; break;
            }
        }
    }
    cout << ans << '\n';
}

