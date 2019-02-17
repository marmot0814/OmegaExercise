#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string str; cin >> str;
    int len = str.size() / 2;
    vector<string> data{str.substr(0, len), str.substr(len, len)};
    for (auto &s : data) {
        int sum = 0;
        for (auto &c : s)
            sum += c - 'A';
        sum %= 26;
        for (auto &c : s) {
            c += sum;
            if (c > 'Z')
                c -= 26;
        }
    }
    for (int i = 0 ; i < len ; i++) {
        data[0][i] += data[1][i] - 'A';
        if (data[0][i] > 'Z')
            data[0][i] -= 26;
    }
    cout << data[0] << '\n';
}
