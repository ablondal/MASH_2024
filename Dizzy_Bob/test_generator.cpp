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

void generateTestCase(ofstream &inFile, int n, int m) {
    double obstacleThreshold = randRange(0, 50);
    inFile << n << " " << m << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if((i == 0 && j == 0) || (i == n-1 && j == m-1)){
                inFile << ".";
                continue;
            }
            if(randRange(0, 100) < obstacleThreshold){
                inFile << '#';
            }else{
                inFile << '.';
            }
        }
        inFile << endl;
    }
}

int main() {
    srand(time(NULL));
    int numTests = 100;
    for(int z = 0; z < numTests; z++){
        ofstream inFile(getInputName(z + 1));
        if(z < 25) {
            generateTestCase(inFile, randRange(2, 10), randRange(2, 10));
        }else if(z < 90) {
            generateTestCase(inFile, randRange(2, 100), randRange(2, 100));
        }else{
            generateTestCase(inFile, 1000, 1000);
        } 
        inFile.close();
    }

}