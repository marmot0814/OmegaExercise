#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    vector<string> trans{"@", "8", "(", "|)", "3", "#", "6", "[-]", "|", "_|", "|<", "1", "[]\\/[]", "[]\\[]", "0", "|D", "(,)", "|Z", "$", "\'][\'", "|_|", "\\/", "\\/\\/", "}{", "`/", "2"};
    string input; getline(cin, input);
    string ans;
    for (auto &c : input) {
        if (isalpha(c)) {
            ans += trans[tolower(c) - 'a'];
        } else ans += c;
    }
    cout << ans << '\n';
}
