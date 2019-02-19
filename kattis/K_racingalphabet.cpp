#include <bits/stdc++.h>
using namespace std;
int getIdx(char c) {
    if (isalpha(c))
        return c - 'A';
    if (c == ' ')
        return 26;
    if (c == '\'')
        return 27;
    return -1;
}
const double PI = acos(-1);
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; string input; getline(cin, input); while (t--) {
        getline(cin, input);
        int pos = getIdx(input[0]);
        int ans = 0;
        for (int i = 1 ; i < (int)input.size() ; i++) {
            int diff = abs(getIdx(input[i]) - pos);
            ans += min(diff, 28 - diff);
            pos = getIdx(input[i]);
        }
        cout << fixed << setprecision(10) << ans * 2.0 * PI / 28.0 * 2 + input.size() << '\n';
    }
}
