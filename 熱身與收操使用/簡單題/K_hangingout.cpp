#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, q; cin >> n >> q;
    int cnt = 0, ans = 0;
    while (q--) {
        string s; int num;
        cin >> s >> num;
        if (s[0] == 'e') {
            if (cnt + num > n) {
                ans++;
            } else {
                cnt += num;
            }
        } else {
            cnt -= num;
        }
    }
    cout << ans << '\n';
}
