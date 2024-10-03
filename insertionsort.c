#include <stdio.h>
#define TAM 10

void change(int* a, int* b);
void print(int* vet, int size);


int main() {

    int vet1[] = {4, 5, 7, 2, 10, 11, 23, 1, 16, 13};

    for (int i = 0; i < TAM - 1; i++) {
        if (vet1[i] > vet1[i + 1]) {
            for (int j = i - 1; j >= 0; j--) {
                if (vet1[i + 1] < vet1[j]) {
                    change(&vet1[i], &vet1[j]);
                }
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