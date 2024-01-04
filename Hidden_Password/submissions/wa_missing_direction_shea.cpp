#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

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
                    // Don't check a specific direction to ensure we get a WA from the judge.
                    if(dx == -1 && dy == 1){
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


int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n;
    cin >> n;
    vector<string> grid(n);
    for(int i = 0; i < n; i++){
        cin >> grid[i];
    }
    int m;
    cin >> m;
    vector<string> potentialPasswords(m);
    for(int i = 0; i < m; i++){
        cin >> potentialPasswords[i];
    }

    for(int i = 0; i < m; i++){
        if(isWordInGrid(grid, potentialPasswords[i])){
            cout << potentialPasswords[i] << endl;
        }
    }
}