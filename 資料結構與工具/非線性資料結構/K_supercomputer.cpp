#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
struct BIT{
    int data[MAXN], n;
    BIT(int _n){ n = _n;
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
    void flip(int x) {
        int res = sum(x) - sum(x - 1);
        if (res == 1)
            add(x, -1);
        else
            add(x, 1);
    }
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    BIT *sol = new BIT(n);
    while (q--) {
        string op; cin >> op;
        if (op[0] == 'F') {
            int x; cin >> x;
            sol->flip(x);
        } else {
            int l, r; cin >> l >> r;
            cout << sol->sum(r) - sol->sum(l - 1) << '\n';
        }
    }
}
