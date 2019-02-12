#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
int solve(int u, int p, vvi &G, int ratio) {
    vector<int> res;
    for (auto &v : G[u]) {
        if (v == p) continue;
        res.push_back(solve(v, u, G, ratio));
    }
    sort(res.begin(), res.end());
    int need = ceil(res.size() / 100. * ratio), sum = 0;
    if (need == 0) return 1;
    for (int i = 0 ; i < need ; i++)
        sum += res[i];
    return sum;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, t; while (cin >> n >> t && n) {
        vvi G(n + 1);
        for (int i = 1 ; i <= n ; i++) {
            int v; cin >> v;
            G[v].push_back(i);
        }
        cout << solve(0, -1, G, t) << '\n';
    }
}
