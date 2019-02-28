#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string input; while (getline(cin, input)) {
        stringstream ss; ss << input;
        int sum = 0, v; while (ss >> v) sum += v;
        cout << sum / 2 << '\n';
    }
}
