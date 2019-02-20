#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; string input; getline(cin, input); while (t--) {
        getline(cin, input);
        if (input.size() < 12) { 
            cout << '\n';
            continue;
        }
        if (input.substr(0, 11) == "simon says ")
            cout << input.substr(11, input.size() - 11) << '\n';
        else
            cout << '\n';
    }
}
