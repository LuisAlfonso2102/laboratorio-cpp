/*
    =   Programa: Ejemplo90.cpp
    =   Fecha: 27 de octubre de 2026
    =   Autor: Luis Alfonso Reyes
    =   Asignaruta: DIA044-Programacion Basica
    =   No. de cuenta: 20192002012
    =   Escriba un programa para simular el tiro de dos dados. El programa debe utilizar rand para tirar el primer dado,
    =   y de nuevo para tirar el segundo dado. Después debe calcularse la suma de los dos valores. [Nota: cada dado puede mostrar un valor
    =   entero del 1 al 6, por lo que la suma de los valores variará del 2 al 12, siendo 7 la suma más frecuente, mientras que 2 y 12 serán
    =   las sumas menos frecuentes]. En la ﬁgura 7.32 se muestran las 36 posibles combinaciones de los dos dados. Su programa debe tirar los dados
    =   36,000 veces. Utilice un arreglo unidimensional para registrar el número de veces que aparezca cada una de las posibles sumas.
    =   Imprima los resultados en formato tabular. Determine además si los totales son razonables (es decir, hay seis formas de tirar un 7,
    =   por lo que aproximadamente una sexta parte de los tiros deben ser 7)  (Ejercicio 7.17, libro 1)
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


int main() {
    
    srand(static_cast<unsigned int>(time(nullptr)));

    // Arreglo unidimensional para almacenar las frecuencias de las sumas (del 2 al 12)
    int frecuencia[13] = {0};

    const int TOTAL_LANZAMIENTOS = 36000;

    // Simular el tiro de dos dados 36,000 veces
    for (int i = 0; i < TOTAL_LANZAMIENTOS; ++i) {
        int dado1 = 1 + (rand() % 6);
        int dado2 = 1 + (rand() % 6);
        int suma = dado1 + dado2;
        
        frecuencia[suma]++;
    }

    // Imprimir los resultados en formato tabular utilizando endl
    cout << "Suma" << "\t" << "Frecuencia" << "\t" << "Porcentaje" << endl;


    for (int suma = 2; suma <= 12; ++suma) {
        double porcentaje = (static_cast<double>(frecuencia[suma]) / TOTAL_LANZAMIENTOS) * 100.0;
        cout << suma << "\t" << frecuencia[suma] << "\t\t" << porcentaje << "%" << endl;
    }

    return 0;
}