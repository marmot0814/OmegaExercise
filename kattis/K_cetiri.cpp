#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    vector<int> data(3);
    for (auto &v : data)
        cin >> v;
    sort(data.begin(), data.end());
    int d = min(data[1] - data[0], data[2] - data[1]);
    if (data[1] - data[0] != d)
        cout << (data[1] + data[0]) / 2 << '\n';
    else if (data[2] - data[1] != d)
        cout << (data[2] + data[1]) / 2 << '\n';
    else
        cout << data[2] + d << '\n';
}
