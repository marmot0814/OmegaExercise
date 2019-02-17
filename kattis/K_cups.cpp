#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    map<int, string> cnt;
    int n; cin >> n; string input; getline(cin, input); while (n--) {
        getline(cin, input);
        stringstream ss; ss << input;
        if (isdigit(input[0])) {
            int di; string name; ss >> di >> name;
            cnt[di / 2] = name;
        } else {
            string name; int ra; ss >> name >> ra;
            cnt[ra] = name;
        }
    }
    for (auto &p : cnt)
        cout << p.second << '\n';
}
