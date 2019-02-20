#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int r, c; cin >> r >> c;
    set<int> app;
    for (int i = 1 ; i <= r ; i++)
        app.insert(i);
    for (int i = 0 ; i < c ; i++) {
        int v; cin >> v;
        app.erase(v);
    }
    if (app.size())
        cout << *app.begin() << '\n';
    else
        cout << "too late\n";
}
