#include <stdio.h>
#include <stdlib.h>

void mezclar(int arreglo[], int inicio, int medio, int fin) {
    int i, j, k;
    int n1 = medio - inicio + 1;
    int n2 = fin - medio;
    int izquierda[n1], derecha[n2];
    for (i = 0; i < n1; i++)
        izquierda[i] = arreglo[inicio + i];
    for (j = 0; j < n2; j++)
        derecha[j] = arreglo[medio + 1 + j];
    i = 0;
    j = 0;
    k = inicio;
    while (i < n1 && j < n2) {
        if (izquierda[i] <= derecha[j]) {
            arreglo[k] = izquierda[i];
            i++;
        } else {
            arreglo[k] = derecha[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arreglo[k] = izquierda[i];
        i++;
        k++;
    }
    while (j < n2) {
        arreglo[k] = derecha[j];
        j++;
        k++;
    }
}

void ordenamientoPorMezcla(int arreglo[], int inicio, int fin) {
    if (inicio < fin) {
        int medio = inicio + (fin - inicio) / 2;
        ordenamientoPorMezcla(arreglo, inicio, medio);
        ordenamientoPorMezcla(arreglo, medio + 1, fin);
        mezclar(arreglo, inicio, medio, fin);
    }
}

void imprimirArreglo(int arreglo[], int tamano) {
    int i;
    for (i = 0; i < tamano; i++)
        printf("%d ", arreglo[i]);
    printf("\n");
}

int main() {
    int arreglo[] = {12, 11, 13, 5, 6, 7};
    int tamano = sizeof(arreglo) / sizeof(arreglo[0]);
    printf("Arreglo original: \n");
    imprimirArreglo(arreglo, tamano);
    ordenamientoPorMezcla(arreglo, 0, tamano - 1);
    printf("Arreglo ordenado: \n");
    imprimirArreglo(arreglo, tamano);
    return 0;
}


