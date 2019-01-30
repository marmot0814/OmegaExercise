#include <bits/stdc++.h>
using namespace std;
const int MAXN = (1<<24) + 5;
struct BIT{
    int data[MAXN], n;
    BIT(){ 
        n = MAXN - 1;
        memset(data, 0, sizeof(data));
    }
    int lowbit(int x) { return x & (-x); }
    int sum(int x){
        int res = 0;
        while (x > 0) res += data[x], x -= lowbit(x);
        return res;
    }
    void add(int x, int d){
        while (x <= n) data[x] += d, x += lowbit(x);
    }
};
void solve(int a, vector<int> &ans, vector<int> &sz, BIT *sol, vector<int> &vis, int &stamp) {
    if (~vis[a]) {
        int len = sol->sum(stamp) - sol->sum(vis[a] - 1);
        for (int i = 0 ; i < (int)ans.size() ; i++) {
            if (sz[i] >= len) break;
            ans[i]++;
        }
        sol->add(vis[a], -1);
    } else for (auto &v : ans) v++;
    sol->add(vis[a] = ++stamp, 1);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n; 
    vector<int> sz(n), vis(MAXN, -1), ans(n, 0);
    for (auto &v : sz) cin >> v;
    BIT *sol = new BIT(); int stamp = 0;
    string op; while (cin >> op) {
        if (op[0] == 'E') break;
        if (op[0] == 'A') {
            int a; cin >> a;
            solve(a, ans, sz, sol, vis, stamp);
        } else if (op[0] == 'R') {
            int a, d, k; cin >> a >> d >> k;
            for (int i = 0 ; i < k ; i++)
                solve(a + d * i, ans, sz, sol, vis, stamp);
        } else {
            for (int i = 0 ; i < (int)ans.size() ; i++)
                cout << ans[i] << " \n"[i == (int)ans.size() - 1];
            ans.clear(); ans.resize(n, 0);
        }
    }
}
