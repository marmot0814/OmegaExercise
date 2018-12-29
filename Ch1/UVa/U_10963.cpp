#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        vector<int> data(n);
        for (auto &v : data) {
            int x, y; cin >> x >> y;
            v = x - y;
        }
        bool legal = true;
        for (int i = 1 ; i < n ; i++) {
            if (data[i] != data[i - 1]) {
                legal = false;
                break;
            }
        }
        if (legal)
            cout << "yes\n";
        else
            cout << "no\n";
        if (t)
            cout << '\n';
    }
}
