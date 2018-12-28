#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int x; cin >> x;
        int ans = abs((x * 567 / 9 + 7492) * 235 / 47 - 498);
        cout << ans / 10 % 10 << '\n';
    }
}
