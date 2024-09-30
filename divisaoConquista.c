#include <stdio.h>
#include <float.h>
#include <math.h>

//Estrutura de dados
typedef struct{
    
    int x, y;

}Ponto;

//Função auxiliar para calcular a distância entre dois pontos
double distancia(Ponto p1, Ponto p2){
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

//Função para ordenar pontos pelo eixo x
int comparaX(const void * a, const void * b){
    Ponto *p1 = (Ponto *)a, *p2 = (Ponto *)b;
    return (p1->x - p2->x);
}

//Função para ordenar pontos pelo eixo y
int comparaY(const void *a, const void *b){
    Ponto *p1 = (Ponto *)a, *p2 = (Ponto *)b;
    return (p1->y - p2->y);
}

double menorDistanciaNaFaixa(Ponto faixa[], int tamanho, double d){
    double menor = d;

    qsort(faixa, tamanho, sizeof(Ponto), comparaY); //Ordenar o eixo y

        for(int i = 0; i < tamanho; i++){
            for(int j = i  + 1; j < tamanho && (faixa[j].y - faixa[i].y) < menor; j++){
             if(distancia(faixa[i], faixa[j]) < menor)
                menor = distancia(faixa[i], faixa[j]);
            }

        }
        return menor;
}

//Função principal de Divisão e Conquista
double closestUtil(Ponto P[],  int n){
    if(n <= 3){
        double min = FLT_MAX;
        for(int i = 0; i < n; i++){
            for(int j = i +1; j < n; j++){
                if(distancia(P[i], P[j]) < min) min = distancia(P[i], P[j]);

            }   
        }    
        return min;
    }

    int meio = n / 2;
    Ponto pontoMedio = P[meio];

    double distEsquerda = closestUtil(P, meio);
    double distDireita = closestUtil(P + meio, n - meio);

    double d = fmin(distEsquerda, distDireita);

    Ponto faixa[n];
    int j = 0;
    for(int i = 0; i < n; i++){
        if(abs(P[i].x - pontoMedio.x) < d){
            faixa[j] = P[i];
            j++;
        }
        return fmin(d, menorDistanciaNaFaixa(faixa, j, d));
    }

}

//Função principal para encotrar a menor distância
double closest(Ponto P[], int n){
    qsort(P, n, sizeof(Ponto), comparaX);

    return closestUtil(P, n);
}


// Teste do algoritmo
int main(){
    Ponto P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(P) / sizeof(P[0]);

    printf("A menor distancia eh %f\n", closest(P, n));

    return 0;
}