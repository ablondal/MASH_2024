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

int main() {
    srand(time(NULL));
    int numTests = 100;
    for(int z = 0; z < numTests; z++){
        ofstream inFile(getInputName(z + 1));
        if(z < 90) {
            inFile << randRange(1, 1e4) << endl;
        }else{
            inFile << randRange(1, 1e5) << endl;
        } 
        inFile.close();
    }

}