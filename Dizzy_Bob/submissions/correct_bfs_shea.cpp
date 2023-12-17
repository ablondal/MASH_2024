#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n, m;
    cin >> n >> m;
    vector<string> maze(n);
    for(int i = 0; i < n; i++){
        cin >> maze[i];
    }

    vector<vector<bool>> visited_start(n, vector<bool>(m));

    vector<vector<bool>> visited_up(n, vector<bool>(m));
    vector<vector<bool>> visited_down(n, vector<bool>(m));
    vector<vector<bool>> visited_left(n, vector<bool>(m));
    vector<vector<bool>> visited_right(n, vector<bool>(m));

    queue<pair<int,int>> coords;
    coords.push({0, 0});

    int numDirectionChanges = 0;
    while(!coords.empty()) {
        queue<pair<int,int>> nextCoords;
        while(!coords.empty()){
            pair<int,int> curCoords = coords.front();
            int row = curCoords.first, col = curCoords.second;
            coords.pop();

            if(row < 0 || row >= n || col < 0 || col >= m || visited_start[row][col]){
                continue;
            }
            visited_start[row][col] = true;
            visited_up[row][col] = true;
            visited_down[row][col] = true;
            visited_left[row][col] = true;
            visited_right[row][col] = true;

            // Check if we reached the exit
            if(row == n-1 && col == m-1){
                cout << numDirectionChanges - 1 << endl;
                exit(0);
            }

            // Try walking up
            for(int newRow = row - 1; newRow >= 0; newRow--){
                if(visited_up[newRow][col] || maze[newRow][col] == '#'){
                    break;
                }
                visited_up[newRow][col] = true;
                nextCoords.push({newRow, col});
            }

            // Try walking down
            for(int newRow = row + 1; newRow < n; newRow++){
                if(visited_down[newRow][col] || maze[newRow][col] == '#'){
                    break;
                }
                visited_down[newRow][col] = true;
                nextCoords.push({newRow, col});
            }

            // Try walking left
            for(int newCol = col - 1; newCol >= 0; newCol--){
                if(visited_left[row][newCol] || maze[row][newCol] == '#'){
                    break;
                }
                visited_left[row][newCol] = true;
                nextCoords.push({row, newCol});
            }

            // Try walking right
            for(int newCol = col + 1; newCol < m; newCol++){
                if(visited_right[row][newCol] || maze[row][newCol] == '#'){
                    break;
                }
                visited_right[row][newCol] = true;
                nextCoords.push({row, newCol});
            }
        }
        coords = nextCoords;
        numDirectionChanges++;
    }

    cout << -1 << endl;
}