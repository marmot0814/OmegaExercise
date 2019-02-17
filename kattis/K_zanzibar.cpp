#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; string input; getline(cin, input); while (t--) {
        getline(cin, input);
        stringstream ss; ss << input;
        int sum = 0, tmp; vector<int> data;
        while (ss >> tmp) data.push_back(tmp);
        for (int i = 1 ; i < (int)data.size() ; i++)
            sum += max(data[i] - data[i - 1] * 2, 0);
        cout << sum << '\n';
    }
}

