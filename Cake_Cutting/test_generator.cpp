#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream fout("N3W_Y34R5_M45H_PR0GR4MM1NG_C0N7357/data/secret/2.in");

    for (int i = 0; i < 5000; i++) {
        fout << (char)(i%26 + 'a');
    }
    fout.close();
    return 0;
}