#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string input; while (getline(cin, input)) {
        if (input[0] == '0') break;
        vector<char> seed, extend, concat;
        for (auto &c : input) {
            if (c >= 'p')
                seed.push_back(c);
            else if (c == 'N')
                extend.push_back(c);
            else
                concat.push_back(c);
        }
        if (seed.size() == 0) {
            cout << "no WFF possible\n";
            continue;
        }
        for (auto &c : extend)
            cout << c;
        for (int i = 1, j = 0 ; i < (int)seed.size() && j < (int)concat.size() ; i++, j++)
            cout << concat[j] << seed[i];
        cout << seed[0] << '\n';
    }
}
