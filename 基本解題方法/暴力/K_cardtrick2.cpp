#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        queue<int> q; q.push(n);
        for (int i = n - 1 ; ~i ; i--) {
            q.push(i);
            for (int j = 0 ; j < i ; j++) {
                q.push(q.front());
                q.pop();
            }
        }
        vector<int> ans;
        while (q.size()) {
            ans.push_back(q.front());
            q.pop();
        }
        ans.pop_back();
        reverse(ans.begin(), ans.end());
        for (auto &v : ans)
            cout << v << ' ';
        cout << '\n';
    }
}
