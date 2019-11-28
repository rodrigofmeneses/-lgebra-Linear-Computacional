#include <stdlib.h>
#include <stdio.h>
#include "utils.c"

/**
 * Row Foward Substitution resolve sistemas com triangulares inferiores
 * linha por linha
 *
 * @param n = numero de linhas/colunas
 * @param g = ponteiro para a matriz G
 * @param b = ponteiro para o vetor b
 */
void row_foward_substitution(const int n, const double *g, double *b)
{
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++)
            b[i] -= g[i * n + j] * b[j];
        
        if(g[i * n + i] == 0){
            printf("Nao e possivel divisao por 0.\n");
            return;
        }
        b[i] /=  g[i * n + i];
    }
}

/**
 * Column Foward Substitution resolve sistemas com triangulares inferiores
 * coluna por coluna
 *
 * @param n = numero de linhas/colunas
 * @param g = ponteiro para a matriz G
 * @param b = ponteiro para o vetor b
 */
void column_foward_substitution(const int n, const double *g, double *b){
    for (int j = 0; j < n; j++)
    {
        if (g[j * n + j] == 0)
        {
            printf("Nao e possivel divisao por 0.\n");
            return;
        }

        b[j] /= g[j * n + j];

        for (int i = j + 1; i < n; i++)
            b[i] -= g[i * n + j] * b[j];
    }
}

/**
 * Row Backward Substitution resolve sistemas com triangulares superiores
 * linha por linha
 * 
 * @param n = numero de linhas/colunas
 * @param g = ponteiro para a matriz G
 * @param b = ponteiro para o vetor b
 */
void row_backward_substitution(const int n, const double *g, double *b)
{
    for(int i = n - 1; i >= 0; i--){
        for(int j = n - 1; j > i; j--)
            b[i] -= g[i * n + j] * b[j];
        
        if(g[i * n + i] == 0){
            printf("Nao e possivel divisao por 0.\n");
            return;
        }
        b[i] /=  g[i * n + i];
    }
}

/**
 * Column Backward Substitution resolve sistemas com triangulares superiores
 * coluna por coluna
 * 
 * @param n = numero de linhas/colunas
 * @param g = ponteiro para a matriz G
 * @param b = ponteiro para o vetor b
 */
void column_backward_substitution(const int n, const double *g, double *b){
    for (int j = n - 1; j >= 0; j--)
    {
        if (g[j * n + j] == 0)
        {
            printf("Nao e possivel divisao por 0.\n");
            return;
        }

        b[j] /= g[j * n + j];

        for (int i = j - 1; i >= 0; i--)
            b[i] -= g[i * n + j] * b[j];
    }
}

int main(int argc, char *argv[]){
    const int n = 4;
    const int nsamples = 3;

    // Instancias para teste

    double g_test[16] = { 2, 0, 0, 0,
                          -1, 2, 0, 0,
                          3, 1, -1, 0,
                          4, 1, -3, 3 };

    double g_test_transpose[16] = { 2, -1, 3, 4,
                                    0, 2, 1, 1, 
                                    0, 0, -1, -3,
                                    0, 0, 0, 3 };

    double b_test[4] = {2, 3, 2, 9};


    // Ponteiros para instancias de testes ou valores aleatórios

    double *g = g_test;
    // double *g = g_test_transpose; 
    double *b = b_test;

    // double *g = lower_triangular_generator(n);
    // double *b = random_vetor_generator(n);

    if (g == NULL || b == NULL)
    {
        printf("Nao ha memoria suficiente.\n");
        return EXIT_FAILURE;
    }

    printf("Matrix A\n");
    printMatrix(n, g);

    printf("\nVetor b - Original\n");
    printVetor(n, b);


    foward_substitution(n, g, b);
    // column_foward_substitution(n, g, b);

    // backward_substitution(n, g, b);
    // column_backward_substitution(n, g, b);

    printf("\nVetor b = Resultado\n");
    printVetor(n, b);

    // Apenas necessário g e b alocam memória (instancias aleatórias)
    // free(g);
    // free(b);

    return EXIT_SUCCESS;
}