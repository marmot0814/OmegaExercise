#include <bits/stdc++.h>
using namespace std;
const double INF = 1e10;
struct Graph {
    static const int MAXN = 105;
    int n; double e[MAXN][MAXN], d[MAXN];
    int match[MAXN], onstk[MAXN];
    vector<int> stk;
    Graph(int _n) {
        n = _n;
        for( int i = 0 ; i < n ; i ++ )
            for( int j = 0 ; j < n ; j ++ )
                e[i][j] = 0;
    }
    void add_edge(int u, int v, double w) {
        e[u][v] = e[v][u] = w;
    }
    bool SPFA(int u){
        if (onstk[u]) return true;
        stk.push_back(u);
        onstk[u] = 1;
        for ( int v = 0 ; v < n ; v++ ) {
            if (u != v && match[u] != v && !onstk[v] ) {
                int m = match[v];
                if ( d[m] > d[u] - e[v][m] + e[u][v] ) {
                    d[m] = d[u] - e[v][m] + e[u][v];
                    onstk[v] = 1;
                    stk.push_back(v);
                    if (SPFA(m)) return true;
                    stk.pop_back();
                    onstk[v] = 0;
                }
            }
        }
        onstk[u] = 0;
        stk.pop_back();
        return false;
    }
    double solve() {
        for ( int i = 0 ; i < n ; i += 2 ) {
            match[i] = i+1;
            match[i+1] = i;
        }
        while (true){
            int found = 0;
            for ( int i = 0 ; i < n ; i++ )
                onstk[ i ] = d[ i ] = 0;
            for ( int i = 0 ; i < n ; i++ ) {
                stk.clear();
                if ( !onstk[i] && SPFA(i) ) {
                    found = 1;
                    while ( stk.size() >= 2 ) {
                        int u = stk.back(); stk.pop_back();
                        int v = stk.back(); stk.pop_back();
                        match[u] = v;
                        match[v] = u;
                    }
                }
            }
            if (!found) break;
        }
        double ret = 0;
        for ( int i = 0 ; i < n ; i++ )
            ret += e[i][match[i]];
        ret /= 2;
        return ret;
    }
};
#define F first
#define S second
typedef pair<double, double> pdd;
double dist(pdd a, pdd b) {
    return sqrt((a.F - b.F) * (a.F - b.F) + (a.S - b.S) * (a.S - b.S));
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    pdd s; cin >> s.F >> s.S;
    int n; cin >> n;
    vector<pdd> data(n);
    for (auto &p : data) cin >> p.F >> p.S;
    double BASE = 0, maxV = 0;
    for (int i = 0 ; i < n ; i++) {
        BASE += dist(s, data[i]);
        maxV = max(maxV, dist(s, data[i]));
    }
    double ans = 0;
    if (n % 2) {
        ans = INF;
        for (int x = 0 ; x < n ; x++) {
            double sum = BASE + dist(data[x], s) - maxV;
            Graph *sol = new Graph(n - 1);
            for (int i = 0 ; i < n ; i++) {
                if (i == x) continue;
                for (int j = i + 1 ; j < n ; j++) {
                    if (j == x) continue;
                    int ac_i = i - (i > x);
                    int ac_j = j - (j > x);
                    sol->add_edge(ac_i, ac_j, dist(data[i], data[j]));
                }
            }
            sum += sol->solve();
            ans = min(ans, sum);
        }
    } else {
        ans = BASE - maxV;
        Graph *sol = new Graph(n);
        for (int i = 0 ; i < n ; i++) {
            for (int j = i + 1 ; j < n ; j++) {
                sol->add_edge(i, j, dist(data[i], data[j]));
            }
        }
        ans += sol->solve();
        delete sol;
    }
    cout << fixed << setprecision(10) << ans << '\n';

    

}
