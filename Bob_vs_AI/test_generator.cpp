#include <bits/stdc++.h>
using namespace std;

double randDouble() {
    return (double)rand() / RAND_MAX;
}

int randRange(int l, int r) {
    int diff = (r - l + 1);
    return (rand() % diff) + l;
}


string getInputName(int testIndex) {
    return "data/secret/" + to_string(testIndex) + ".in";
}

string getOutputName(int testIndex) {
    return "data/secret/" + to_string(testIndex) + ".out";
}

void generateTestCase(ofstream &inFile, int n, int m) {
    inFile << n << " " << m << endl;
    for(int i = 0; i <= m; i++){
        for(int j = 0; j < n; j++){
            inFile << setprecision(6) << randDouble() << " ";
        }
        inFile << endl;
    }
}

int main() {
    srand(time(NULL));
    int numTests = 100;
    for(int z = 0; z < numTests; z++){
        ofstream inFile(getInputName(z + 1));
        if(z < 90) {
            generateTestCase(inFile, randRange(1, 100), randRange(1, 10));
        }else{
            generateTestCase(inFile, 1000, 10);
        } 
        inFile.close();
    }

}