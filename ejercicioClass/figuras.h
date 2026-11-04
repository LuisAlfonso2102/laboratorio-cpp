/*====================================================
    =   Programa: Ejemplo75.cpp
    =   Fecha: 23 de octubre de 2026
    =   Autor: Luis Alfonso Reyes
    =   Asignaruta: DIA044-Programacion Basica
    =   No. de cuenta: 20192002012
    =  Cree una librería que imprima diversos tipos de cuadrados:
    =  Cuadrado solo con el borde y vacío por dentro.
    =  Cuadrado lleno.
    =  Cuadrado solo la mitad lleno.
    =  Rectángulo vacío.
    =  Rectángulo lleno.
    =  Triángulo (como sea)
    = Y ahora haga un programa que pregunte al usuario qué desea dibujar y con qué carácter y lo presente en pantalla
    = (el usuario debe poder ingresar la longitud de los lados de los cuadrados y la altura del triángulo).

  =====================================================*/
#ifndef FIGURAS_H
#define FIGURAS_H

#include <iostream>
using namespace std;

//al ser libreria no se usa el main.
void cuadradoVacio(int lado, char caracter) {
    for (int i = 1; i <= lado; i++) {
        for (int j = 1; j <= lado; j++) {
            if (i == 1 || i == lado || j == 1 || j == lado) {
                cout << caracter << " ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

void cuadradoLleno(int lado, char caracter) {
    for (int i = 1; i <= lado; i++) {
        for (int j = 1; j <= lado; j++) {
            cout << caracter << " ";
        }
        cout << endl;
    }
}

void cuadradoMitad(int lado, char caracter) {
    for (int i = 1; i <= lado; i++) {
        for (int j = 1; j <= lado; j++) {
            if (i <= lado / 2) {
                cout << caracter << " ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

void rectanguloVacio(int largo, int corto, char caracter) {
    for (int i = 1; i <= corto; i++) {
        for (int j = 1; j <= largo; j++) {
            if (i == 1 || i == corto || j == 1 || j == largo) {
                cout << caracter << " ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

void rectanguloLleno(int largo, int corto, char caracter) {
    for (int i = 1; i <= corto; i++) {
        for (int j = 1; j <= largo; j++) {
            cout << caracter << " ";
        }
        cout << endl;
    }
}

void triangulo(int altura, char caracter) {
    for (int i = 1; i <= altura; i++) {
        for (int j = 1; j <= i; j++) {
            cout << caracter << " ";
        }
        cout << endl;
    }
}

bool validarRectangulo(int largo, int corto) {
    return (largo > corto && largo % 2 == 0 && largo / 2 == corto);
}

void leerEnteroPositivo(const char mensaje[], int &valor) {
    do {
        cout << mensaje;
        cin >> valor;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            valor = 0;
        }

        if (valor <= 0) {
            cout << "Error: Ingrese un numero entero positivo." << endl;
        }

    } while (valor <= 0);
}

#endif
