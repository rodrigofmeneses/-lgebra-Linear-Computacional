#include <stdlib.h>
#include <stdio.h>

/**
 * Ax = b
 * A função recebe os ponteiros para a matriz A, e os vetores x e b
 * que já estão alocados com as respectivas dimensões nrows e ncols
 * 
 * @param nrows = número de linhas
 * @param ncols = número de colunas
 * @param a = ponteiro para a matriz A
 * @param x = ponteiro para o vetor x
 * @param b = ponteiro para o vetor b
 * 
 * 
 * @info Estratégia visa multiplicar os elementos da linha
 * pois em C os elementos são armazenados na memória ordenadamente
 * e como estratégia de otimização de hardware o processador move a memória
 * em pequenos blocos na tentativa de diminuir o número de acessos à memórias mais lentas.
 * 
 * @info const = os valores não serão alterados 
 * @infor n^2 flops
 */
void matvec_row(const int nrows, const int ncols, const double *a, const double *x, double *b)
{
    for (int i = 0; i < nrows; ++i)
        b[i] = 0;

    for (int i = 0; i < nrows; ++i)
        for (int j = 0; j < ncols; ++j)
            b[i] += a[i * ncols + j] * x[j];
}


/**
 * @param nrows = número de linhas
 * @param ncols = número de colunas
 * @param a = ponteiro para a matriz A
 * @param x = ponteiro para o vetor x
 * @param b = ponteiro para o vetor b
 * 
 * 
 * @info Função quase idêntica a matvec_row, invertendo apenas a ordem dos laços,
 * fazendo que ao invés de multiplicar ordenadamente elementos de mesma linha,
 * agora multiplique ordenadamente elementos da coluna
 * 
 * @info Essa estratégia visa explorar a falha que o matvec_row está contornando
 * a ideia é que o desempenho nesta função seja menor. 
 */
void matvec_col(const int nrows, const int ncols, const double *a, const double *x, double *b)
{
    for (int i = 0; i < nrows; ++i)
        b[i] = 0;

    for (int j = 0; j < ncols; ++j)
        for (int i = 0; i < nrows; ++i)
            b[i] += a[i * ncols + j] * x[j];
}