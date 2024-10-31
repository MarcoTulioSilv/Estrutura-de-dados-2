#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// funcao auxiliar para intercalar o vetor
void intercalar(int *vetor, int inicio, int meio,int fim)
{
    int i = inicio, j = meio, k = 0;
    int aux[fim - inicio];
    while (i < meio && j < fim)
    {
        if (vetor[i] <= vetor[j])
        {
            aux[k++] = vetor[i++];
        }
        else
        {
            aux[k++] = vetor[j++];
        }
    }
    while (i < meio)
    {
        aux[k++] = vetor[i++];
    }

    while (j < fim)
    {
        aux[k++] = vetor[j++];
    }

    for (i = inicio, k = 0; i < fim; i++, k++)
    {
        vetor[i] = aux[k];
    }
}
// funcao principal onde o vertor e divido e chamado recursivamente 
void merge(int *vetor, int inicio, int fim)
{
    if (fim - inicio > 1)
    {
        int meio = (inicio + fim) / 2;
        merge(vetor, inicio, meio);
        merge(vetor, meio, fim);
        intercalar(vetor, inicio, fim, meio);
    }
}

int main() {
    srand(time(NULL));  // Inicializa a semente para números aleatórios

    // Loop para tamanhos de 100010 a 1.000.000 com incrementos de 100.000
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

        // Mede o tempo de execução do merge sort
       clock_t inicio = clock();
        merge(vetor, 0, i);
        clock_t fim = clock();
        double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

        printf("Tempo para vetor de %d posicoes = %.3f segundos\n", i, tempo);

        free(vetor);  // Libera a memória alocada
    }

    return 0;
}