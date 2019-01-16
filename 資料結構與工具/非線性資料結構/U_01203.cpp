#include <bits/stdc++.h>
using namespace std;
int main() {
    map<int, int> cnt;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    string s; while (cin >> s) {
        if (s[0] == '#')
            break;
        int id, per; cin >> id >> per;
        cnt[id] = per;
        pq.push(make_pair(per, id));
    }
    int k; cin >> k; while (k--) {
        pair<int, int> p = pq.top(); pq.pop();
        cout << p.second << '\n';
        p.first += cnt[p.second];
        pq.push(p);
    }
}
