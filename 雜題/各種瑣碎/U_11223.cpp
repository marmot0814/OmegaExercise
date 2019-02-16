#include <bits/stdc++.h>
using namespace std;
void trim(string &input) {
    while (input.front() == ' ')
        input = input.substr(1, input.size() - 1);
}
int main() {
    vector<string> sym{"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", ".", ",", "?", "\'", "!", "/", "(", ")", "&", ":", ";", "=", "+", "-", "_", "\"", "@"};
    vector<string> code{".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", ".-.-.-", "--..--", "..--..", ".----.", "-.-.--", "-..-.", "-.--.", "-.--.-", ".-...", "---...", "-.-.-.", "-...-", ".-.-.", "-....-", "..--.-", ".-..-.", ".--.-."};
    map<string, string> mapping;
    for (int i = 0 ; i < 53 ; i++)
        mapping[code[i]] = sym[i];
    int t, kase = 0; cin >> t; string input; getline(cin, input); while (t--) {
        cout << "Message #" << ++kase << '\n';
        getline(cin, input);
        trim(input);
        string tar = "";
        while (input.size()) {
            if (input.front() == ' ') {
                if (tar.size()) {
                    cout << mapping[tar];
                    tar = "";
                } else { 
                    cout << ' '; trim(input);
                    continue;
                }
            } else tar += input.front();
            input = input.substr(1, input.size() - 1);
        }
        cout << '\n';
        if (t) cout << '\n';
    }
}
