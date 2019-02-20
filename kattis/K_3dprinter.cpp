#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    int ans = 0;
    while ((1 << ans) < n) ans++;
    cout << ans + 1 << '\n';
}
