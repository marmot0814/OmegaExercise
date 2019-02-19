#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; string input; getline(cin, input); while (t--) {
        vector<bool> app(26, false);
        getline(cin, input);
        for (auto &c : input) {
            if (isalpha(c))
                app[tolower(c) - 'a'] = true;
        }
        string ans;
        for (int i = 0 ; i < 26 ; i++)
            if (!app[i])
                ans += i + 'a';
        if (ans.size())
            cout << "missing " << ans << '\n';
        else cout << "pangram\n";
    }
}
