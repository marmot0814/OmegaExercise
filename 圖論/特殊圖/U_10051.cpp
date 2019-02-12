#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
struct B {
    int c[6];
};
vector<string> NAME{"front", "back", "left", "right", "top", "bottom"};
void printPath(int u, vector<int> &pa) {
    if (u == -1) return ;
    printPath(pa[u], pa);
    cout << u / 6 + 1 << ' ' << NAME[u % 6] << '\n';
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int kase = 0, first = 1;
    int n; while (cin >> n && n) {
        if (first) first = 0; else cout << '\n';
        cout << "Case #" << ++kase << '\n';
        vector<B> data(n);
        for (auto &b : data) {
            for (int i = 0 ; i < 6 ; i++)
                cin >> b.c[i];
        }
        vector<vector<int> > G(6 * n);
        vector<int> ind(6 * n, 0);
        for (int i = 0 ; i < n ; i++)
            for (int j = i + 1 ; j < n ; j++)
                for (int _i = 0 ; _i < 6 ; _i++)
                    for (int _j = 0 ; _j < 6 ; _j++)
                        if (data[i].c[_i] == data[j].c[_j])
                            G[(6 * i + _i) ^ 1].push_back(6 * j + _j), ind[6 * j + _j]++;
        queue<int> q;
        vector<int> dp(6 * n, 0);
        vector<int> pa(6 * n, -1);
        for (int i = 0 ; i < 6 * n ; i++) {
            if (ind[i]) continue;
            q.push(i);
        }
        while (q.size()) {
            int u = q.front(); q.pop();
            for (auto &v : G[u]) {
                if (dp[v] < dp[u] + 1)
                    dp[v] = dp[u] + 1, pa[v] = u;
                if (--ind[v]) continue;
                q.push(v);
            }
        }
        int ans = 0, idx = -1;
        for (int i = 0 ; i < 6 * n ; i++)
            if (ans < dp[i])
                ans = dp[i], idx = i;
        cout << ans + 1 << '\n';
        printPath(idx, pa);
    }
}
