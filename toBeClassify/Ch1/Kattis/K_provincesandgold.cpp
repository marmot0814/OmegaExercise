#include <bits/stdc++.h>
using namespace std;
int main() {
    int G, S, C; cin >> G >> S >> C;
    int sum = 3 * G + 2 * S + C;
    bool first = false;
    if (sum >= 8) {
        cout << "Province";
    } else if (sum >= 5) {
        cout << "Duchy";
    } else if (sum >= 2) {
        cout << "Estate";
    } else {
        first = true;
    }
    if (!first)
        cout << " or ";
    if (sum >= 6) {
        cout << "Gold\n";
    } else if (sum >= 3) {
        cout << "Silver\n";
    } else {
        cout << "Copper\n";
    }
}

