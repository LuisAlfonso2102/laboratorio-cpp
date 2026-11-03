/*====================================================
    =   Programa: Ejemplo47.cpp
    =   Fecha: 5 de octubre de 2026
    =   Autor: Luis Alfonso Reyes
    =   Asignaruta: DIA044-Programacion Basica
    =   No. de cuenta: 20192002012
    =   Usando la función getline con las librerías string e iostream haga un programa que pida al usuario cinco nombres
    =  (formados por primer nombre y primer apellido) y los imprima en pantalla alineados a la izquierda.
  =====================================================*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Declaración de un arreglo de tipo string (indicando que voy a guardar aqui las cadenas de texto) para almacenar los 5 nombres.pag483
    string nombres[5];

    cout << "Por favor ingrese 5 nombres y 5 apellidos:\n";

    // Ciclo para pedir los 5 nombres utilizando getline. 
    for (int i = 0; i < 5; i++)//el contador inicia con 0 y aplique la condicion, asi mismo va incrementando su valor con ++.
    {
        cout << "Ingrese el nombre: " << (i + 1) << " (Primer nombre y apellido): ";//i+1=es el conteo de las personas que esta ingresando.
        
        // getline se usa para capturar cadenas de texto completas que incluyen espacios en blanco
        getline(cin, nombres[i]);// al poner la variable i dentro de corchetes quiere decir que alli guardaran el numeros de los nombres 
    }

    cout << "\nEstos son los nombres ingresados alineados a la izquierda\n";

    // Ciclo para mostrar los nombres almacenados en pantalla
    for (int i = 0; i < 5; i++)
    {
        cout << "Nombre " << (i + 1) << ": " << nombres[i] << endl;
    }

    cout << "\nPrograma finalizado.\n";

    return 0;
}