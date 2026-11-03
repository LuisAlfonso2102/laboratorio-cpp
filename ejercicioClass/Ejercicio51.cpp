/*====================================================
    =   Programa: Ejemplo47.cpp
    =   Fecha: 5 de octubre de 2026
    =   Autor: Luis Alfonso Reyes
    =   Asignaruta: DIA044-Programacion Basica
    =   No. de cuenta: 20192002012
    =  Escriba una función que muestre en el margen izquierdo de la pantalla un cuadrado relleno de asteriscos,
    =  cuyo lado se especiﬁ que en el parámetro entero lado. Por ejemplo, si lado es 4, el método debe mostrar lo
    =  siguiente (Ejercicio 3.2, libro 1):
  =====================================================*/
#include <iostream>
#include <clocale>
using namespace std;

// Función que dibuja el cuadrado relleno de asteriscos que me da en la imagen del problema.
void mostrarCuadrado(int lado)//variable tipo retorno, realiza la tarea no regresa ningun valor, en este caso la utilizare para los asteriscos.pag71
{
    // el ciclo externo que controla las filas (hacia abajo)
    for (int i = 0; i < lado; ++i)
    {
        // el ciclo interno que controla las columnas (hacia la derecha)
        for (int j = 0; j < lado; ++j)// este es un ciclo anidado y utilizo la j por que es la siguiente letra de la i.
        {
            cout << "*";
        }
       
        cout << "\n";//sin este espacio todos los asteriscos de todas las filas del cuadrado se imprimirían pegados en una sola línea larguísima horizontal.
    }
}
//Puse la declaración de la función previa a main() para evitar errores de compilación lineal.Asi el compilador ya conoce los parametros y estructura.
int main()
{
    setlocale(LC_ALL, "es_ES.UTF-8");//Ñ
    int lado = 0;

    cout << "Por favor escriba en numeros el tamaño del lado del cuadrado: ";
    cin >> lado;

    cout << "\nEste es un cuadrado de" << lado << "x" << lado << "\n";// en esta parte pongo el numero que el usuario digito en cada lado
    
    // Aqui estoy llamando a la funcio
    mostrarCuadrado(lado);

    return 0;
}