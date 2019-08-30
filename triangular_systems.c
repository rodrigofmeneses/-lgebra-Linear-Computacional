#include <stdlib.h>
#include <stdio.h>

void printMatrix(const int n, const double *a)
{
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            printf("%f ", a[i * n + j]);
        printf("\n");
    }
}

void printVetor(const int n, const double *b)
{
    for (int i = 0; i < n; i++)
        printf("%f ", b[i]);
    printf("\n");
} 

/**
 * Por algum motivo o código não está conseguindo acessar as posições
 * da matriz g, apenas retornando 2. 
 *
 * @param n = numero de linhas/colunas
 * @param g = ponteiro para a matriz G
 * @param b = ponteiro para o vetor b
 */
void lower_triangular(const int n, const double *g, double *b)
{
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++)
            b[i] -= g[i * n + j] * b[j];
        
        if(g[i * n] == 0){
            printf("Nao e possivel divisao por 0.\n");
            return;
        }
        b[i] /=  g[i * n];
    }
}

/**
 * Lower triangular generator
 */
int main(int argc, char *argv[]){
    const int n = 4;
    const int nsamples = 3;

    double *g = (double *)malloc(n * n * sizeof(double));
    double *b = (double *)malloc(n * sizeof(double));

    if (g == NULL || b == NULL)
    {
        printf("Nao ha memoria suficiente.\n");
        return EXIT_FAILURE;
    }

    // Usar valores aleatórios para 'a' e 'b'
    for (int i = 0; i < n; ++i)
    {
        // A função rand() gera valores de 0 a RAND_MAX
        // esta sendo dividido para serem valores entre 0 e 1
        b[i] = ((double)rand()) / RAND_MAX;
        for (int j = 0; j <= i; ++j)
            g[i * n + j] = ((double)rand()) / RAND_MAX;
    }


    // Test
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

    printf("Matrix A\n");
    printMatrix(n, g);

    printf("Vetor b\n");
    printVetor(n, b);

    lower_triangular(n, g, b);

    //printMatrix(n, g);
    printf("\nVetor y\n");
    printVetor(n, b);

    free(g);
    free(b);

    return EXIT_SUCCESS;
}