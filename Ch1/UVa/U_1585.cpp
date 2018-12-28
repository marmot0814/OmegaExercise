#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        string s; cin >> s;
        int ans = 0, cnt = 0;
        for (auto &c : s) {
            if (c == 'O')
                cnt++;
            else
                cnt = 0;
            ans += cnt;
        }
        cout << ans << '\n';
    }
}
