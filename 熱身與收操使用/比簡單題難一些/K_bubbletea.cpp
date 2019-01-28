#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> tea(n);
    for (auto &v : tea) cin >> v;
    int m; cin >> m;
    vector<int> top(m);
    for (auto &v : top) cin >> v;
    int minV = INF;
    for (int i = 0 ; i < n ; i++) {
        int num; cin >> num;
        for (int j = 0 ; j < num ; j++) {
            int id; cin >> id;
            minV = min(minV, tea[i] + top[id - 1]);
        }
    }
    int price; cin >> price;
    cout << max(0, price / minV - 1) << '\n';
}
