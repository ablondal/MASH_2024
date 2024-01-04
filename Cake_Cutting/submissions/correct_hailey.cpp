#include <iostream>
#include <vector>
using namespace std;

// Retrieve n-bit mask from mask_counter
vector<int> get_mask(const int& n, const int& mask_counter) {
    vector<int> mask(n, 0);
    int m = mask_counter;
    for (int i = 0; i < n; i++) {
        mask[i] = m % 2;
        m /= 2;
    }
    return mask;
}

// Retrieve vector from col_counter
vector<int> get_col(const int& n, const int& col_counter) {
    vector<int> col(2, 0);
    col[0] = col_counter % n;
    col[1] = (col_counter / n) % n;
    return col;
}

int main() {
    int w, n;
    cin >> w >> n;
    vector<vector<int>> reserved(2, vector<int>(w, 0));
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

    const int mask_max = 1 << n;
    const int col_max = n*n;

    // DP on number of ways to cut the first i columns of cake based on the two parameters
    // 1. mask: n-bit binary mask of appearance of person in the first i columns
    // 2. col: 2 numbers from {1, ..., n} representing who takes each row of the cake in column i
    vector<vector<vector<int>>> DP(w);
    for (int i = 0; i < w; i++) {
        DP[i] = vector<vector<int>>(mask_max);
        for (int j = 0; j < mask_max; j++) {
            DP[i][j] = vector<int>(col_max, 0);
        }
    }

    // column 0
    for (int c = 0; c < col_max; c++) {
        vector<int> col = get_col(n, c);
        vector<int> mask(n, 0);
        mask[col[0]] = 1;
        mask[col[1]] = 1;
        if (reserved[0][0] != -1 && reserved[0][0] != col[0]) continue;
        if (reserved[1][0] != -1 && reserved[1][0] != col[1]) continue;

        int m = 0;
        for (int j = n-1; j >= 0; j--) {
            m *= 2;
            m += mask[j];
        }
        DP[0][m][c] = 1;
    }

    // column i
    for (int i = 0; i < w-1; i++) {
        for (int m1 = 0; m1 < mask_max; m1++) {
            for (int c1 = 0; c1 < col_max; c1++) {
                for (int c2 = 0; c2 < col_max; c2++) {
                    vector<int> col1 = get_col(n, c1);
                    vector<int> col2 = get_col(n, c2);
                    if (reserved[0][i+1] != -1 && reserved[0][i+1] != col2[0]) continue;
                    if (reserved[1][i+1] != -1 && reserved[1][i+1] != col2[1]) continue; // (3)
                    vector<int> mask1 = get_mask(n, m1);
                    if (mask1[col1[0]] == 0 || mask1[col1[1]] == 0) continue; // (1)
                    vector<int> mask2(n, 0);
                    mask2[col2[0]] = 1;
                    mask2[col2[1]] = 1; // mask2 construction

                    // Check condition (2)
                    bool valid = true;
                    for (int j = 0; j < n; j++) {
                        if (mask1[j] == 1 && mask2[j] == 1) {
                            if (!((col1[0] == j && col2[0] == j)
                                || (col1[1] == j && col2[1] == j))) {
                                valid = false;
                                break;
                            }
                        }
                    }
                    if (!valid) continue;

                    vector<int> new_mask(n, 0);
                    int new_mask_counter = 0;
                    for (int j = n-1; j >= 0; j--) {
                        new_mask[j] = mask1[j] | mask2[j];
                        new_mask_counter *= 2;
                        new_mask_counter += new_mask[j];
                    }
                    DP[i+1][new_mask_counter][c2] += DP[i][m1][c1];
                    DP[i+1][new_mask_counter][c2] %= 100000007;
                }
            }
        }
    }

    int result = 0;
    for (int c = 0; c < col_max; c++) {
        result += DP[w-1][mask_max-1][c];
        result %= 100000007;
    }

    cout << result << endl;

    return 0;
}