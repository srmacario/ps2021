#include <bits/stdc++.h>

using namespace std;


int arr[] = {2, 8, 6, 10, 4, 3, 7, 5, 9, 11}; 
int L[10000], R[100000];

void merge(int l, int r){
    //Condição de Parada: vetor de um elemento, não precisa ordenar
    if(l == r) return;
    //separando os tamanhos
    int m = (l+r)/2, n1 = m-l+1, n2 = r-m;
    //divide o problema atual em dois: lado esquerdo e lado direito
    merge(l, m), merge(m+1, r);
    //Nesse ponto, já resolveu os dois problemas anteriores, agora é necessário juntar os dois 
    //Separando em dois para visualizar: arr está ordenado de l a m
    //                                   arr está ordenado de m+1 a r
    for(int i=0;i<n1;i++) L[i] = arr[l+i];
    for(int i=0;i<n2;i++) R[i] = arr[m+1+i];
    //anda com dois ponteiros verificando quem é o menor numero atual comparando entre os dois vetores (esquerda e direita)
    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        if(L[i] <= R[j]) arr[k] = L[i], i++;
        else arr[k] = R[j], j++;
        k++;
    }
    //dependendo dos valores pode acabar esse loop sem ter passado totalmente pelo L ou totalmente pelo R
    while(i<n1) arr[k] = L[i], i++, k++;
    while(j<n2) arr[k] = R[j], j++, k++;
    //fim dessa etapa do merge
}

void print(int size) { 
    for (int i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 
  
int main() { 
    int arr_size = sizeof(arr)/sizeof(arr[0]); 
  
    printf("Array original \n"); 
    print(arr_size); 
  
    merge(0, arr_size - 1); 
  
    printf("\nArray ordenado \n"); 
    print(arr_size); 
    return 0; 
} 