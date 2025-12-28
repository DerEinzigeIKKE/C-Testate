#include <stdlib.h>
#include <malloc.h> // MAC OS X: Auskommentieren!
#include <stdio.h> // Output zu Testzwecken
#include "testat-8.h"

/********************************************************************
 * Die folgenden drei Funktionen duerfen nicht veraendert werden!!
 *******************************************************************/
matrix matrix_create(int n) {
    matrix m = {n, malloc(n*n*sizeof(double))};
    return m;
}

void matrix_destroy(matrix m){
    free(m.p);
}

double * matrix_element(matrix A, int z, int s) {
    return A.p + (z - 1) * A.n + (s - 1);
}

/*******************************************************************
 * Implementieren Sie die folgenden beiden Funktionen.
 ******************************************************************/
double matrix_det (matrix A) {
    double d = 0;
    if (A.n == 1) {
        return *matrix_element(A, 1, 1);
    }
    for (int s = 1; s <= A.n; s++) {
        matrix B = matrix_sub(A, s);
        double sign = (s % 2 == 0) ? -1.0 : 1.0;
        d += sign * (*matrix_element(A, 1, s)) * matrix_det(B);
        matrix_destroy(B);
    }
    return d;
}

matrix matrix_sub (matrix A, int k) {
    matrix B = matrix_create(A.n - 1);
    int row = 1;  // Zeilenindex für B (1-basiert)
    for (int z = 2; z <= A.n; z++) {  // Zeile 1 überspringen
        int col = 1;  // Spaltenindex für B
        for (int s = 1; s <= A.n; s++) {
            if (s != k) {  // Spalte k überspringen
                *matrix_element(B, row, col) = *matrix_element(A, z, s);
                col++;
            }
        }
        row++;
    }
    return B;
}

int main() {
    matrix A = matrix_create(3);
    int k = 2; // Beispielspalte
    //Matrix befuellen
    for (int z = 1; z <= A.n; z++) {
        for (int s = 1; s <= A.n; s++) {
            *matrix_element(A, z, s) = z * 10 + s;
        }
    }

    //Aus Matrix ausgeben
    for (int z = 1; z <= A.n; z++) {
        for (int s = 1; s <= A.n; s++) {
            double wert = *matrix_element(A, z, s);
            printf("%.2f ", wert);
        }
        printf("\n");
    }
    printf("\n");
    //Submatrix auslesen
    matrix B = matrix_sub(A, k);

    //Aus Submatrix ausgeben
    for (int z = 1; z <= B.n; z++) {
        for (int s = 1; s <= B.n; s++) {
            double wert = *matrix_element(B, z, s);
            printf("%.2f ", wert);
        }
        printf("\n");
    }
    printf("Determinante: %.2f\n", matrix_det(A));
    matrix_destroy(A);
    matrix_destroy(B);
    return 0;
}