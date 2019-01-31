#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> p1(n);
    for (auto &v : p1) cin >> v;
    cin >> n;
    vector<int> p2(n);
    for (auto &v : p2) cin >> v;
    sort(p1.begin(), p1.end());
    sort(p2.begin(), p2.end());
    int i = 0, j = 0, whofirst = 0, ans = 0;
    while (i < (int)p1.size() && j < (int)p2.size()) {
        if (p1[i] < p2[j] && whofirst == 2) {
            i++;
        } else if (p1[i] > p2[j] && whofirst == 1) {
            j++;
        } else {
            ans++;
            if (p1[i] == p2[j]) {
                i++, j++; whofirst = 0;
            } else if (p1[i] < p2[j]) {
                i++; whofirst = 2;
            } else {
                j++; whofirst = 1;
            }
        }
    }
    if (whofirst != 2 && i < (int)p1.size())
        ans++;
    if (whofirst != 1 && j < (int)p2.size())
        ans++;
    cout << ans << '\n';
}
