#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    map<string, string> data;
    string input; while (1) {
        getline(cin, input);
        if (input == "")
            break;
        stringstream ss; ss << input;
        string a, b; ss >> a >> b;
        data[b] = a;
    }
    while (getline(cin, input))
        if (data.count(input))
            cout << data[input] << '\n';
        else
            cout << "eh\n";
}
