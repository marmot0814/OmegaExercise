#include <bits/stdc++.h>
using namespace std;
struct P {
    int idx; long long a, d, h;
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    set<int> app;
    vector<P> data(n);
    for (int i = 0 ; i < n ; i++) {
        data[i].idx = i;
        cin >> data[i].a >> data[i].d >> data[i].h;
    }
    sort(data.begin(), data.end(), [](P a, P b) { return a.a > b.a; });
    for (int i = 0 ; i < k ; i++)
        app.insert(data[i].idx);
    sort(data.begin(), data.end(), [](P a, P b) { return a.d > b.d; });
    for (int i = 0 ; i < k ; i++)
        app.insert(data[i].idx);
    sort(data.begin(), data.end(), [](P a, P b) { return a.h > b.h; });
    for (int i = 0 ; i < k ; i++)
        app.insert(data[i].idx);
    cout << app.size() << '\n';
}
