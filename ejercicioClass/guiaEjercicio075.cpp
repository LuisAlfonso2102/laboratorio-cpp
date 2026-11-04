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
#include <iostream>
#include "figuras.h" // Incluimos tu librería propia

using namespace std; // Agregado para evitar el uso de std::

int main()
{
    int opcion, lado, largo, corto, altura;
    char caracter, continuar;

    do
    {
        cout << "LIBRERIA DE FIGURAS" << endl;
        cout << "1. Cuadrado vacio" << endl;
        cout << "2. Cuadrado lleno" << endl;
        cout << "3. Cuadrado a la mitad" << endl;
        cout << "4. Rectangulo vacio" << endl;
        cout << "5. Rectangulo lleno" << endl;
        cout << "6. Triangulo" << endl;

        do
        {
            leerEnteroPositivo("Seleccione una figura (1-6): ", opcion);

            if (opcion < 1 || opcion > 6)
            {
                cout << "Error: Seleccione una opcion del 1 al 6." << endl;
            }

        } while (opcion < 1 || opcion > 6);

        cout << endl << "Ingrese el caracter para dibujar: ";
        cin >> caracter;

        switch (opcion)
        {
            case 1:
                leerEnteroPositivo("Ingrese el lado del cuadrado: ", lado);
                cout << endl << "CUADRADO VACIO" << endl;
                cuadradoVacio(lado, caracter);
                break;

            case 2:
                leerEnteroPositivo("Ingrese el lado del cuadrado: ", lado);
                cout << endl << "CUADRADO LLENO" << endl;
                cuadradoLleno(lado, caracter);
                break;

            case 3:
                leerEnteroPositivo("Ingrese el lado del cuadrado: ", lado);
                cout << endl << "CUADRADO A LA MITAD" << endl;
                cuadradoMitad(lado, caracter);
                break;

            case 4:
                leerEnteroPositivo("Ingrese el lado mas corto: ", corto);
                do
                {
                    leerEnteroPositivo("Ingrese el lado mas largo: ", largo);
                    if (!validarRectangulo(largo, corto))
                    {
                        cout << "Error: El lado largo debe ser el doble del lado corto." << endl;
                    }
                } while (!validarRectangulo(largo, corto));

                cout << endl << "RECTANGULO VACIO" << endl;
                rectanguloVacio(largo, corto, caracter);
                break;

            case 5:
                leerEnteroPositivo("Ingrese el lado mas corto: ", corto);
                do
                {
                    leerEnteroPositivo("Ingrese el lado mas largo: ", largo);
                    if (!validarRectangulo(largo, corto))
                    {
                        cout << "Error: El lado largo debe ser el doble del lado corto." << endl;
                    }
                } while (!validarRectangulo(largo, corto));

                cout << endl << "RECTANGULO LLENO" << endl;
                rectanguloLleno(largo, corto, caracter);
                break;

            case 6:
                leerEnteroPositivo("Ingrese la altura del triangulo: ", altura);
                cout << endl << "TRIANGULO" << endl;
                triangulo(altura, caracter);
                break;
        }

        cout << endl << "Desea dibujar otra figura? (S/N): ";
        cin >> continuar;

        while (continuar != 'S' && continuar != 's' &&
               continuar != 'N' && continuar != 'n')
        {
            cout << "Ingrese S para continuar o N para salir: ";
            cin >> continuar;
        }

    } while (continuar == 'S' || continuar == 's');

    cout << endl << "Gracias por utilizar el programa." << endl;

    return 0;
}