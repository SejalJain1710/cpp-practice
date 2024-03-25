#include <bits/stdc++.h>
using namespace std;

#define ROW 5
#define COL 5

int isValid(int mat[][COL], int row, int col) {
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && (mat[row][col]);
}

void DFS(int mat[][COL], int row, int col) {
    static int rowNbr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    static int colNbr[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

    mat[row][col] = 0;

    for (int k = 0; k < 8; ++k)
        if (isValid(mat, row + rowNbr[k], col + colNbr[k]))
            DFS(mat, row + rowNbr[k], col + colNbr[k]);
}

int countIslands(int mat[][COL]) {
    int count = 0;
    for (int i = 0; i < ROW; ++i)
        for (int j = 0; j < COL; ++j) {
            if (mat[i][j]) {
                DFS(mat, i, j);
                ++count;
            }
        }
    return count;
}

int main() {
    int mat[][COL] = { { 1, 1, 0, 0, 0 },
                     { 0, 1, 0, 0, 1 },
                     { 1, 0, 0, 1, 1 },
                     { 0, 0, 0, 0, 0 },
                     { 1, 0, 1, 0, 1 } };

    cout << "Number of islands is: " << countIslands(mat) << endl;
    return 0;
}
