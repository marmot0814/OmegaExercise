#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<string> data(n);
    for (auto &s : data)
        cin >> s;
    bool ok = true;
    for (int i = 1 ; i < (int)data.size() ; i++)
        if (data[i - 1] < data[i])
            ok = false;
    if (ok) return cout << "DECREASING\n", 0;
    ok = true;
    for (int i = 1 ; i < (int)data.size() ; i++)
        if (data[i - 1] > data[i])
            ok = false;
    if (ok) return cout << "INCREASING\n", 0;
    cout << "NEITHER\n";
}
