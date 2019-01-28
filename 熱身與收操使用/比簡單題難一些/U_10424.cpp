#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string a, b;
    while (getline(cin, a)) {
        getline(cin, b);
        int sum_a = 0, sum_b = 0;
        for (auto &c : a) {
            if (!isalpha(c))
                continue;
            sum_a += tolower(c) - 'a' + 1;
        }
        for (auto &c : b) {
            if (!isalpha(c))
                continue;
            sum_b += tolower(c) - 'a' + 1;
        }
        while (sum_a > 9) {
            int tmp = sum_a;
            sum_a = 0;
            while (tmp) 
                sum_a += tmp % 10, tmp /= 10;
        }
        while (sum_b > 9) {
            int tmp = sum_b;
            sum_b = 0;
            while (tmp)
                sum_b += tmp % 10, tmp /= 10;
        }
        cout << fixed << setprecision(2) << (double)min(sum_a, sum_b) / max(sum_a, sum_b) * 100 << " %\n";
    }
}
