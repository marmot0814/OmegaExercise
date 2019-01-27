#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; while (cin >> n >> k && (n || k)) {
        vector<int> ans;
        vector<int> sum(n, 0);
        queue<int> q;
        for (int i = 0 ; i < n ; i++)
            q.push(i);
        int rem = 0, cur = 0;
        while (q.size()) {
            if (!rem) { 
                cur %= k; cur++;
                rem = cur;
            }
            int p = q.front(); q.pop();
            int need = 40 - sum[p];
            if (need > rem) {
                sum[p] += rem;
                rem = 0;
                q.push(p);
            } else {
                ans.push_back(p + 1);
                sum[p] = 40;
                rem -= need;
            }
        }
        for (auto &v : ans)
            cout << setw(3) << v;
        cout << '\n';
    }
}
