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
            printf("%f ", a[i * n + j]);
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
        printf("%f ", b[i]);
    printf("\n");
} 

/**
 * Foward Substitution resolve sistemas com triangulares inferiores
 *
 * @param n = numero de linhas/colunas
 * @param g = ponteiro para a matriz G
 * @param b = ponteiro para o vetor b
 */
void foward_substitution(const int n, const double *g, double *b)
{
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++)
            b[i] -= g[i * n + j] * b[j];
        
        if(g[i * n] == 0){
            printf("Nao e possivel divisao por 0.\n");
            return;
        }
        b[i] /=  g[i * n + i];
    }
}

/**
 * Backward Substitution resolve sistemas com triangulares superiores
 * 
 * @param n = numero de linhas/colunas
 * @param g = ponteiro para a matriz G
 * @param b = ponteiro para o vetor b
 */
void backward_substitution(const int n, const double *g, double *b)
{
    for(int i = n - 1; i <= 0; i--){
        for(int j = n - 1; j <= i; j--)
            b[i] -= g[i * n + j] * b[j];
        
        if(g[i * n] == 0){
            printf("Nao e possivel divisao por 0.\n");
            return;
        }
        b[i] /=  g[i * n + i];
    }
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
        b[i] = ((double)rand()) / RAND_MAX;
    
    return b;
}

int main(int argc, char *argv[]){
    const int n = 4;
    const int nsamples = 3;

    double *g = upper_triangular_generator(n);
    double *b = random_vetor_generator(n);

    if (g == NULL || b == NULL)
    {
        printf("Nao ha memoria suficiente.\n");
        return EXIT_FAILURE;
    }

    printf("Matrix A\n");
    printMatrix(n, g);

    printf("Vetor b\n");
    printVetor(n, b);

    /**
    g[0] = 2;
    g[4] = -1;
    g[5] = 2;
    g[8] = 3;
    g[9] = 1;
    g[10] = -1;
    g[12] = 4;
    g[13] = 1;
    g[14] = -3;
    g[15] = 3;

    b[0] = 2;
    b[1] = 3;
    b[2] = 2;
    b[3] = 9;
    */

    foward_substitution(n, g, b);
    backward_substitution(n, g, b);

    printVetor(n, b);

    free(g);
    free(b);

    return EXIT_SUCCESS;
}