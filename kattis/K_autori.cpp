#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;
    string ans;
    for (auto &c : s)
        if (isupper(c))
            ans += c;
    cout << ans << '\n';
}
