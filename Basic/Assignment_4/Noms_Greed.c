#include <stdio.h>

#define N 9

int is_safe(int grid[N][N], int row, int col, int num) {
    for (int i = 0; i < N; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return 0;
        }
    }

    int box_start_row = (row / 3) * 3;
    int box_start_col = (col / 3) * 3;
    for (int i = box_start_row; i < box_start_row + 3; i++) {
        for (int j = box_start_col; j < box_start_col + 3; j++) {
            if (grid[i][j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

int solve_sudoku(int grid[N][N], int row, int col) {
    if (row == N - 1 && col == N) {
        return 1;
    }

    if (col == N) {
        return solve_sudoku(grid, row + 1, 0);
    }

    if (grid[row][col] != 0) {
        return solve_sudoku(grid, row, col + 1);
    }

    for (int num = 1; num <= N; num++) {
        if (is_safe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solve_sudoku(grid, row, col + 1)) {
                return 1;
            }
            grid[row][col] = 0;
        }
    }

    return 0;
}

int main() {
    int grid[N][N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &grid[i][j]);
            if (grid[i][j] == -1) {
                grid[i][j] = 0;
            }
        }
    }

    if (solve_sudoku(grid, 0, 0)) {
        printf("Solved Sudoku:\n");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
    }
    else {
        printf("No solution found.\n");
    }

    return 0;
}