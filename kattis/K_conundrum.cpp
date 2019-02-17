#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;
    string base = "PER";
    int ans = 0;
    for (int i = 0 ; i < (int)s.size() ; i++)
        ans += s[i] != base[i % 3];
    cout << ans << '\n';
}
