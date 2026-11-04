/*====================================================
    =   Programa: Ejemplo58.cpp
    =   Fecha: 11 de octubre de 2026
    =   Autor: Luis Alfonso Reyes
    =   Asignaruta: DIA044-Programacion Basica
    =   No. de cuenta: 20192002012
    =  Escriba un programa que simule el lanzamiento de monedas. Cada vez que se lance la moneda, el programa debe imprimir Cara o Cruz.
    =  Deje que el programa lance la moneda 100 veces y cuente el número de veces que aparezca cada uno de los lados de la moneda.
    =  Imprima los resultados. El programa debe llamar a un método separado, llamado tirar, que no reciba argumentos y devuelva 0 
    =  en caso de cara y 1 en caso de cruz. [Nota: si el programa simula en forma realista el lanzamiento de monedas,
    =  cada lado de la moneda debe aparecer aproximadamente la mitad del tiempo]. (Ejercicio 6.34, libro 1)
  =====================================================*/

  #include <iostream>
#include <cstdlib>  // esto es para rand() y srand()
#include <ctime>    // Necesario para time() que sea de forma aleatorea
#include <clocale>  //(tildes y ñ)

using namespace std;

// Función tirar que simula el lanzamiento de una moneda.
// Retorna un int: 0 para cara, 1 para cruz.
// No recibe ningún argumento por dentro.
int tirar()
{
    // rand() % 2 genera un número aleatorio que puede ser 0 o 1.
    // 0 va hacer cara y 1 cruz.
    return rand() % 2;
}

int main()
{
    setlocale(LC_ALL, "es_ES.UTF-8");

    // Inicializar la semilla aleatoria para que los resultados cambien en cada ejecución
    srand(time(0)); 

    int contadorCaras = 0;
    int contadorCruces = 0;

    cout << "Simulando el lanzamiento de una Moneda 100 veces\n";

    // Ciclo para lanzar la moneda 100 veces
    for (int i = 0; i < 100; ++i)
    {
        // Llamamos a la función tirar() y guardamos su resultado (0 o 1)
        int resultado = tirar();

        if (resultado == 0)
        {
            cout << "Lanzamiento " << (i + 1) << ": Cara\n";
            contadorCaras++;  // Sumamos uno al contador de caras
        }
        else
        {
            cout << "Lanzamiento " << (i + 1) << ": Cruz\n";
            contadorCruces++; // Sumamos uno al contador de cruces
        }
    }
  
    cout << "Estos son los resultados despues de lanzar la moneda 100 veces"<<endl;
   
    cout << "Total de veces que salió CARA: " << contadorCaras <<endl;
    cout << "Total de veces que salió CRUZ: " << contadorCruces <<endl;

    return 0;
}