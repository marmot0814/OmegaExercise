#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
const double INF = 1e10;
const double EPS = 1e-9;
typedef pair<int, int> pii;
double dist(pii a, pii b) {
    return sqrt((a.F - b.F) * (a.F - b.F) + (a.S - b.S) * (a.S - b.S));
}
int main() {
    int n; while (cin >> n && n) {
        vector<pii> pos(n);
        for (auto &p : pos)
            cin >> p.F >> p.S;
        int m; cin >> m;
        vector<vector<bool> > hasEdge(n, vector<bool>(n, false));
        vector<vector<double> > d(n, vector<double>(n, INF));
        for (int i = 0 ; i < n ; i++) d[i][i] = 0;
        while (m--) {
            int u, v; cin >> u >> v;
            d[u][v] = d[v][u] = dist(pos[u], pos[v]);
            hasEdge[u][v] = hasEdge[v][u] = true;
        }
        for (int k = 0 ; k < n ; k++)
            for (int i = 0 ; i < n ; i++)
                for (int j = 0 ; j < n ; j++)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        double ori = 0;
        for (int i = 0 ; i < n ; i++)
            for (int j = 0 ; j < n ; j++)
                ori += d[i][j];
        ori /= 2;
        double ans = INF;
        int ans_i = -1, ans_j = -1;
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < n ; j++) {
                if (hasEdge[i][j])
                    continue;
                double sum = 0;
                for (int x = 0 ; x < n ; x++)
                    for (int y = 0 ; y < n ; y++)
                        sum += min(d[x][y], min(d[x][i] + d[j][y], d[x][j] + d[i][y]) + dist(pos[i], pos[j]));
                if (sum / 2 < ans) {
                    ans = sum / 2;
                    ans_i = i;
                    ans_j = j;
                }
            }
        }
        if (abs(ans - ori) < EPS) {
            cout << fixed << setprecision(10) << "no addition reduces " << ori << '\n';
        } else {
            if (ans_i > ans_j) swap(ans_i, ans_j);
            cout << "adding " << ans_i << ' ' << ans_j << " reduces " << fixed << setprecision(10) << ori << " to " << ans << '\n';
        }
    }

}
