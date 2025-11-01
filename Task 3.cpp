#include <stdio.h>

void updateSector(int grid[3][3], int row, int col, int flag, int value) {
    int bit = 1 << flag;
    if (value == 1)
        grid[row][col] |= bit;
    else
        grid[row][col] &= ~bit;
}

void querySector(int grid[3][3], int row, int col) {
    int val = grid[row][col];
    printf("Sector (%d,%d): ", row, col);
    printf("Power: %s, ", (val & 1) ? "ON" : "OFF");
    printf("Overload: %s, ", (val & 2) ? "YES" : "NO");
    printf("Maintenance: %s\n", (val & 4) ? "REQUIRED" : "NORMAL");
}

void systemDiagnostic(int grid[3][3]) {
    int overload = 0, maint = 0, i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (grid[i][j] & 2) overload++;
            if (grid[i][j] & 4) maint++;
        }
    }
    printf("Overloaded sectors: %d\n", overload);
    printf("Maintenance required: %d\n", maint);
}

void displayMenu() {
    printf("\n1. Update Sector Status");
    printf("\n2. Query Sector Status");
    printf("\n3. Run System Diagnostic");
    printf("\n4. Exit\n");
}

int main() {
    int grid[3][3] = {0};
    int choice, row, col, flag, value;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 4) break;

        if (choice == 1) {
            printf("Enter row and column: ");
            scanf("%d %d", &row, &col);
            printf("Enter flag (0=Power,1=Overload,2=Maintenance): ");
            scanf("%d", &flag);
            printf("Enter value (1=Set,0=Clear): ");
            scanf("%d", &value);
            updateSector(grid, row, col, flag, value);
        } 
        else if (choice == 2) {
            printf("Enter row and column: ");
            scanf("%d %d", &row, &col);
            querySector(grid, row, col);
        } 
        else if (choice == 3) {
            systemDiagnostic(grid);
        } 
        else {
            printf("Invalid choice.\n");
        }
    }
    return 0;
}

