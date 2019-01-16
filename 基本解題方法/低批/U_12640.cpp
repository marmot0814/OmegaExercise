#include <bits/stdc++.h>
using namespace std;
int main() {
    string s; while (getline(cin, s)) {
        stringstream ss; ss << s;
        int ans = 0, sum = 0;
        int tmp; while (ss >> tmp)
            sum = max(0, sum + tmp), ans = max(ans, sum);
        cout << ans << '\n';
    }
}
