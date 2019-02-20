#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int a, b, c; cin >> a >> b >> c;
    vector<int> cnt(105, 0);
    for (int i = 0 ; i < 3 ; i++) {
        int x, y; cin >> x >> y;
        for (int j = x ; j < y ; j++)
            cnt[j]++;
    }
    int ans = 0;
    for (int i = 0 ; i < 105 ; i++) {
        if (cnt[i] == 1)
            ans += cnt[i] * a;
        if (cnt[i] == 2)
            ans += cnt[i] * b;
        if (cnt[i] == 3)
            ans += cnt[i] * c;
    }
    cout << ans << '\n';
}
