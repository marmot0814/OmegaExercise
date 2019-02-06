#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
struct MinGWM {
    static const int MAXN = 105;
    int n; LL e[MAXN][MAXN], d[MAXN];
    int match[MAXN], onstk[MAXN];
    vector<int> stk;
    MinGWM(int _n) {
        n = _n;
        for( int i = 0 ; i < n ; i ++ )
            for( int j = 0 ; j < n ; j ++ )
                e[i][j] = 0;
    }
    void add_edge(int u, int v, LL w) {
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
    LL solve() {
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
        LL ret = 0;
        for ( int i = 0 ; i < n ; i++ )
            ret += e[i][match[i]];
        ret /= 2;
        return ret;
    }
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; while (cin >> n && n) {
        cin >> m;
        vector<vector<LL> > d(n, vector<LL>(n, INF));
        vector<int> deg(n, 0);
        for (int i = 0 ; i < n ; i++) d[i][i] = 0;
        LL ans = 0;
        while (m--) {
            int u, v; LL w;
            cin >> u >> v >> w;
            u--, v--;
            d[u][v] = d[v][u] = min(d[u][v], w);
            deg[u]++; deg[v]++;
            ans += w;
        }
        vector<int> odds;
        for (int i = 0 ; i < n ; i++)
            if (deg[i] % 2)
                odds.push_back(i);
        for (int k = 0 ; k < n ; k++)
            for (int i = 0 ; i < n ; i++)
                for (int j = 0 ; j < n ; j++)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        MinGWM *minGWM = new MinGWM(odds.size());
        for (int i = 0 ; i < (int)odds.size() ; i++)
            for (int j = i + 1 ; j < (int)odds.size() ; j++)
                minGWM->add_edge(i, j, d[odds[i]][odds[j]]);
        ans += minGWM->solve();
        cout << ans << '\n';
        delete minGWM;
    }
}
