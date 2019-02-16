#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    vector<int> data(5, 0);
    for (int i = 0 ; i < 5 ; i++) {
        for (int j = 0 ; j < 4 ; j++) {
            int v; cin >> v;
            data[i] += v;
        }
    }
    int maxV = 0, maxIdx = -1;
    for (int i = 0 ; i < 5 ; i++) {
        if (maxV < data[i])
            maxV = data[i], maxIdx = i;
    }
    cout << maxIdx + 1 << ' ' << maxV << '\n';
}
