#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, c, k; cin >> n >> c >> k;
    vector<int> data(n);
    for (auto &v : data) cin >> v;
    sort(data.begin(), data.end());
    vector<int> target; int ans = 0;
    for (auto &v : data) {
        if (target.size() == 0) {
            target.push_back(v);
        } else {
            if (target.size() == c) {
                ans++;
                target.clear();
                target.push_back(v);
            } else {
                if (v - target.front() > k) {
                    ans++;
                    target.clear();
                    target.push_back(v);
                } else {
                    target.push_back(v);
                }
            }
        }
    }
    if (target.size())
        ans++;
    cout << ans << '\n';

}
