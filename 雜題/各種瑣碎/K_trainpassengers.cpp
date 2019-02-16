#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int c, n; cin >> c >> n;
    int cnt = 0; bool legal = true;
    for (int i = 0 ; i < n ; i++) {
        int l, e, s; cin >> l >> e >> s;
        if (l > cnt) {
            legal = false;
            break;
        }
        cnt -= l - e;
        if (cnt > c) {
            legal = false;
            break;
        }
        if (s > 0 && c != cnt) {
            legal = false;
            break;
        }
    }
    if (cnt != 0)
        legal = false;
    if (legal)
        cout << "possible\n";
    else
        cout << "impossible\n";
}
