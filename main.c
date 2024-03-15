#include <stdio.h>
#include <stdlib.h>

long long power(int base, int exp) {
    long long result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}


int charToDigit(char c) {
    return c - '0';
}

int isEmbediaPowerMatrix(char **matrix, int rows, int cols) {
    for (int i = 1; i < rows - 1; i++) {
        for (int j = 0; j < cols; j++) {
            int upper = charToDigit(matrix[i - 1][j]);
            int current = charToDigit(matrix[i][j]);
            int lower = charToDigit(matrix[i + 1][j]);
            if (power(lower, upper) != current) {
                return 0; //
            }
        }
    }
    return 1;
}

int main() {
    int rows, cols;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);


    char **matrix = (char **)malloc(rows * sizeof(char *));
    if (matrix == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    for (int i = 0; i < rows; i++) {
        matrix[i] = (char *)malloc(cols * sizeof(char));
        if (matrix[i] == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }
    }


    printf("Enter the elements of the matrix (as characters):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf(" %c", &matrix[i][j]);
        }
    }

    if (isEmbediaPowerMatrix(matrix, rows, cols)) {
        printf("The matrix is an Embedia Power Matrix.\n");
    } else {
        printf("The matrix is not an Embedia Power Matrix.\n");
    }

}
