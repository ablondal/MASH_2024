#include <bits/stdc++.h>
using namespace std;

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

void generateTestCase(ofstream &inFile, int n) {
    inFile << n << endl;
    for(int i = 0; i < n; i++){
        inFile << randRange(1, 1000) << " ";
    }
    inFile << endl;
}

int main() {
    srand(time(NULL));
    int numTests = 100;
    for(int z = 0; z < numTests; z++){
        ofstream inFile(getInputName(z + 1));
        if(z < 90) {
            generateTestCase(inFile, 2 * randRange(2, 50));
        }else{
            generateTestCase(inFile, 1000);
        } 
        inFile.close();
    }

}