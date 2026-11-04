/*====================================================
    =   Programa: Ejemplo31.cpp
    =   Fecha: 9 de octubre de 2026
    =   Autor: Luis Alfonso Reyes
    =   Asignaruta: DIA044-Programacion Basica
    =   No. de cuenta: 20192002012
    =   Modifi que el programa que escribió en el ejercicio 5.23, para que lea un número impar en el rango de 1 a 19, de manera
    =   que especifi que el número de fi las en el rombo, y después muestre un rombo del tamaño apropiado.

  =====================================================*/
#include <iostream>
using namespace std;

int main()
{
    int filas;

    // Validación de entrada: debe ser impar y estar entre 1 y 19
    do
    {
        cout << "Ingrese el numero de filas para el rombo (impar entre 1 y 19): ";
        cin >> filas;

        if (filas < 1 || filas > 19 || filas % 2 == 0)//aqui puse el operador logico OR para ver si una de las opciones cumple.
        {
            cout << "Entrada invalida. Debe ser un numero impar en el rango de 1 a 19.\n\n";
        }
    } while (filas < 1 || filas > 19 || filas % 2 == 0);

    int puntoMedio = (filas + 1) / 2;
    int espacios;
    int asteriscos;

    for (int fila = 1; fila <= filas; fila++)
    {
        if (fila <= puntoMedio)
        {
            espacios = puntoMedio - fila;
            asteriscos = 2 * fila - 1;
        }
        else
        {
            espacios = fila - puntoMedio;
            asteriscos = 2 * (filas - fila) + 1;
        }

        for (int i = 1; i <= espacios; i++)
        {
            cout << " ";
        }

        for (int i = 1; i <= asteriscos; i++)
        {
            cout << "*";
        }

        cout << endl;
    }

    return 0;
}