/*====================================================
    =   Programa: Ejemplo62.cpp
    =   Fecha: 14 de octubre de 2026
    =   Autor: Luis Alfonso Reyes
    =   Asignaruta: DIA044-Programacion Basica
    =   No. de cuenta: 20192002012
    =  Busque el problema de las torres de hanoi y copie el código en c++, documente las líneas y haga una salida elegante
    =  (si, copie el código, se basa en funciones recursivas).

  =====================================================*/
#include <iostream>
#include <clocale>

using namespace std;

// ==========================================
// FUNCIÓN RECURSIVA PARA LAS TORRES DE HANÓI
// Parámetros:
//   n: número de discos a mover
//   origen: poste inicial
//   destino: poste final donde deben terminar
//   auxiliar: poste de apoyo temporal
// ==========================================
void hanoi(int n, int origen, int destino, int auxiliar)
{
    // Caso base: Si solo queda 1 disco, se mueve directamente de origen a destino
    if (n == 1)
    {
        cout << "   [Mover] Disco 1  -->  Del poste " << origen << " al poste " << destino << endl;
        return;
    }

    // Paso 1: Llamada recursiva para mover n-1 discos del poste origen al auxiliar, usando el destino como apoyo
    hanoi(n - 1, origen, auxiliar, destino);

    // Paso 2: Imprimir el movimiento del disco más grande actual desde el origen hasta el destino
    cout << "   [Mover] Disco " << n << "  -->  Del poste " << origen << " al poste " << destino << endl;

    // Paso 3: Llamada recursiva para mover los n-1 discos del auxiliar al destino, usando el origen como apoyo
    hanoi(n - 1, auxiliar, destino, origen);
}

int main()
{
    // Configura la consola para mostrar tildes correctamente
    setlocale(LC_ALL, "es_ES.UTF-8");

    int totalDiscos = 3; // Puedes cambiar este número para probar con más o menos discos

    cout << "==================================================" << endl;
    cout << "       RESOLUCIÓN DE LAS TORRES DE HANÓI          " << endl;
    cout << "       (Basado en funciones recursivas)           " << endl;
    cout << "==================================================" << endl << endl;

    cout << " Configuración inicial:" << endl;
    cout << " - Total de discos: " << totalDiscos << endl;
    cout << " - Poste de Origen: 1" << endl;
    cout << " - Poste Auxiliar:  2" << endl;
    cout << " - Poste de Destino:3" << endl << endl;

    cout << "=== SECUENCIA DE MOVIMIENTOS OPTIMIZADOS ===" << endl;
    
    // Invocación inicial de la función recursiva
    hanoi(totalDiscos, 1, 3, 2);

    cout << endl;
    cout << "==================================================" << endl;
    cout << " Proceso recursivo finalizado con Exito" << endl;
    cout << "==================================================" << endl;

    return 0;
}