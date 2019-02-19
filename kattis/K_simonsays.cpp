#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; string input; getline(cin, input); while (t--) {
        getline(cin, input);
        if (input.size() < 11) continue;
        if (input.substr(0, 10) == "Simon says")
            cout << input.substr(10, input.size() - 10) << '\n';
    }
}
