#include <bits/stdc++.h>
using namespace std;
typedef pair<int, string> pis;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        map<string, int> cnt;
        for (int i = 0 ; i < n ; i++) {
            string name; int num;
            cin >> name >> num;
            cnt[name] += num;
        }
        vector<pis> data;
        for (auto &p : cnt)
            data.push_back({-p.second, p.first});
        sort(data.begin(), data.end());
        cout << data.size() << '\n';
        for (auto &p : data)
            cout << p.second << ' ' << -p.first << '\n';
    }
}
