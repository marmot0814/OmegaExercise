#include <bits/stdc++.h>
using namespace std;
int main() {
    int t, kase = 0; cin >> t; while (t--) {
        cout << "Case " << ++kase << ": ";
        int n; cin >> n;
        string s; cin >> s;
        int ans = 0;
        for (int i = 0 ; i < n ; i++) {
            if (s[i] == '.')
                ans++, i += 2;
        }
        cout << ans << '\n';
    }
}
