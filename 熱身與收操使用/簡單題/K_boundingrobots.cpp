#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m; while (cin >> n >> m && (n || m)) {
        pair<int, int> rob = make_pair(0, 0), act = make_pair(0, 0);
        int q; cin >> q; while (q--) {
            string op; cin >> op;
            int idx; cin >> idx;
            if (op[0] == 'u') {
                rob.second += idx;
                act.second += idx;
            } else if (op[0] == 'd') {
                rob.second -= idx;
                act.second -= idx;
            } else if (op[0] == 'r') {
                rob.first += idx;
                act.first += idx;
            } else {
                rob.first -= idx;
                act.first -= idx;
            }
            act.first  = max(min(n - 1, act.first), 0);
            act.second = max(min(m - 1, act.second), 0);
        }
        cout << "Robot thinks " << rob.first << ' ' << rob.second << '\n';
        cout << "Actually at " << act.first << ' ' << act.second << '\n';
        cout << '\n';
    }
}
