#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int, int> pii;
struct Data {
    int base, sz, dim;
    vector<pii> v;
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q; while (cin >> n >> q) {
        map<string, Data> data;
        while (n--) {
            string name; cin >> name;
            cin >> data[name].base >> data[name].sz;
            int m; cin >> m; while (m--) {
                int l, u; cin >> l >> u;
                data[name].v.emplace_back(l, u);
            }
        }
        while (q--) {
            string name; cin >> name;
            cout << name << "[";
            bool first = true;
            int ans = 0;
            for (auto &p : data[name].v) {
                ans *= (p.S - p.F + 1);
                int num; cin >> num;
                if (first) first = false;
                else cout << ", ";
                cout << num;
                ans += (num - p.F);
            }
            cout << "] = " << ans * data[name].sz + data[name].base << '\n';
        }
    }
}
