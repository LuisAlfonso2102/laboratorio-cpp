/*====================================================
    =   Programa: Ejemplo45.cpp
    =   Fecha: 5 de octubre de 2026
    =   Autor: Luis Alfonso Reyes
    =   Asignaruta: DIA044-Programacion Basica
    =   No. de cuenta: 20192002012
    =   Haciendo uso de las librerías stdlib y time vamos a hacer un programa que sirva para imprimir unas cuantas líneas de la siguiente manera:
    =   a.Pedir al usuario el ingreso de un número entero “X” que oscile entre cinco (5) y veinte (20) incluyéndolos.
    =   b.Pedir al usuario el ingreso de un carácter “Y”.
    =   c.Haciendo uso de una función imprimir línea se imprimirán X líneas donde cada una de ellas deberá imprimir separado por un espacio en blanco
    =   tantos caracteres Y como arroje la función rand (que oscilará entre los primeros quince números positivos) usando como semilla de srand time(NULL).
    =   Se deben contar la cantidad total de caracteres impresos porque después se imprimirá de nuevo X cantidad de líneas pero la cantidad
    =   de Y caracteres de cada línea no dependerá de time(NULL) sino del número total de caracteres que se contaron de la primera salida.
    =   Las X líneas se imprimen con una función que recibe el número X y los caracteres de cada línea se imprimen con una función que recibe
    =   el carácter que ingresó el usuario seguido del número de veces que debe escribirlo en esa línea. 
  =====================================================*/
#include <iostream>
#include <iomanip>//esta biblioteca siver para usar setw() este herramientas para manipuladores de flujo parametrizados . pag.134
#include <cstdlib>//este lo utilizo para funciones relacionadas con operaciones generales del programa.pag214
#include <ctime>//este Contiene prototipos de función y tipos para manipular la hora y la fecha.pag214

using namespace std;

// variables para el prototipo de funciones
int imprimirLinea(char Y, int cantidad);//char esta almacenando el simbolo.pag41
int imprimirLineas(int X, char Y);//X=representa el numero entero entre 5y20. y=representa el caracter que usara el usuario

int main()
{
    //
 
    int X, totalCaracteres;//este guarda el total de caracteres que se imprime
    char Y, continuar;//esta variable es para si desea continuar, el usuario puede precionar S o N

    do
    {
        // Validando el numero X
        do
        {
            cout << "\nIngrese un numero entero entre 5 y 20: ";
            cin >> X;

            if (cin.fail())//Si el usuario comete el error de poner un simbolo o letra que no sea numero entero
            {
                cin.clear();// restablece el estado de CIN quita el estado error
                cin.ignore(10000, '\n');//descarta letras incorrectas que el usuario escribio
                X = 0;
                cout << "Error. Debe ingresar un numero entero.\n";
            }
            else if (X < 5 || X > 20)//si el usuario ingresa numero diferente de entre 5-20. ||=O
            {
                cout << "Error. El numero debe estar entre 5 y 20.\n";
            }

        } while (X < 5 || X > 20);

        // solicitando el caracter Y
        cout << "Ingrese el caracter Y: ";
        cin >> Y;

        // primera salida
        srand(time(NULL));//hora actual del sistema en segundos.pag214

        cout << "\nPRIMERA SALIDA\n";

        totalCaracteres = imprimirLineas(X, Y);

        cout << "\nTotal de caracteres impresos: "
             << totalCaracteres << endl;

        // segunda salida
        srand(totalCaracteres);

        cout << "\nSEGUNDA SALIDA\n";

        imprimirLineas(X, Y);

        // ciclo para saber si el usuario desea continuar
        do
        {
            cout << "\nDesea ejecutar nuevamente? (S/N): ";
            cin >> continuar;

            if (continuar != 'S' && continuar != 's' &&//este es operador logico AND
                continuar != 'N' && continuar != 'n')
            {
                cout << "Error. Ingrese S o N.\n";
            }

        } while (continuar != 'S' && continuar != 's' &&
                 continuar != 'N' && continuar != 'n');

    } while (continuar == 'S' || continuar == 's');

    cout << "\nPrograma finalizado.\n";

    return 0;
}

// Esta es la funcion para imprimir la linea Y
int imprimirLinea(char Y, int cantidad)
{
    for (int i = 1; i <= cantidad; i++)
    {
        cout << Y << " ";
    }

    return cantidad;
}

// Esta es la funcion para imprimir la linea Y
int imprimirLineas(int X, char Y)
{
    int cantidad, total = 0;

    for (int i = 1; i <= X; i++)
    {
        cantidad = rand() % 15 + 1;

        cout << "Linea " << setw(2) << i << ": ";

        total = total + imprimirLinea(Y, cantidad);

        cout << endl;
    }

    return total;
}