#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m; cin >> n >> m;
    set<string> app;
    int ans = 0;
    for (int i = 0 ; i < m ; i++) {
        string input; cin >> input;
        app.insert(input);
        if (!ans && (int)app.size() == n)
            ans = i + 1;
    }
    if (ans)
        cout << ans << '\n';
    else 
        cout << "paradox avoided\n";
}
