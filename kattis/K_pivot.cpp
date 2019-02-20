#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    int maxV = 0, ans = 0;
    for (int i = 1 ; i <= n ; i++) {
        int v; cin >> v;
        if (v == i && maxV < v)
            ans++;
        maxV = max(maxV, v);
    }
    cout << ans << '\n';
}
