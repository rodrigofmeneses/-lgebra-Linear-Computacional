#include <stdlib.h>
#include <stdio.h>

/**
 * 
 * @param n = dimensão da matriz (quadradas)
 * @param a = ponteiro para a matriz A
 * @param x = ponteiro para a matriz X
 * @param b = ponteiro para a matriz B
 * 
 * @info Multiplicação matriz matriz
 * 
 * @info n^3 flops
 */

void matmult(const int n, const double *a, const double *x, double *b)
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            b[i * n + j] = 0;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for(int k = 0; k < n; ++k)
                b[i * n + j] += a[i * n + k] * x[k * n + j];
}