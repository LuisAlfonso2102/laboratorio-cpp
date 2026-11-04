/*====================================================
    =   Programa: Ejemplo79.cpp
    =   Fecha: 9 de octubre de 2026
    =   Autor: Luis Alfonso Reyes
    =   Asignaruta: DIA044-Programacion Basica
    =   No. de cuenta: 20192002012
    =  Al programa del numeral 78 agregar lo siguiente:
    =  Función espar(float) que, retornando un booleano, determina si el valor recibido es par.
    =  Usando la función espar() contar los números pares e impares de la salida final (los cinco mostrados en la tabla)
    =  Después de la tabla aparezcan total de pares, total de impares y total de haber sumado los valores, los cuadrados y los cubos.
    =  Total de valores, total de cuadrados, total de cubos, total de pares e impares no son variables diferentes, 
    =  todas son partes del vector TOTALES.
  =====================================================*/
#include <iostream>
#include <clocale> 

using namespace std;

// Función espar(float): Retorna true si el valor recibido es par, y false si es impar

bool espar(float valor)
{
    long entero = (long)valor; // Convertimos a entero para usar operador %
    return (entero % 2 == 0);
}

int main()
{
    setlocale(LC_ALL, "es_ES.UTF-8");

    double TOTALES[6] = {0, 0, 0, 0, 0, 0};

    // Simulamos los valores de la tabla (ejemplo con los 5 valores requeridos)
    float valoresTabla[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    int cantidadValores = 5;

    cout << "          TABLA DE VALORES, CUADRADOS Y CUBOS           " << endl;

    cout << "Valor\t\tCuadrado\tCubo" << endl;

    for (int i = 0; i < cantidadValores; i++)
    {
        float val = valoresTabla[i];
        float cuadrado = val * val;
        float cubo = val * val * val;


        cout << val << "\t\t" << cuadrado << "\t\t" << cubo << endl;

        if (espar(val)) {
            TOTALES[4]++; 
        } else {
            TOTALES[5]++;
        }

        TOTALES[0]++;   
        TOTALES[1] += val;    
        TOTALES[2] += cuadrado; 
        TOTALES[3] += cubo;     
    }

    cout << "               RESUMEN ESTADÍSTICO (TOTALES)            " << endl;

    cout << " - Total de valores procesados: " << TOTALES[0] << endl;
    cout << " - Suma total de los valores:   " << TOTALES[1] << endl;
    cout << " - Suma total de cuadrados:     " << TOTALES[2] << endl;
    cout << " - Suma total de cubos:         " << TOTALES[3] << endl;
    cout << " - Total de números pares:      " << TOTALES[4] << endl;
    cout << " - Total de números impares:    " << TOTALES[5] << endl;

    return 0;
}