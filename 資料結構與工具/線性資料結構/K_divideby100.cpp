#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string N, M; cin >> N >> M;
    int cnt = N.size() - M.size() + 1;
    string output = "";
    if (cnt <= 0) { 
        output += "0.";
        for (int i = 0 ; i < abs(cnt) ; i++)
            output += '0';
    }
    for (auto &c : N) {
        output += c; cnt--;
        if (cnt == 0)
            output += '.';
    }
    reverse(output.begin(), output.end());
    cnt = 0;
    for (auto &c : output) {
        if (c == '0')
            cnt++;
        else if (c == '.') {
            cnt++;
            break;
        } else break;
    }
    reverse(output.begin(), output.end());
    cout << output.substr(0, output.size() - cnt) << '\n';
}

