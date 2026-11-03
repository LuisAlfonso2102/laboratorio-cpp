/*====================================================
    =   Programa: Ejemplo47.cpp
    =   Fecha: 9 de octubre de 2026
    =   Autor: Luis Alfonso Reyes
    =   Asignaruta: DIA044-Programacion Basica
    =   No. de cuenta: 20192002012
    =  Usando la librería math.h haga un programa que en forma tabular muestre los grados desde 0o a 360o y a la par su seno, coseno y tangente. Debe satisfacer las siguientes restricciones:
    =  La tabla debe estar correctamente construida con columnas de un ancho de 15.
    =  Deben usarse solamente tres cifras decimales en los resultados mostrados.
    =  Como saldran 361 resultados el programa debe hacer una pausa y solicitar que se presione cualquier tecla cada vez que haya mostrado 50 valores.
    =  Después de cada pausa los encabezados de las columnas deben volver a aparecer.
  =====================================================*/
#include <iostream>
#include <cmath>    // funciones trigonométricas
#include <clocale>  // Para soporte de tildes y caracteres en español

using namespace std;

// Función auxiliar para redondear y mostrar números con exactamente 3 cifras decimales
// (Dado que no podemos usar las herramientas de iomanip por restricciones de clase)
void mostrarDecimal(double valor)
{
    // Multiplicamos por 1000, sumamos 0.5 para el redondeo y truncamos con una cast a entero
    long entero = (long)(valor * 1000.0 + (valor >= 0 ? 0.5 : -0.5));
    double resultadoRedondeado = (double)entero / 1000.0;

    cout << resultadoRedondeado;
}

// Función para imprimir los encabezados tabulares con columnas de ancho fijo (15 espacios)
void imprimirEncabezados()
{
    cout << "------------------------------------------------------------" << endl;
    cout << "Grados\t\tSeno\t\tCoseno\t\tTangente" << endl;
    cout << "------------------------------------------------------------" << endl;
}

int main()
{
    // Configura la consola para aceptar tildes correctamente
    setlocale(LC_ALL, "es_ES.UTF-8");

    // Constante de Pi para convertir grados a radianes
    const double PI = 3.141592;

    int contadorValores = 0;

    cout << "============================================================" << endl;
    cout << "        TABLA TRIGONOMÉTRICA (0° A 360°) - C++20            " << endl;
    cout << "============================================================" << endl << endl;

    // Imprimimos los encabezados iniciales
    imprimirEncabezados();

    // Ciclo desde 0° hasta 360°
    for (int grados = 0; grados <= 360; grados++)
    {
        // Convertimos de grados a radianes para la librería matemática
        double radianes = grados * PI / 180.0;

        double valorSeno = sin(radianes);
        double valorCoseno = cos(radianes);
        
        // Control matematico para evitar indeterminaciones infinitas en la tangente de 90° y 270°
        bool esIndeterminado = (grados == 90 || grados == 270);

        // Imprimimos los grados
        cout << grados << "°\t\t";

        // Imprimimos el Seno con 3 decimales
        mostrarDecimal(valorSeno);
        cout << "\t\t";

        // Imprimimos el Coseno con 3 decimales
        mostrarDecimal(valorCoseno);
        cout << "\t\t";

        // Imprimimos la Tangente (o un aviso si tiende al infinito)
        if (esIndeterminado)
        {
            cout << "Inf";
        }
        else
        {
            mostrarDecimal(tan(radianes));
        }

        cout << endl;

        contadorValores++;

        //Cada 50 valores, hacer una pausa, solicitar una tecla y reimprimir encabezados
        if (contadorValores == 50 && grados < 360)
        {
            cout << endl;
            cout << "[Pausa] Se han mostrado 50 valores." << endl;
            cout << "Presione la tecla 'Enter' o cualquier otra para continuar...";
            
            // Limpiamos el búfer y pausamos hasta que el usuario presione una tecla
            cin.get();

            cout << endl;
            imprimirEncabezados(); // Vuelven a aparecer los encabezados
            contadorValores = 0;   // Reiniciamos el contador para los siguientes 50
        }
    }

    cout << endl;
    cout << "============================================================" << endl;
    cout << " Tabla generada y completada con éxito hasta los 360°" << endl;
    cout << "============================================================" << endl;

    return 0;
}