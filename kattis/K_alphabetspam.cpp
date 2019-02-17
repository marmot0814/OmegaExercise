#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string name; cin >> name;
    vector<int> cnt(4, 0);
    for (auto &c : name) {
        if (c == '_')
            cnt[0]++;
        else if (islower(c))
            cnt[1]++;
        else if (isupper(c))
            cnt[2]++;
        else
            cnt[3]++;
    }
    cout << fixed << setprecision(20) << cnt[0] / (double)name.size() << '\n';
    cout << fixed << setprecision(20) << cnt[1] / (double)name.size() << '\n';
    cout << fixed << setprecision(20) << cnt[2] / (double)name.size() << '\n';
    cout << fixed << setprecision(20) << cnt[3] / (double)name.size() << '\n';
}
