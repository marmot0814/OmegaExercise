#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<pii> data(n);
    for (auto &p : data) cin >> p.first >> p.second;
    int minV = INF;
    for (int S = 1 ; S < (1 << n) ; S++) {
        pii sum; sum.first = 1;
        for (int i = 0 ; i < n ; i++) {
            if ((S & (1 << i)) == 0) continue;
            sum.first *= data[i].first;
            sum.second += data[i].second;
        }
        minV = min(minV, abs(sum.first - sum.second));
    }
    cout << minV << '\n';
}
