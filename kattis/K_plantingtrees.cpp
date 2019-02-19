#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> data(n);
    for (auto &v : data) cin >> v;
    sort(data.begin(), data.end(), [](int a, int b){ return a > b; });
    int ans = 0;
    for (int i = 0 ; i < n ; i++)
        ans = max(ans, data[i] + i + 1);
    cout << ans + 1 << '\n';
}
