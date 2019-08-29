#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "matvec.c"

/**
 * Função principal, onde serão testados os algorítmos 
 */
int main(int argc, char *argv[]){
    const int n = 12000;
    const int nsamples = 3;

    /** Ponteiro para double apontando para espaços na memória que estão sendo alocados
    * (double *) definido o tipo de ponteiro
    * malloc = memory allocation - aloca um bloco de bytes consecutivos na memória
    * é acompanhado do free, para liberar a memória alocada.
    * equivalente ao new e delete do c++,
    * 
    * A matriz 'a' está sendo armazenada em um bloco sequencial
    */ 
    double *a = (double *)malloc(n * n * sizeof(double));
    double *x = (double *)malloc(n * sizeof(double));
    double *b = (double *)malloc(n * sizeof(double));

    /**
     * Em caso de memória insuficiente, o ponteiro apontará para Nulo
     */
    if (a == NULL || x == NULL || b == NULL)
    {
        printf("Nao ha memoria suficiente.\n");
        return EXIT_FAILURE;
    }

    // Usar valores aleatórios para 'a' e 'x'
    for (int i = 0; i < n; ++i)
    {
        // A função rand() gera valores de 0 a RAND_MAX
        // esta sendo dividido para serem valores entre 0 e 1
        x[i] = ((double)rand()) / RAND_MAX;
        for (int j = 0; j < n; ++j)
            a[i * n + j] = ((double)rand()) / RAND_MAX;
    }

    clock_t initial_time;
    double total_time;

    // timing matvec_row
    initial_time = clock();
    for (int i = 0; i < nsamples; ++i)
        matvec_row(n, n, a, x, b);
    total_time = (clock() - initial_time) / CLOCKS_PER_SEC;
    printf("total_time(matvec_row    ) %f secs\n", total_time / nsamples);

    // timing matvec_col
    initial_time = clock();
    for (int i = 0; i < nsamples; ++i)
        matvec_col(n, n, a, x, b);
    total_time = (clock() - initial_time) / CLOCKS_PER_SEC;
    printf("total_time(matvec_col    ) %f secs\n", total_time / nsamples);

    // Desalocando memória
    free(a);
    free(b);
    free(x);

    return EXIT_SUCCESS;
}