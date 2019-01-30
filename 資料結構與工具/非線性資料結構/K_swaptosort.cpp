#include <bits/stdc++.h>
using namespace std;
vector<int> pa;
int find(int x) { return pa[x] == x ? x : pa[x] = find(pa[x]); }
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    pa.resize(n + 1);
    for (int i = 1 ; i <= n ; i++)
        pa[i] = i;
    for (int i = 0 ; i < k ; i++) {
        int u, v; cin >> u >> v;
        int x = find(u);
        int y = find(v);
        if (x == y) continue;
        pa[x] = y;
    }
    bool ok = true;
    for (int i = 1 ; i <= n / 2 ; i++) {
        int x = find(i);
        int y = find(n - i + 1);
        if (x != y)
            ok = false;
    }
    if (ok) cout << "Yes\n";
    else cout << "No\n";
}
