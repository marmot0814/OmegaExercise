#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    map<int, int> cnt, idx;
    for (int i = 0 ; i < n ; i++) {
        int v; cin >> v;
        cnt[v]++;
        idx[v] = i;
    }
    int maxV = -1;
    for (auto &p : cnt)
        if (p.second == 1)
            maxV = max(maxV, p.first);
    if (maxV == -1)
        cout << "none\n";
    else
        cout << idx[maxV] + 1 << '\n';
}
