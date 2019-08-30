#include <stdlib.h>
#include <stdio.h>

/**
 * Seja A uma matriz definida positiva.  
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
 * @info A matriz R sobreescreverá A
 */

void cholesky(const int n, double *a)
{
    for(int i = 0; i < n; i++)
    {
        for (int k = 0; k < i; k++)
            a[i * n + i] -= a[k * n + i] * a[k * n + i];
        
        if(a[i * n + i] <= 0)
            break;

        for(int j = i + 1; j < n; j++)
        {
            for (int k = 0; k < i; k++)
                a[i * n + j] -= a[k * n + i] * a[k * n + j];
            a[i * n + j] /= a[i * n + i];
        }
    }
}

int main(int argc, char *argv[]){
    
    return EXIT_SUCCESS;
}