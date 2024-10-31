#include <stdio.h>
#include<stdlib.h>
#include<time.h>

// funcao principal que seleciona coloca os meiores elementos do vetor no final
void organiza(int vetor[], int n)
{
    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (vetor[j] > vetor[j + 1])
            {
                int aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
        }
    }
}

int main() {
    srand(time(NULL));  // Inicializa a semente para números aleatórios

    // Loop para tamanhos de 10 a 1.000.010 com incrementos de 100.000
    for (int i = 10; i <= 1000010; i += 100000) {
        printf("Iniciando ordenacao para vetor de tamanho %d\n", i);  // Verifica onde o código para
        int *vetor = (int*)malloc(i * sizeof(int));
        if (!vetor) {
            printf("Falha na alocacao de memória para tamanho %d.\n", i);
            return 1;
        }

        // Preenche o vetor com números aleatórios
        for (int j = 0; j < i; j++) {
            vetor[j] = rand() % i;
        }

        // Mede o tempo de execução 
       clock_t inicio = clock();
        organiza(vetor, i);
        clock_t fim = clock();
        double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

        printf("Tempo para vetor de %d posicoes = %.3f segundos\n", i, tempo);

        free(vetor);  // Libera a memória alocada
    }

    return 0;
}