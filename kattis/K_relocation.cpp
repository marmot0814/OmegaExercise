#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    vector<int> data(n);
    for (auto &v : data)
        cin >> v;
    while (q--) {
        int op, a, b; cin >> op >> a >> b;
        if (op == 1)
            data[a - 1] = b;
        else
            cout << abs(data[a - 1] - data[b - 1]) << '\n';
    }
}
