#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; while (cin >> n && ~n) {
        vector<vector<int> > G(n);
        vector<LL> w(n);
        for (int i = 0 ; i < n ; i++) {
            cin >> w[i]; w[i] *= -1;
            int m; cin >> m;
            while (m--) {
                int v; cin >> v; v--;
                G[i].push_back(v);
            }
        }
        deque<int> q; q.push_back(0);
        vector<LL> d(n, INF); d[0] = -100;
        vector<int> updateTime(n, 0);
        vector<bool> inq(n, false); inq[0] = true;
        while (q.size()) {
            int u;
            if (d[q.front()] < d[q.back()])
                u = q.front(), q.pop_front();
            else
                u = q.back(), q.pop_back();
            inq[u] = false;
            if (updateTime[u] >= n)
                d[u] = -INF;
            for (auto &v : G[u]) {
                if (d[v] == -INF)
                    continue;
                if (d[u] == -INF)
                    d[v] = -INF, q.push_back(v);
                else if (d[u] + w[v] < d[v]) {
                    d[v] = d[u] + w[v];
                    updateTime[v]++;
                    if (d[v] >= 0)
                        continue;
                    if (inq[v])
                        continue;
                    q.push_back(v);
                    inq[v] = true;
                }
            }
        }
        if (d[n - 1] < 0)
            cout << "winnable\n";
        else
            cout << "hopeless\n";
    }
}
