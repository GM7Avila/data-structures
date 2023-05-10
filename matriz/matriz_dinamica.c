#include <stdio.h>

int main() {

    int **m = NULL, nrows = 2, ncols = 3;

    m = (int**) calloc(nrows, sizeof(int*));
    for (int i = 0; i < nrows; i++) {
        m[i] = (int*) calloc(ncols, sizeof(int));
    }

}