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

string createRandomString(int length) {
    string s = "";
    for(int i = 0; i < length; i++){
        s += 'a' + randRange(0, 25);
    }
    return s;
}

bool isWordInGrid(vector<string> &grid, string word) {
    int n = grid.size();
    int sz = word.size();
    for(int startX = 0; startX < n; startX++){
        for(int startY = 0; startY < n; startY++){
            for(int dx = -1; dx <= 1; dx++){
                for(int dy = -1; dy <= 1; dy++){
                    if(dx == 0 && dy == 0){
                        continue;
                    }
                    int curX = startX;
                    int curY = startY;
                    bool works = true;
                    for(int i = 0; i < sz; i++){
                        if(curX < 0 || curX >= n || curY < 0 || curY >= n){
                            works = false;
                            break;
                        }
                        if(grid[curX][curY] != word[i]){
                            works = false;
                        }
                        curX += dx;
                        curY += dy;
                    }
                    if(works){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

string chooseHiddenWord(vector<string> &grid, int n) {
    int hiddenWordLength = randRange(3, n);
    int dx = randRange(-1, 1);
    int dy = randRange(-1, 1);
    while(dx == 0 && dy == 0){
        dx = randRange(-1, 1);
        dy = randRange(-1, 1);
    }
    int startX = randRange(0, n-1);
    while((startX + dx * (hiddenWordLength-1)) < 0 || (startX + dx * (hiddenWordLength-1)) >= n) {
        startX = randRange(0, n-1);
    }
    int startY = randRange(0, n-1);
    while((startY + dy * (hiddenWordLength-1)) < 0 || (startY + dy * (hiddenWordLength-1)) >= n) {
        startY = randRange(0, n-1);
    }
    string hiddenWord = "";
    int curX = startX;
    int curY = startY;
    for(int i = 0; i < hiddenWordLength; i++){
        hiddenWord += grid[curX][curY];
        curX += dx;
        curY += dy;
    }
    return hiddenWord;
}

void generateTestCase(ofstream &inFile, int n, int m) {
    double obstacleThreshold = randRange(0, 50);
    vector<string> grid(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
           grid[i] += 'a' + randRange(0, 25);
        }
    }
    vector<string> words(m);
    for(int i = 0; i < m; i++){
        words[i] = createRandomString(randRange(3, n));
        while(isWordInGrid(grid, words[i])){
            words[i] = createRandomString(randRange(3, n));
        }
    }
    words[randRange(0, m-1)] = chooseHiddenWord(grid, randRange(3, n));
    
    inFile << n << endl;
    for(int i = 0; i < n; i++){
        inFile << grid[i] << endl;
    }
    inFile << m << endl;
    for(int i = 0; i < m; i++){
        inFile << words[i] << endl;
    }
}

int main() {
    srand(time(NULL));
    int numTests = 100;
    for(int z = 0; z < numTests; z++){
        ofstream inFile(getInputName(z + 1));
        if(z < 90) {
            generateTestCase(inFile, randRange(3, 10), randRange(3, 10));
        }else{
            generateTestCase(inFile, 10, 10);
        } 
        inFile.close();
    }

}