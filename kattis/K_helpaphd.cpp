#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; string input; getline(cin, input); while (t--) {
        getline(cin, input);
        bool skip = false;
        for (auto &c : input) {
            if (c == '=')
                skip = true;
            if (!isdigit(c))
                c = ' ';
        }
        if (skip)
            cout << "skipped\n";
        else {
            stringstream ss; ss << input;
            int a, b; ss >> a >> b;
            cout << a + b << '\n';
        }
    }
}
