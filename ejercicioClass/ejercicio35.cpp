/*====================================================
    =   Programa: Ejemplo35.cpp
    =   Fecha: 5 de octubre de 2026
    =   Autor: Luis Alfonso Reyes
    =   Asignaruta: DIA044-Programacion Basica
    =   No. de cuenta: 20192002012
    =   UN programa que pida al usuario una altura y luego dibuje un triángulo con esa altura
  =====================================================*/
#include <iostream>

using namespace std;

int main() {
    int altura;

    cout << "Ingrese la altura del arbol: ";
    cin >> altura;

    cout << endl;//Puse un salto de separacion para que se mirara mejor visualmente

    // Ciclo externo
    for (int i = 1; i <= altura; i++) {/*la variable i es la incializacion y representa el numero actual.
        La condicion la pone <= basicamente le pone un alto al siclo.
        */
        //Ciclo interno para imprimir los espacios en blanco (centrado).altura es el tamaño y la i en la fila que llevo.
        for (int espacios = 1; espacios <= (altura - i); espacios++) {
            cout << " ";//Las Dobles comillas las pongo para evitar que el diseño se vea torcida, por que lo necesito en el centro.
        }

        //Ciclo interno para imprimir los asteriscos con la fórmula impar
        for (int asteriscos = 1; asteriscos <= (2 * i - 1); asteriscos++) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}