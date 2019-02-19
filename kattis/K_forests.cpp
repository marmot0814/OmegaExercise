#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<set<int> > data(n);
    int i, j; while (cin >> i >> j) {
        i--, j--;
        data[i].insert(j);
    }
    set<set<int> > cnt;
    for (auto &s : data)
        cnt.insert(s);
    cout << cnt.size() << '\n';
}
