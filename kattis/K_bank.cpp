#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, t; cin >> n >> t;
    vector<pii> data;
    for (int i = 0 ; i < n ; i++) {
        int x, y; cin >> x >> y;
        data.push_back({y, -x});
    }
    sort(data.begin(), data.end());
    multiset<int> app;
    for (int i = 0 ; i < n ; i++) {
        if ((int)app.size() <= data[i].first)
            app.insert(-data[i].second);
        else if ((int)app.size() == data[i].first + 1 && *app.begin() < -data[i].second) {
            app.erase(app.begin());
            app.insert(-data[i].second);
        }
    }
    int ans = 0;
    for (auto &v : app)
        ans += v;
    cout << ans << '\n';
}
