#include <bits/stdc++.h>
using namespace std;
vector<bool> ans, vis;
vector<vector<int> > force, outgoing;
void dfs(int u, int k) {
    if (vis[u]) return ;
    vis[u] = true;
    ans[u] = (force[u].size() == 0);
    for (auto &v : force[u])
        dfs(v, k);
    if (k == 0) return ;
    for (auto &v : outgoing[u])
        dfs(v, k - 1);
}
int main() {
    int n, m; cin >> n >> m;
    force.clear(); force.resize(n);
    outgoing.clear(); outgoing.resize(n);
    while (m--) {
        int a, b; cin >> a >> b;
        if (a > 0) {
            a--, b--;
            outgoing[a].push_back(b);
        } else {
            a = -a;
            a--, b--;
            force[a].push_back(b);
        }
    }
    ans.clear(); ans.resize(n, false);
    vis.clear(); vis.resize(n, false);
    dfs(0, 1);
    int ans_num = 0;
    for (auto bo : ans)
        ans_num += bo;
    cout << ans_num << '\n';

}
