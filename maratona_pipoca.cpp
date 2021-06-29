//Questão da Maratona de Programação 2019
//https://www.urionlinejudge.com.br/judge/pt/problems/view/2973

#include <stdio.h>
int N, C, T, somaPipocas =0;
int p[100000];
int validar(int chute){
    int pipocas = T*chute;
    int soma =0;
    int comedores = C;
    int aux = 0;
    while(aux<N){
        if(comedores ==0)
            return 0;
        if(soma + p[aux] <= pipocas){
            soma += p[aux];
            aux++;
        }else{
            soma = 0;
            comedores--;
        }

    }
    return 1;
}


int main(){
    scanf("%d %d %d", &N, &C, &T);
    for(int i=0; i<N; i++){
        scanf("%d", &p[i]);
        somaPipocas += p[i];
    }
    int l = 1;
    int r = (somaPipocas/T);
    int mid, ant, atual;
    ant = 1;
    while(r>=l){
        mid = (l + r)/2;
        if(validar(mid)==1){
            r = mid - 1;
            ant = 1;
        }else{
            l = mid + 1;
            ant = 0;
        }
    }
    if(ant==0)
        mid = mid +1;

    printf("%d\n", mid);

    return 0;
}