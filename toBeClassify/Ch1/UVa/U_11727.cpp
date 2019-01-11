#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int kase = 0;
    int t; cin >> t; while (t--) {
        vector<int> data(3);
        for (auto &v : data)
            cin >> v;
        sort(data.begin(), data.end());
        cout << "Case " << ++kase << ": " << data[1] << '\n';
    }
}
