#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
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

void generateTestCase(ofstream &inFile, const int& w, const int& n) {
    inFile << w << " " << n << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < w; j++) {
            double rand_seed = ((double)(rand()))/RAND_MAX;
            if (rand_seed < 0.8) {
                inFile << ". ";
            }
            else {
                rand_seed = ((double)(rand()))/(double)RAND_MAX * n;
                inFile << (int)(floor(rand_seed) + 1) << " ";
            }
        }
        inFile << endl;
    }
    inFile << endl;
}

void generateTestCaseLarge(ofstream &inFile, const int& w, const int& n) {
    inFile << w << " " << n << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < w; j++) {
            double rand_seed = ((double)(rand()))/RAND_MAX;
            if (rand_seed < 0.98) {
                inFile << ". ";
            }
            else {
                rand_seed = ((double)(rand()))/(double)RAND_MAX * n;
                inFile << (int)(floor(rand_seed) + 1) << " ";
            }
        }
        inFile << endl;
    }
    inFile << endl;
}

void generateTestCaseTLETest(ofstream &inFile, const int& w, const int& n) {
    inFile << w << " " << n << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < w; j++) {
            inFile << ". ";
        }
        inFile << endl;
    }
    inFile << endl;
}

int main() {
    srand(time(NULL));
    int numTests = 80;
    /*
    for(int z = 5; z < 80; z++){
        ofstream inFile(getInputName(z + 1));
        int w = ((double)z / 8.0)+2;
        int n = (z%4)+2;
        generateTestCase(inFile, w, n);
        inFile.close();
    }*/

    for(int z = 80; z < 99; z++){
        ofstream inFile(getInputName(z + 1));
        int w = ((double)(z-79)*3);
        if (w > 30) {
            w = 30;
        }
        int n = 5;
        generateTestCaseLarge(inFile, w, n);
        inFile.close();
    }
    for(int z = 99; z < 100; z++){
        ofstream inFile(getInputName(z + 1));
        int w = 30;
        int n = 5;
        generateTestCaseTLETest(inFile, w, n);
        inFile.close();
    }

}