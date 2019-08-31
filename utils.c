#include <stdlib.h>
#include <stdio.h>

/**
 * Imprime Matriz a de dimensão n x n
 * 
 * @param n = tamanho da Matriz quadrada n x n
 * @param a = ponteiro para a Matriz
 */
void printMatrix(const int n, const double *a)
{
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            printf("%.2f ", a[i * n + j]);
        printf("\n");
    }
}

/**
 * Imprime Vetor de dimensão n
 * 
 * @param n = tamanho do vetor
 * @param b = ponteiro para o vetor
 */
void printVetor(const int n, const double *b)
{
    for (int i = 0; i < n; i++)
        printf("%.2f ", b[i]);
    printf("\n");
} 

/**
 * Aloca memória e gera uma matriz triangular inferior de dimensão n x n
 * 
 * @param n = tamanho da Matriz quadrada n x n
 * 
 * @return ponteiro para o bloco de memória alocado
 */
double* lower_triangular_generator(const int n)
{
    double *g = (double *)malloc(n * n * sizeof(double));
    if (g == NULL)
        return NULL;

    for (int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            g[i * n + j] = 0;
    

    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= i; ++j)
            g[i * n + j] = ((double)rand()) / RAND_MAX;
    
    return g;
}

/**
 * Aloca memória e gera uma matriz triangular superior de dimensão n x n
 * 
 * @param n = tamanho da Matriz quadrada n x n
 * 
 * @return ponteiro para o bloco de memória alocado
 */
double* upper_triangular_generator(const int n)
{
    double *g = (double *)malloc(n * n * sizeof(double));
    if (g == NULL)
        return NULL;

    for (int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            g[i * n + j] = 0;

    for (int i = 0; i < n; ++i)
        for (int j = i; j < n; ++j)
            g[i * n + j] = ((double)rand()) / RAND_MAX;
    
    return g;
}
/**
 * Aloca memória e gera um vetor de dimensão n
 * 
 * @param n = tamanho do vetor
 * 
 * @return ponteiro para o bloco de memória alocado
 */
double* random_vetor_generator(const int n){
    double *b = (double *)malloc(n * sizeof(double));
    if (b == NULL)
        return NULL;

    for (int i = 0; i < n; i++)
        b[i] = 0;

    for (int i = 0; i < n; i++)
        b[i] = ((double)rand()) / RAND_MAX;
    
    return b;
}