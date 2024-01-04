#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> assignment;
vector<vector<int>> reserved;
int w, n;

bool incrementAssignment(const int& i, const int& j) {
    if (j == w) {
        return incrementAssignment(i+1, 0);
    }
    if (i == 2) {
        return false;
    }
    if (reserved[i][j] != -1) {
        return incrementAssignment(i, j+1);
    }
    if (assignment[i][j] == n-1) {
        assignment[i][j] = 0;
        return incrementAssignment(i, j+1);
    }
    else {
        assignment[i][j]++;
    }
    return true;
}

vector<vector<bool>> visited;
vector<bool> isFound;

void dfsVisit(const int& i, const int& j) {
    if (i-1 >= 0 && !visited[i-1][j] && assignment[i-1][j] == assignment[i][j]) {
        visited[i-1][j] = true;
        dfsVisit(i-1, j);
    }
    if (i+1 < 2 && !visited[i+1][j] && assignment[i+1][j] == assignment[i][j]) {
        visited[i+1][j] = true;
        dfsVisit(i+1, j);
    }
    if (j-1 >= 0 && !visited[i][j-1] && assignment[i][j-1] == assignment[i][j]) {
        visited[i][j-1] = true;
        dfsVisit(i, j-1);
    }
    if (j+1 < w && !visited[i][j+1] && assignment[i][j+1] == assignment[i][j]) {
        visited[i][j+1] = true;
        dfsVisit(i, j+1);
    }
}

bool isValidAssignment() {
    visited = vector<vector<bool>>(2, vector<bool>(w, false));
    isFound = vector<bool>(n, false);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < w; j++) {
            if (!visited[i][j] && isFound[assignment[i][j]]) {
                return false; // disconnected component found
            }
            else if (!visited[i][j]) {
                visited[i][j] = true;
                isFound[assignment[i][j]] = true;
                dfsVisit(i, j);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (!isFound[i]) {
            return false; // unassigned component
        }
    }
    return true;
}

int main() {
    cin >> w >> n;
    reserved = vector<vector<int>>(2, vector<int>(w, 0));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < w; j++) {
            char next;
            cin >> next;
            if (next == '.') {
                reserved[i][j] = -1;
            }
            else {
                reserved[i][j] = next - '1';
            }
        }
    }

    assignment = vector<vector<int>>(2);
    for (int i = 0; i < 2; i++) {
        assignment[i] = vector<int>(w, 0);
        for (int j = 0; j < w; j++) {
            if (reserved[i][j] != -1) {
                assignment[i][j] = reserved[i][j];
            }
        }
    }

    int result = 0;
    if (isValidAssignment()) {
        result++;
    }
    while (incrementAssignment(0, 0)) {
        if (isValidAssignment()) {
            result++;
        }
    }

    cout << result << endl;

    return 0;
}