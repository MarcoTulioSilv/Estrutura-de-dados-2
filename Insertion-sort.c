#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Funcao principal onde cada elemento sera comparado com os demais para encontrar sua posicao
void insertion(int vetor[], int n)
{
    int at = 0, prox = 0, aux;
    for (at = 1; at < n; at++)
    {
        prox = at;
        while (prox>0&&vetor[prox-1]>vetor[prox])
        {
            if(vetor[prox-1]>vetor[prox]){
                aux=vetor[prox];
                vetor[prox]=vetor[prox-1];
                vetor[prox-1]=aux;
                prox--;
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
        insertion(vetor, i);
        clock_t fim = clock();
        double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

        printf("Tempo para vetor de %d posicoes = %.3f segundos\n", i, tempo);

        free(vetor);  // Libera a memória alocada
    }

    return 0;
}