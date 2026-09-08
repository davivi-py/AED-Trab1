// TRABALHO 1 - Contagem de Operacoes e de Tempo de Execucao

/* Membros:
Andre Gazebayukian Abrahamian - 11734701
Davi de Alcantara Lima - 16861647
Esther Vieira Parise Bianchini - 15636362
Sarah Mendes Gurgel - 14778859
*/

//Bibliotecas:
# include <stdio.h>
# include <stdlib.h>
# include <windows.h> //QueryPerformanceCounter

int inversao(int *v, int N){
    int temp;

    for(int i = 0; i < N / 2; i++){
        temp = v[i];
        v[i] = v[N - 1 - i];
        v[N - 1 - i] = temp;
    }

    return 1;
}

int busca_sequencial(const int *vetor, int P, int N){

    for(int i = 0; i < N; i++){
        if(vetor[i] == P){
            return 1;       //se achou o P no vetor
        }
    }

    return 0;   //caso nao achou
}

int busca_interativa(const int *v, int P, int N){
    int inicio = 0, fim = N - 1, meio;

    while(inicio <= fim){
        meio = (inicio + fim) / 2;
        if(v[meio] == P){
            return 1;
        }else if(v[meio] < P){
            inicio = meio + 1;
        }else{
            fim = meio - 1;
        }
    }

    return 0;
}

int busca_recursiva(const int *v, int inicio, int fim, int P){

    if (inicio > fim) { //elemento não encontrado
        return 0;
    }

    int meio = inicio + (fim - inicio) / 2;

    if (v[meio] == P) { // Se o elemento estiver no meio, retorna o índice
        return 1;
    }

    // Se o elemento for menor que o meio, busca na metade esquerda
    if (v[meio] > P) {
        return busca_recursiva(v, inicio, meio - 1, P);
    }

    // Se o elemento for maior que o meio, busca na metade direita
    return busca_recursiva(v, meio + 1, fim, P);
}


int main(){
    LARGE_INTEGER freq, inicio, fim;
    double tempo_decorrido;

    //Obtem a frequencia do contador de alta resolucao
    QueryPerformanceFrequency(&freq);

    int Q; //comando
    int N; //qtd de elementos do vetor
    int *v; //vetor
    int P; //valor a ser procurado nas buscas
    int resultado;

    scanf("%d", &N);                // quantidade de elementos do vetor
    v = malloc(sizeof(int)*N);  //cria o vetor

    if(v == NULL){ // verifica se o vetor foi alocado corretamente
        return 0;
    }

    for(int i = 0; i < N; i++){     //aloca os elementos no vetor
        scanf("%d", &v[i]);
    }


    scanf("%d", &Q);                //Comando a ser realizado

    while(Q != 5){
        if(Q == 1){                     //Inversao da ordem
            QueryPerformanceCounter(&inicio);

            for(volatile long i = 0; i < 100; i++){
                inversao(v, N);
            }

            QueryPerformanceCounter(&fim);

            tempo_decorrido = (double)(fim.QuadPart - inicio.QuadPart)/ freq.QuadPart;
            tempo_decorrido = tempo_decorrido / 100.0;
            printf("Tempo decorrido: %.9f segundos \n", tempo_decorrido);

            //Faz uma inversão adicional para deixar o vetor invertido
            inversao(v, N);

            for(int i = 0; i < N; i++){
                printf("%d ", v[i]);
            }
            printf("\n");
            inversao(v, N);
        }else if(Q == 2){               //Busca sequencial
            scanf("%d", &P);            //Valor a ser buscado

            QueryPerformanceCounter(&inicio);

            for(volatile long i = 0; i < 100; i++){
                resultado = busca_sequencial(v, P, N);
            }

            QueryPerformanceCounter(&fim);

            //Calcula o tempo decorrido em segundos (com fracao)
            tempo_decorrido = (double)(fim.QuadPart - inicio.QuadPart)/ freq.QuadPart;
            tempo_decorrido = tempo_decorrido / 100.0;

            printf("Tempo decorrido: %.9f segundos \n", tempo_decorrido);

            if(resultado == 1){
                printf("SIM\n");
            }else{
                printf("NAO\n");
            }

        }else if(Q == 3 ){              //Buca binaria Interativa
            scanf("%d", &P);            //Valor a ser buscado

            QueryPerformanceCounter(&inicio);

            for(volatile long i = 0; i < 100; i++){
                resultado = busca_interativa(v, P, N);
            }

            QueryPerformanceCounter(&fim);

            //Calcula o tempo decorrido em segundos (com fracao)
            tempo_decorrido = (double)(fim.QuadPart - inicio.QuadPart)/ freq.QuadPart;
            tempo_decorrido = tempo_decorrido / 100.0;

            printf("Tempo decorrido: %.9f segundos \n", tempo_decorrido);

            if(resultado == 1){
                printf("SIM\n");
            }else{
                printf("NAO\n");
            }

        }else if(Q == 4){               //Busca binaria Recursiva
            scanf("%d", &P);            //Valor a ser buscado

             QueryPerformanceCounter(&inicio);

            for(volatile long i = 0; i < 100; i++){
                resultado = busca_recursiva(v, 0, N - 1, P); //(vetor, começo, final, procurado)
            }

            QueryPerformanceCounter(&fim);

            //Calcula o tempo decorrido em segundos (com fracao)
            tempo_decorrido = (double)(fim.QuadPart - inicio.QuadPart)/ freq.QuadPart;
            tempo_decorrido = tempo_decorrido / 100.0;

            printf("Tempo decorrido: %.9f segundos \n", tempo_decorrido);

            if(resultado == 1){
                printf("SIM\n");
            }else{
                printf("NAO\n");
            }
        }
        scanf("%d", &Q); // atualiza o valor do comando
    }
    return 0;
}
