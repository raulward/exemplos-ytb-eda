#include <stdio.h>
#define TAM 10

void change(int* a, int* b);
void print(int* vet, int size);


int main() {

    int vet1[] = {4, 5, 7, 2, 10, 11, 23, 1, 16, 13};

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM - i; j++) {
            if (vet1[j] > vet1[j + 1]) {
                change(&vet1[j], &vet1[j+1]);
            }
        }
    }

    print(vet1, 10);

    return 0;
}

void change(int* a, int* b) {
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void print(int* vet, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");
}