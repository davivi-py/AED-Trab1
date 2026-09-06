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

int inversao(v,N){
    printf("vc esta em inversao\n");
    return 0;
}

int busca_sequencial(const int *vetor, int P, int N){
// P eh o valor a ser procurado
    for(int i = 0; i < N; i++){
        if(vetor[i] == P){
            printf("SIM\n"); //se achou o P no vetor
            return 1;
        }
    }
    //caso nao achou
    printf("NAO\n");
    return 0;
}
int busca_interativa(v,P,N){
    printf("Vc esta em busca interativa\n");
    return 0;
}
int busca_recursiva(v,P,N){
    printf("Vc sta em busca recursiva\n");
    return 0;
}


int main(){
    int Q; //comando
    int N; //qtd de elementos do vetor
    int *v; //vetor
    int P; //valor a ser procurado nas buscas

    scanf("%d", &N);                // quantidade de elementos do vetor
    v = malloc(sizeof(int)*N);  //cria o vetor
    for(int i = 0; i < N; i++){     //aloca os elementos no vetor
        scanf("%d", &v[i]);
    }
    if(v == NULL){
        return 0;
    }

    scanf("%d", &Q);                //Comando a ser realizado

    while(Q != 5){
        if(Q == 1){                     //Inversao da ordem
            inversao(v, N);
        }else if(Q == 2){               //Busca sequencial
            scanf("%d", &P);            //Valor a ser buscado
            busca_sequencial(v, P, N);
        }else if(Q == 3 ){              //Buca binaria Interativa
            scanf("%d", &P);            //Valor a ser buscado
            busca_interativa(v, P, N);
        }else if(Q == 4){               //Busca binaria Recursiva
            scanf("%d", &P);            //Valor a ser buscado
            busca_recursiva(v, P, N);
        }
        scanf("%d", &Q);
    }
    return 0;
}
