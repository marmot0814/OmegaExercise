#include <bits/stdc++.h>
using namespace std;
typedef pair<char, int> pci;
typedef pair<int, int> pii;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    vector<int> data(3);
    for (auto &v : data) cin >> v;
    sort(data.begin(), data.end());
    string str; cin >> str;
    vector<pci> cha(3);
    for (int i = 0 ; i < 3 ; i++)
        cha[i].first = str[i], cha[i].second = i;
    sort(cha.begin(), cha.end());
    vector<pii> ans(3);
    for (int i = 0 ; i < 3 ; i++)
        ans[i].first = cha[i].second, ans[i].second = data[i];
    sort(ans.begin(), ans.end());
    for (int i = 0 ; i < 3 ; i++)
        cout << ans[i].second << " \n"[i == 2];
}
