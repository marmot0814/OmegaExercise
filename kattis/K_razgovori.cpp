#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<LL, LL> pii;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<pii> data(n);
    for (auto &p : data)
        cin >> p.F >> p.S;
    sort(data.begin(), data.end());
    data.push_back({0, 0});
    LL ret = 0;
    for (int i = 1 ; i <= n ; i++)
        ret += max(0LL, data[i - 1].S - data[i].S);
    cout << ret << '\n';
}
