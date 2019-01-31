#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> data(n);
    for (auto &v : data) cin >> v;
    queue<int> q; q.push(0);
    int idx = 0;
    while (q.size()) {
        int p = q.front(); q.pop();
        while (data[p]--) {
            if (idx == n - 1) {
                cout << "NO\n";
                return 0;
            }
            data[++idx]--;
            q.push(idx);
        }
    }
    if (idx == n - 1)
        cout << "YES\n";
    else
        cout << "NO\n";
    
}
