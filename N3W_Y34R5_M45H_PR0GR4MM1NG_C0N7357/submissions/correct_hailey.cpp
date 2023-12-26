#include <iostream>
using namespace std;

int main() {
    char c;
    cin.get(c);
    while (!cin.eof()) {
        if (c == 'a' || c == 'A') {
            cout << '4';
        }
        else if (c == 'e' || c == 'E') {
            cout << '3';
        }
        else if (c == 'i' || c == 'I') {
            cout << '1';
        }
        else if (c == 'o' || c == 'O') {
            cout << '0';
        }
        else if (c == 's' || c == 'S') {
            cout << '5';
        }
        else if (c == 't' || c == 'T') {
            cout << '7';
        }
        else if (c == 'z' || c == 'Z') {
            cout << '2';
        }
        else if (c >= 'a' && c <= 'z') {
            cout << (char)(c - 'a' + 'A');
        }
        else {
            cout << c;
        }
        cin.get(c);
    }
    return 0;
}