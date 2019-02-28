#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, p; cin >> n >> p;
    vector<int> data(n);
    for (auto &v : data) {
        cin >> v;
        v -= p;
    }
    int maxV = 0, sum = 0;
    for (auto &v : data) {
        sum = max(sum + v, 0);
        maxV = max(maxV, sum);
    }
    cout << maxV << '\n';
}
