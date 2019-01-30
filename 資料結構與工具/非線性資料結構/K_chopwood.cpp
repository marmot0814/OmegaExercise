#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> data(n), cnt(n + 2);
    for (auto &v : data) { 
        cin >> v; cnt[v]++;
    }
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = 1 ; i <= n ; i++)
        if (cnt[i] == 0)
            pq.push(i);
    for (int i = 0 ; i < n ; i++) {
        if (pq.size() == 0) {
            cout << "Error\n";
            return 0;
        }
        ans.push_back(pq.top()); pq.pop();
        cnt[data[i]]--;
        if (cnt[data[i]] == 0)
            pq.push(data[i]);
    }
    for (auto &v : ans)
        cout << v << '\n';
}
