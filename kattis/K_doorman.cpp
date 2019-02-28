#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    int cnt = 0, ans = 0;
    for (int i = 0 ; i < (int)s.size() ; i++) {
        if (abs(cnt) < n) {
            if (s[i] == 'M') cnt++;
            else cnt--;
            ans++;
        }
    }
    cout << ans << '\n';
}
