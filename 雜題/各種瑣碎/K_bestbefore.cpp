#include <bits/stdc++.h>
using namespace std;
bool isleap(int y) {
    if (y % 400 == 0)
        return true;
    else if (y % 100 == 0)
        return false;
    else if (y % 4 == 0)
        return true;
    else 
        return false;
}
int day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool islegal(int y, int m, int d) {
    if (m >= 13 || m == 0) return false;
    if (m == 2) {
        if (d > day[m - 1] + isleap(y) || d == 0)
            return false;
    } else {
        if (d > day[m - 1] || d == 0) 
            return false;
    }
    return true;
}
int main() {
    string input; cin >> input;
    string tar = input;
    for (auto &c : tar)
        if (c == '/')
            c = ' ';
    stringstream ss; ss << tar;
    vector<int> vec; int tmp; 
    while (ss >> tmp) vec.push_back(tmp);
    sort(vec.begin(), vec.end());
    bool legal = false;
    do {
        if (islegal(vec[0] < 2000 ? vec[0] + 2000 : vec[0], vec[1], vec[2])) {
            legal = true;
            break;
        }
    } while (next_permutation(vec.begin(), vec.end()));
    if (legal) {
        cout << (vec[0] < 2000 ? vec[0] + 2000 : vec[0]) << '-';
        cout << setw(2) << setfill('0') << vec[1] << '-';
        cout << setw(2) << setfill('0') << vec[2] << '\n';
    } else {
        cout << input << " is illegal\n";
    }
}
