#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int sum = 0;
    int t; cin >> t; while (t--) {
        string s; int x;
        cin >> s;
        if (s[0] == 'd') {
            cin >> x;
            sum += x;
        } else
            cout << sum << '\n';
    }
}
