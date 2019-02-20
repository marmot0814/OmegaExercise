#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> data(n);
    for (auto &v : data)
        cin >> v;
    sort(data.begin(), data.end());
    reverse(data.begin(), data.end());
    int ans = 0;
    for (int i = 0 ; i < n ; i += 3) {
        ans += data[i];
        if (i + 1 < n)
            ans += data[i + 1];
    }
    cout << ans << '\n';
}
