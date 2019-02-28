#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int b, k, g; cin >> b >> k >> g;
    int per = k / g;
    int ans = b / per + (b % per != 0);
    if (b % per == 1 || per == 1) ans--;
    cout << ans << '\n';
}
