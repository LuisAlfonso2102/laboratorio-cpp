/*====================================================
    =   Programa: Ejemplo86.cpp
    =   Fecha: 27 de octubre de 2026
    =   Autor: Luis Alfonso Reyes
    =   Asignaruta: DIA044-Programacion Basica
    =   No. de cuenta: 20192002012
    =   El ordenamiento de burbuja descrito en el ejercicio 7.11 es ineﬁciente para grandes arreglos.
    =   Realice las siguientes modiﬁcaciones simples para mejorar el rendimiento del ordenamiento de burbuja  (Ejercicio 7.12, libro 1): 
    =   Después de la primera pasada, se garantiza que el número más grande estará en el elemento con la numeración más alta del arreglo;
    =   después de la segunda pasada, los dos números más altos estarán “acomodados”, y así en lo sucesivo. En lugar de realizar nueve
    =   comparaciones en cada pasada, modiﬁ que el ordenamiento de burbuja para que realice ocho comparaciones en la segunda pasada,
    =   siete en la tercera, y así en lo sucesivo. Los datos en el arreglo tal vez se encuentren ya en el orden apropiado, o casi apropiado,
    =   así que ¿para qué realizar nueve pasadas, si basta con menos?.Modiﬁque el ordenamiento para comprobar al ﬁ nal de cada pasada si se han
    =   realizado intercambios. Si no se ha realizado ninguno, los datos ya deben estar en el orden apropiado, por lo que el programa debe terminar.
    =   Si se han realizado intercambios, por lo menos se necesita una pasada más.Para probarlo crear un vector de 50 posiciones que se llene de 
    =   maner aleatoria obviamente mostrar el vector antes y después de aplicar el ordenamiento.
  =====================================================*/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    const int TAM = 50;
    int arreglo[TAM];

    srand(time(0));

    // Llenar el arreglo con 50 números aleatorios entre 1 y 100
    for (int i = 0; i < TAM; i++) {
        arreglo[i] = 1 + rand() % 100;
    }

    // Mostrar el arreglo antes de ordenarlo
    cout << "ARREGLO ORIGINAL (DESORDENADO)" << endl;
    for (int i = 0; i < TAM; i++) {
        cout << arreglo[i] << " ";
        // Salto de línea cada 10 elementos para que la consola se vea ordenada
        if ((i + 1) % 10 == 0) {
            cout << endl;
        }
    }
    cout << endl;

    
    int pasada = 0;
    bool huboIntercambio;

    do {
        huboIntercambio = false;

        // Optimización a: Reducir comparaciones en cada pasada (TAM - 1 - pasada)
        // Ya que en cada pasada el elemento más grande se posiciona al final.
        for (int j = 0; j < TAM - 1 - pasada; j++) {
            if (arreglo[j] > arreglo[j + 1]) {
                // Intercambio de valores
                int temp = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = temp;

                huboIntercambio = true;
            }
        }
        pasada++;

    } while (huboIntercambio && pasada < TAM); 
    // El ciclo se repite solo si hubo intercambios, terminando antes si ya está ordenado.

  
    cout << endl << "El arreglo se ordeno despues de " << pasada << " pasadas gracias a las optimizaciones." << endl << endl;


    cout << "ARREGLO ORDENADO" << endl;
    for (int i = 0; i < TAM; i++) {
        cout << arreglo[i] << " ";
        if ((i + 1) % 10 == 0) {
            cout << endl;
        }
    }
    cout << endl;

    return 0;
}