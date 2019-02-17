#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    vector<int> data(4);
    for (auto &v : data) cin >> v;
    sort(data.begin(), data.end());
    cout << data[0] * data[2] << '\n';
}
