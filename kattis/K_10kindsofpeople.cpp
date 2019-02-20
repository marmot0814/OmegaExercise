#include <bits/stdc++.h>
using namespace std;
vector<int> pa;
int find(int x) { return pa[x] < 0 ? x : pa[x] = find(pa[x]); }
void Union(int a, int b) {
    int x = find(a);
    int y = find(b);
    if (x != y)
        pa[x] = y;
}
int encode(int i, int j, int m) {
    return i * m + j;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    pa.clear(); pa.resize(n * m, -1);
    vector<vector<char> > G(n, vector<char>(m));
    for (auto &vv : G)
        for (auto &v : vv)
            cin >> v;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            if (i != 0 && G[i][j] == G[i - 1][j]) 
                Union(encode(i, j, m), encode(i - 1, j, m));
            if (j != 0 && G[i][j] == G[i][j - 1])
                Union(encode(i, j, m), encode(i, j - 1, m));
        }
    }
    int q; cin >> q; while (q--) {
        int ax, ay, bx, by; cin >> ax >> ay >> bx >> by;
        ax--, bx--, ay--, by--;
        if (G[ax][ay] != G[bx][by] || find(encode(ax, ay, m)) != find(encode(bx, by, m)))
            cout << "neither\n";
        else {
            if (G[ax][ay] == '1')
                cout << "decimal\n";
            else
                cout << "binary\n";
        }
    }
}
