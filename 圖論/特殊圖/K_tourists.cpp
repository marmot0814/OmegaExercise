#include <bits/stdc++.h>
using namespace std;
void flatten(int u, int p, vector<vector<int> > &G, vector<int> &dep, vector<int> &f_G, vector<int> &inS) {
    inS[u] = f_G.size();
    f_G.push_back(u);
    for (auto &v : G[u]) {
        if (v == p) continue;
        dep[v] = dep[u] + 1;
        flatten(v, u, G, dep, f_G, inS);
        f_G.push_back(u);
    }
}
struct SparseTable{
    vector<vector<int> > data, idx;
    SparseTable(vector<int> &arr, int n){
        int lgN = __lg(n) + 5;
        data.resize(lgN);
        idx.resize(lgN);
        for (int i = 0 ; i < n ; i++) data[0].push_back(arr[i]), idx[0].push_back(i);
        for (int h = 1 ; h < lgN ; h++){
            int len = 1 << (h-1), i = 0;
            for (; i + len < n ; i++) {
                idx[h].push_back(idx[h - 1][i + len * (data[h - 1][i] > data[h - 1][i + len])]);
                data[h].push_back(min(data[h-1][i], data[h-1][i+len]));
            }
            if (!i) break;
            for (; i < n ; i++)
                data[h].push_back(data[h-1][i]), idx[h].push_back(idx[h - 1][i]);
        }
    }
    int query(int l, int r){
        int h = __lg(r - l);
        int len = 1 << h;
        return data[h][l] < data[h][r - len] ? idx[h][l] : idx[h][r - len];
    }
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<vector<int> > G(n);
    for (int i = 0 ; i < n - 1 ; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<int> dep(n, 0), inS(n, -1), f_G;
    flatten(0, 0, G, dep, f_G, inS);
    vector<int> arr;
    for (auto &v : f_G)
        arr.push_back(dep[v]);
    SparseTable *sol = new SparseTable(arr, 2 * n - 1);
    long long ans = 0;
    for (int u = 1 ; u <= n ; u++) {
        for (int v = u * 2 ; v <= n ; v += u) {
            int lca = sol->query(min(inS[u - 1], inS[v - 1]), max(inS[u - 1], inS[v - 1]));
            ans += dep[u - 1] + dep[v - 1] - 2 * dep[f_G[lca]] + 1;
        }
    }
    cout << ans << '\n';

}
