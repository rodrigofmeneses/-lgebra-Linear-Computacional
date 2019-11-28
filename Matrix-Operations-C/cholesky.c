#include <stdlib.h>
#include <stdio.h>
#include "utils.c"

/**
 * Seja A uma matriz simétrica e definida positiva  
 * (Matriz em que para qualquer valor de xi  nesse sistema:
 * x * A * x^transposto = b, bi será maior 0) 
 * 
 * Então A pode ser decomposta de maneira única no produto:
 * A = R(traspose) * R
 * sendo R é uma matriz triangular Superior 
 * com diagonal principal maior que 0
 */

/**
 * Algoritmo para encontrar a matriz R
 * 
 * A ideia é que se A = Rt * R
 * então fazendo uma multiplicação matricial 
 * conseguimos obter todos os componentes de R
 * considerando que rii != 0 e aii > 0 (o que garante que é o numero é Real)
 */


/**
 * @param n = tamanho da Matriz quadrada n x n
 * @param a = ponteiro para a Matriz
 * 
 * @info Assume-se que a matriz informada é simétrica, e definida positiva.
 * 
 * @info A matriz R sobreescreverá A e será zerado a parte inferior
 * para que R seja triangular superior.
 */

void cholesky(const int n, double *a)
{
    for(int i = 0; i < n; i++)
    {
        // Preenchendo diagonal principal
        for (int k = 0; k < i; k++)
            a[i * n + i] -= a[k * n + i] * a[k * n + i];
        // Se diagonal principal menor que 0 entao resultado não se encontra nos reais
        if(a[i * n + i] <= 0)
            break;
        // Resolvendo o sistema linha a linha
        for(int j = i + 1; j < n; j++)
        {
            for (int k = 0; k < i; k++)
                a[i * n + j] -= a[k * n + i] * a[k * n + j];
            a[i * n + j] /= a[i * n + i];
        }
    }

    // Já que R é triangular superior, parte inferior zerada.
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            a[i * n + j] = 0;
}

int main(int argc, char *argv[]){
    const int n = 3;

    double a_test[9] = {1, 1, 1,
                        1, 2, 2,
                        1, 2, 3};

    double *a = a_test;

    printf("Matrix A\n");
    printMatrix(n, a);

    cholesky(n, a);

    printf("\nMatriz R - Cholesky\n");
    printMatrix(n, a);

    return EXIT_SUCCESS;
}