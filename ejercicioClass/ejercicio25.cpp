/*====================================================
    =   Programa: Ejemplo25.cpp
    =   Fecha: 3 de octubre de 2026
    =   Autor: Luis Alfonso Reyes
    =   Asignaruta: DIA044-Programacion Basica
    =   No. de cuenta: 20192002012
    =   La función factorial se utiliza frecuentemente en los problemas de probabilidad.
    =   Utilizando la deﬁnición de factorial del ejercicio 4.35, escriba un programa que utilice una función for para 
    =   evaluar los factoriales de los enteros del 1 al 5. Muestre los resultados en formato tabular (Ejercicio 5.10 Libro 1). 
  =====================================================*/
#include <iostream>
using namespace std;

int main() {
    /*Este sera el encabezado de la tabla. Ya que el problema me pide que tabule, entonces al momento que los datos se muestren tiene que aparecer
    una tabla ordenada. Para eso utilizo la funcion (\t) este es un separador invisible que tabula horizontalmente y lo puse enmedio para que mostara
    el orden derecha a izquierda.pag39
    */
    cout << "Numero\tFactorial" << endl;
    cout << "=================" << endl;

    /* Ciclo (for) para evaluar los factoriales de los enteros del 1 al 5. El libro pide una secucencia ordenada(1,2,3,4,5). para que se pueda
    correr un numero tras otro necesito poner el contador(i) para que avance por escalon. El ++ es el mecanizmo que avanza por cada numero ya que 
    es un operador de incremento.pag140
    */
    for (int i = 1; i <= 5; i++) {
        long long factorial = 1; // Variable acumuladora, esta contiene 64 bits y almacena numero enteros muy largos.pag8
                                 //No utilice el INT porque se queda sin espacio muy rápido con las multiplicaciones sucesivas.

        // Ciclo interno para calcular el factorial de i (i!). 
        for (int contador = 1; contador <= i; contador++) {
            factorial *= contador; //el *= es un operador de asignacion compuesta multiplica el valor del factorial por el contador, asi mismo
                                   //guarda y reemplaza ese nuevo valor en la misma variable factorial.pag 142
        }

        // Mostrar el resultado en formato tabular. i imprime el resultado de la variable del ciclo externo y factorial del externo.
        cout << i << "\t" << factorial << endl;
    }

    return 0;
}