#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    vector<pair<int, int> > data;
    for (int i = 0 ; i < 2 ; i++) {
        int x, y; cin >> x >> y;
        data.push_back({x, y});
    }
    for (int i = 0 ; i < 3 ; i++) {
        int t; cin >> t; t--;
        int ans = 0;
        for (int j = 0 ; j < 2 ; j++) {
            auto &p = data[j];
            ans += (t % (p.first + p.second) < p.first);
        }
        if (ans == 0)
            cout << "none\n";
        if (ans == 1)
            cout << "one\n";
        if (ans == 2)
            cout << "both\n";
    }
}
