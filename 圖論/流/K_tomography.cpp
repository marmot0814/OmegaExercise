#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<int> v1(n), v2(m);
    for (auto &v : v1) cin >> v;
    for (auto &v : v2) cin >> v;
    sort(v1.rbegin(), v1.rend());
    sort(v2.rbegin(), v2.rend());
    for (auto &v : v1) {
        for (int i = 0 ; i < v ; i++)
            v2[i]--;
        sort(v2.rbegin(), v2.rend());
    }
    bool ok = true;
    for (auto &v : v2)
        if (v != 0)
            ok = false;
    cout << (ok ? "Yes\n" : "No\n");
}
