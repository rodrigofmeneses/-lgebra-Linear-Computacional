#include <stdlib.h>
#include <stdio.h>

/**
 * 
 * @param n = numero de linhas/colunas (quadrada)
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

/**
 *
 * @param bs = número de blocos 
 * @param n = numero de linhas/colunas
 * @param a = ponteiro para matriz A que será particionada
 * @param x = ponteiro para matriz X que será particionada
 * @param b = ponteiro para a matriz B que será preenchida
 * 
 * @info Assume-se que o bloco será uma matriz quadrada e 
 * será um multiplo da tamanho de n.
 * 
 * @info Assume-se que o usuário particionou a matriz A e que todos os 
 * blocos estão de forma contínua na memória.
 * 
 */

void matmult_block(const int bs, const int n, const double *a, const double *x, double *b)
{
    // Matriz nao cumpre os requisitos, logo retorna nada.
    if(n % bs) return;

    // Zerar matriz B
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            b[i * n + j] = 0;

    // Número de elementos de cada bloco
    const int BS = bs * bs;
    // Número de blocos por linha/coluna
    const int N = n / bs;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
            {
                // Cria-se um ponteiro para o primeiro elemento do bloco A,
                const double *aik = &(a[i * N * BS + k * BS]);
                // um ponteiro para o primeiro elemento do bloco X
                const double *xkj = &(x[k * N * BS + j * BS]);
                // e um ponteiro para b.
                double *bij = &(b[i * N * BS + j * BS]);
                // Chama-se a função de multiplicação de matrizes para os devidos blocos
                matmult(bs, aik, xkj, bij);
            }
}