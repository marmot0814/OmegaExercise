#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        vector<int> data(n);
        for (auto &v : data)
            cin >> v;
        sort(data.begin(), data.end());
        cout << 2 * (data.back() - data.front()) << '\n';
    }
}
