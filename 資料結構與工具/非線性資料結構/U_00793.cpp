#include <bits/stdc++.h>
using namespace std;
vector<int> pa;
int find(int x) { return x == pa[x] ? x : pa[x] = find(pa[x]); }
int main() {
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        string input; getline(cin, input);
        int ans[2] = {0};
        pa.clear(); pa.resize(n + 1);
        for (int i = 1 ; i <= n ; i++)
            pa[i] = i;
        while (getline(cin, input)) {
            if (input.size() == 0) break;
            stringstream ss; ss << input;
            string op; int u, v;
            ss >> op >> u >> v;
            if (op[0] == 'c') {
                int x = find(u);
                int y = find(v);
                pa[x] = y;
            } else {
                int x = find(u);
                int y = find(v);
                ans[x != y]++;
            }
        }
        cout << ans[0] << ',' << ans[1] << '\n';
        if (t) cout << '\n';
    }
}
