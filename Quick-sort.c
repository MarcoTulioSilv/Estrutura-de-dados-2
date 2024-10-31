#include <stdio.h>
#include<stdlib.h>
#include<time.h>

// funcao para particioanar o vetor deixando os numeros menores que o pivo a sua esquerda
int particiona(int vetor[], int inicio, int fim)
{
    int pivo = vetor[inicio];
    int s = inicio + 1;
    int aux;
    for (int i = inicio + 1; i <= fim; i++)
    {
        if (vetor[i] < pivo)
        {
            aux = vetor[s];
            vetor[s] = vetor[i];
            vetor[i] = aux;
            s++;
        }
    }
    aux = vetor[inicio];
    vetor[inicio] = vetor[s-1];
    vetor[s-1] = aux;
    return s-1;
}
//funcao principal onde o vetor e particionado e chamado recursivamente ate que o fim seja igual o começo(nao e possivel divisao)
void quick(int vetor[],int inicio, int fim){
    if(inicio<fim){
        int pivo= particiona(vetor, inicio, fim);
        quick(vetor,inicio,pivo-1);
        quick(vetor,pivo+1,fim);
    }
}

int main() {
    srand(time(NULL));  // Inicializa a semente para números aleatorios

    // Loop para tamanhos de 10 a 1.000.010 com incrementos de 100.000
    for (int i = 10; i <= 1000010; i += 100000) {
        printf("Iniciando ordenacao para vetor de tamanho %d\n", i);  // mostra o inicio da ordenacao
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
        quick(vetor, 0, i);
        clock_t fim = clock();
        double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

        printf("Tempo para vetor de %d posicoes = %.3f segundos\n", i, tempo);

        free(vetor);  // Libera a memória alocada
    }

    return 0;
}