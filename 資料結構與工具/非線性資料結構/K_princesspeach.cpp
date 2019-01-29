#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<bool> cnt(205, false);
    for (int i = 0 ; i < m ; i++) {
        int num; cin >> num;
        cnt[num] = true;
    }
    int ans = 0;
    for (int i = 0 ; i < n ; i++) {
        if (cnt[i]) {
            ans++;
            continue;
        }
        cout << i << '\n';
    }
    cout << "Mario got " << ans << " of the dangerous obstacles.\n";
}
