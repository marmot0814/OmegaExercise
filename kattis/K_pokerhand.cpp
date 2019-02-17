#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    map<char, int> cnt;
    for (int i = 0 ; i < 5 ; i++) {
        string s; cin >> s;
        cnt[s[0]]++;
    }
    int ans = 0;
    for (auto &p : cnt)
        ans = max(ans, p.second);
    cout << ans << '\n';
}
