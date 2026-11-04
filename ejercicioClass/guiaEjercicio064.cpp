/*====================================================
    =   Programa: Ejemplo64.cpp
    =   Fecha: 15 de octubre de 2026
    =   Autor: Luis Alfonso Reyes
    =   Asignaruta: DIA044-Programacion Basica
    =   No. de cuenta: 20192002012
    =  Escriba un programa completo en C++ con las dos funciones alternativas que se especiﬁ can a continuación,
    =  de las cuales cada una simplemente triplica la variable cuenta deﬁ nida en main. Después compare y contraste ambos métodos.
    =  Estas dos funciones son: 
    =  la función triplicarPorValor, que pasa una copia de cuenta por valor, triplica la copia y devuelve el nuevo valor, y 
    =  la función triplicarPorReferencia, que pasa cuenta por referencia a través de un parámetro por referencia y triplica
    = el valor original de cuenta a través de su alias (es decir, el parámetro por referencia). (Ejercicio 6.56, Libro 1)  .
  =====================================================*/

  #include <iostream>
  #include <clocale>

using namespace std;

//Función triplicarPorValor:
// Recibe una copia de la variable, la triplica internamente y devuelve el nuevo valor mediante return.
int triplicarPorValor(int c)
{
    c = c * 3; // Modifica únicamente la copia local
    return c;  // Devuelve el resultado
}

//Función triplicarPorReferencia:
// Recibe la variable mediante un parámetro por referencia usando &,
// lo que crea un alias que modifica directamente la variable original en el main.
void triplicarPorReferencia(int &c)
{
    c = c * 3; // Modifica directamente la variable original en memoria
}

int main()
{
    // Configura la consola para aceptar tildes y la letra ñ correctamente
    setlocale(LC_ALL, "es_ES.UTF-8");

    // Definición de la variable cuenta en el main
    int cuenta = 5;

    cout << "     Comparación: Paso por Valor vs Referencia    " << endl;

    cout << "1. Metodo triplicarPorValor:" << endl;
    cout << "   Valor original de cuenta en main: " << cuenta << endl;
    
    // Como es por valor, se pasa una copia. Para ver el cambio en main,
    // debemos reasignar explícitamente el valor devuelto por la función.
    cuenta = triplicarPorValor(cuenta);
    
    cout << "   Valor de cuenta después de la función por valor: " << cuenta << endl << endl;

    //Reiniciamos cuenta a 5 para el siguiente experimento
    cuenta = 5;

    cout << "2. Método triplicarPorReferencia:" << endl;
    cout << "   Valor original de cuenta en main: " << cuenta << endl;
    
    // Llamamos a la función pasando la variable por referencia.
    // Modifica la variable original de forma automática sin necesidad de return.
    triplicarPorReferencia(cuenta);
    
    cout << "   Valor de cuenta después de la función por referencia: " << cuenta << endl << endl;

    //La comprobacion y contraste de ambos metodos se hace en la siguiente sección:
   
    cout << " COMPARACIÓN Y CONTRASTE DE AMBOS MÉTODOS:" << endl;
    cout << "- Paso por Valor (triplicarPorValor):" << endl;
    cout << "  * Crea una copia independiente del argumento en la memoria." << endl;
    cout << "  * Los cambios hechos dentro de la función no afectan a la variable original." << endl;
    cout << "  * Requiere obligatoriamente un 'return' para enviar el resultado de vuelta al main." << endl << endl;
    cout << "- Paso por Referencia (triplicarPorReferencia):" << endl;
    cout << "  * No crea una copia; utiliza un alias ('&') que apunta directamente a la variable original." << endl;
    cout << "  * Cualquier alteración dentro de la función modifica la variable original al instante." << endl;
    cout << "  * No necesita una instrucción 'return' (puede ser de tipo void)." << endl;

    return 0;
}