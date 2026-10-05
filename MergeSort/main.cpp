/*
    Descripcion: Implementacion del algoritmo MergeSort utilizando la tecnica 
    de Divide y Venceras para ordenar un arreglo de numeros reales de mayor a menor.
    Autor: Lucca Traslosheros Abascal A01713944
    Fecha de creacion: 19/08/2026
*/

#include <iostream>
#include <vector>

/*
    Proposito: Juntar dos subarreglos ordenados en uno solo de mayor a menor.
    Parametros: 
        - arreglo: Referencia al vector original de numeros reales.
        - inicio: Indice inicial del subarreglo.
        - medio: Indice medio que divide los subarreglos.
        - final: Indice final del subarreglo.
    Retorno: Ninguno (void).
    Complejidad: O(n) donde n es la cantidad de elementos a juntar.
*/
void merge(std::vector<double> &arreglo, int inicio, int medio, int final) {
    int tamanoIzquierda = medio - inicio + 1;
    int tamanoDerecha = final - medio;

    std::vector<double> subarregloIzquierdo(tamanoIzquierda);
    std::vector<double> subarregloDerecho(tamanoDerecha);

    for (int i = 0; i < tamanoIzquierda; i++) {
        subarregloIzquierdo[i] = arreglo[i + inicio];
    }
    
    for (int j = 0; j < tamanoDerecha; j++) {
        subarregloDerecho[j] = arreglo[j + medio + 1];
    }

    int indiceIzquierdo = 0;
    int indiceDerecho = 0;
    int indiceArreglo = inicio;

    while (indiceIzquierdo < tamanoIzquierda && indiceDerecho < tamanoDerecha) {
        if (subarregloIzquierdo[indiceIzquierdo] >= subarregloDerecho[indiceDerecho]) {
            arreglo[indiceArreglo] = subarregloIzquierdo[indiceIzquierdo];
            indiceIzquierdo++;
        } else {
            arreglo[indiceArreglo] = subarregloDerecho[indiceDerecho];
            indiceDerecho++;
        }
        indiceArreglo++;
    }

    while (indiceIzquierdo < tamanoIzquierda) {
        arreglo[indiceArreglo] = subarregloIzquierdo[indiceIzquierdo];
        indiceArreglo++;
        indiceIzquierdo++;
    }

    while (indiceDerecho < tamanoDerecha) {
        arreglo[indiceArreglo] = subarregloDerecho[indiceDerecho];
        indiceArreglo++;
        indiceDerecho++;
    }
}

/*
    Proposito: Dividir recursivamente el arreglo para ordenarlo de mayor a menor.
    Parametros:
        - arreglo: Referencia al vector de numeros reales a ordenar.
        - inicio: Indice donde comienza la particion a ordenar.
        - final: Indice donde termina la particion a ordenar.
    Retorno: Ninguno (void).
    Complejidad: O(n log n) en el peor de los casos y en caso promedio.
*/
void mergeSort(std::vector<double> &arreglo, int inicio, int final) {
    if (inicio < final) {
        int medio = inicio + (final - inicio) / 2;
        
        mergeSort(arreglo, inicio, medio);
        mergeSort(arreglo, medio + 1, final);

        merge(arreglo, inicio, medio, final);
    }
}

/*
    Proposito: Punto de entrada del programa. Lee la cantidad de datos, 
    los almacena, llama al ordenamiento e imprime el resultado.
    Parametros: Ninguno.
    Retorno: 0 si la ejecucion fue exitosa.
    Complejidad: O(n log n) dominada por la llamada a mergeSort.
*/
int main() {
    int cantidadElementos = 0;

    if (std::cin >> cantidadElementos && cantidadElementos > 0) {
        std::vector<double> listaNumeros(cantidadElementos, 0.0);

        for (int indice = 0; indice < cantidadElementos; indice++) {
            std::cin >> listaNumeros[indice];
        }

        mergeSort(listaNumeros, 0, cantidadElementos - 1);

        for (int indice = 0; indice < cantidadElementos; indice++) {
            std::cout << listaNumeros[indice];
            if (indice < cantidadElementos - 1) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}