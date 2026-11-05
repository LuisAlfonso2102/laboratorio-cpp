/*====================================================
    =   Programa: Ejemplo86.cpp
    =   Fecha: 27 de octubre de 2026
    =   Autor: Luis Alfonso Reyes
    =   Asignaruta: DIA044-Programacion Basica
    =   No. de cuenta: 20192002012
    =  Una matriz tiene un valle si el valor de una de sus celdas es menor que el de cualquiera de sus 8 celdas vecinas.
    =  Haga un programa que lea una matriz (el usuario te indicará de cuántas filas y columnas) y nos diga si la matriz tiene un valle o no.
    =  En caso afirmativo, nos mostrará en pantalla las coordenadas de todos los valles, sus valores y el de sus celdas vecinas. 
    =  La matriz debe tener un número de filas y columnas mayor o igual que 3 y menor o igual que 10. 
    =  Las casillas que no tienen 8 vecinos no se consideran candidatas a ser valle (pues no tienen 8 vecinos). Aquí un ejemplo de la salida
    =  esperada para esta matriz de 4 × 5.
    =  En 955,945,876 el valle es 4 y, en 329,618,638 el valle es 1; note que al usuario se le  indican las celdas numeradas desde 1 y no desde 0.
  =====================================================*/
#include <iostream>
using namespace std;

int main() {
    int filas, columnas;

    // aqui esta la para asegurar que el número de filas esté entre 3 y 10, tal como pide el ejercicio
    do {
        cout << "Ingrese el numero de filas (3 a 10): ";
        cin >> filas;
    } while (filas < 3 || filas > 10);

    do {
        cout << "Ingrese el numero de columnas (3 a 10): ";
        cin >> columnas;
    } while (columnas < 3 || columnas > 10);

    //matriz estática de tamaño máximo 10x10 para almacenar los datos
    int matriz[10][10];

    // Ciclos anidados para permitir que el usuario ingrese los valores de la matriz
    cout << endl << "Ingrese los elementos de la matriz:" << endl;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            // muestro la posición al usuario en base 1 sumando 1 a los índices
            cout << "Elemento [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matriz[i][j];
        }
    }

    // Bandera lógica (flag) para saber si se encontró al menos un valle en toda la matriz
    bool hayValle = false; 

    // empiezo en 1 y terminamos en (filas - 1) y (columnas - 1) respectivamente. 
    // Esto es fundamental porque las celdas de las orillas (bordes) no tienen 8 vecinos circundantes.
    for (int i = 1; i < filas - 1; ++i) {
        for (int j = 1; j < columnas - 1; ++j) {
            int centro = matriz[i][j]; // Celda candidata a ser valle

            // CONDICIÓN DE VALLE: La celda evaluada debe ser estrictamente menor
            // que cada una de sus 8 posiciones vecinas alrededor.
            if (centro < matriz[i - 1][j - 1] && centro < matriz[i - 1][j] && centro < matriz[i - 1][j + 1] &&
                centro < matriz[i][j - 1]                                 && centro < matriz[i][j + 1]     &&
                centro < matriz[+ 1][j - 1] && centro < matriz[i + 1][j] && centro < matriz[i + 1][j + 1]) {

                hayValle = true; // Se encontró un valle exitosamente

                // Imprimimos la coordenada del valle sumando 1 para mostrarla en base 1 al usuario
                cout << endl << "Valle en fila " << i + 1 << " columna " << j + 1 << ":" << endl;

                // Mostramos en formato tabular la submatriz de 3x3 compuesta por el valle y sus 8 vecinos
                cout << matriz[i - 1][j - 1] << " " << matriz[i - 1][j] << " " << matriz[i - 1][j + 1] << endl;
                cout << matriz[i][j - 1]     << " " << matriz[i][j]     << " " << matriz[i][j + 1]     << endl;
                cout << matriz[i + 1][j - 1] << " " << matriz[i + 1][j] << " " << matriz[i + 1][j + 1] << endl;
            }
        }
    }

    // 
    if (!hayValle) {
        cout << endl << "La matriz no tiene ningún valle." << endl;
    }

    return 0;