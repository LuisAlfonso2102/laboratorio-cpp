/*====================================================
    =   Programa: Ejemplo86.cpp
    =   Fecha: 9 de octubre de 2026
    =   Autor: Luis Alfonso Reyes
    =   Asignaruta: DIA044-Programacion Basica
    =   No. de cuenta: 20192002012
    =  Utilice un arreglo unidimensional para resolver el siguiente problema. Una compañía paga a sus vendedores por comisión.
    =  Los vendedores reciben $200 por semana más 9% de sus ventas totales de esa semana. Por ejemplo, un vendedor que acumule 
    =  $5000 en ventas en una semana, recibirá $200 más 9% de $5000, o un total de $650. Escriba un programa (utilizando un arreglo de 20 a 50
    =  contadores) que determine cuántos vendedores recibieron salarios en cada uno de los siguientes rangos (suponga que el salario de cada 
    =  vendedor se trunca a una cantidad entera): 
$200-299 
$300-399 
$400-499 
$500-599 
$600-699 
$700-799 
$800-899
$900-999 
$1000 en adelante
    =  Haga la gráfica de cada categoría en barras horizontales. Usar iomanip para controlar ancho de columnas y cifras.
  =====================================================*/
#include <iostream>

#include <iostream>
using namespace std;

int main() {
   
    int contadores[20] = {0}; 
    int ventas;
    char continuar;

    cout << "SISTEMA DE COMISIONES DE VENDEDORES" << endl;

    do {
        cout << endl << "Ingrese las ventas totales de la semana (-1 para terminar): ";
        cin >> ventas;

        if (ventas == -1) {
            break;
        }

        if (ventas < 0) {
            cout << "Error: Las ventas no pueden ser negativas." << endl;
            continue;
        }

        // Calcular el salario: $200 + 9% de las ventas totales.
        // Al declararlo como 'int', la parte decimal se trunca automáticamente a entero.
        int salario = 200 + (ventas * 9 / 100);

        cout << "Salario calculado (truncado): $" << salario << endl;

        int indice = (salario - 200) / 100;

        // Validar límites de los rangos
        if (indice < 0) {
            indice = 0; 
        }
        if (indice > 8) {
            indice = 8; 
        }

        contadores[indice]++;

        cout << "Desea ingresar otro vendedor? (S/N): ";
        cin >> continuar;

    } while (continuar == 'S' || continuar == 's');

    cout << "     RESUMEN DE SALARIOS Y GRAFICA DE BARRAS" << endl;


    string rangos[9] = {
        "$200 - $299      ",
        "$300 - $399      ",
        "$400 - $499      ",
        "$500 - $599      ",
        "$600 - $699      ",
        "$700 - $799      ",
        "$800 - $899      ",
        "$900 - $999      ",
        "$1000 en adelante"
    };

    for (int i = 0; i < 9; i++) {
        cout << rangos[i] << " | ";
        
        for (int j = 0; j < contadores[i]; j++) {
            cout << "*";
        }
        
        cout << "  (" << contadores[i] << ")" << endl;
    }

    cout << "Fin del programa." << endl;

    return 0;
}