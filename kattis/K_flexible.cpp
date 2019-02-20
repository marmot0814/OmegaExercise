#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int w, n; cin >> w >> n;
    int pre = 0;
    vector<int> data;
    for (int i = 0 ; i < n ; i++) {
        int v; cin >> v;
        data.push_back(v - pre);
        pre = v;
    }
    data.push_back(w - pre);
    set<int> app;
    for (int i = 1 ; i <= (int)data.size() ; i++) {
        int sum = 0;
        for (int j = 0 ; j < i - 1 ; j++)
            sum += data[j];
        for (int j = i - 1 ; j < (int)data.size() ; j++) {
            sum += data[j];
            app.insert(sum);
            sum -= data[j - i + 1];
        }
    }
    bool first = true;
    for (auto &v : app) {
        if (first) first = false;
        else cout << ' ';
        cout << v;
    }
    cout << '\n';
}
