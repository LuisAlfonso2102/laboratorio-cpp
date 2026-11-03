/*====================================================
    =   Programa: Ejemplo19.cpp
    =   Fecha: 30 de septiembre de 2026
    =   Autor: Luis Alfonso Reyes
    =   Asignaruta: DIA044-Programacion Basica
    =   No. de cuenta: 20192002012
    =   (Criptografía)  Una compañía desea transmitir datos a través del teléfono, pero le preocupa que sus teléfonos puedan estar intervenidos. 
    =   Todos los datos se transmiten como enteros de cuatro dígitos. La compañía le ha pedido a usted que escriba un programa que cifre sus datos,
    =   de manera que éstos puedan transmitirse con más seguridad. Su programa debe leer un entero de cuatro dígitos introducido por el usuario y 
    =   cifrarlo de la siguiente manera: reemplace cada dígito con (el resultado de sumar 7 al dígito) módulo 10. Luego intercambie el primer dígito
    =   con el tercero, intercambie el segundo dígito con el cuarto. Después imprima el entero cifrado. Escriba un programa separado que reciba como 
    =   entrada un entero de cuatro dígitos cifrado, y que lo descifre para formar el número original. 

  =====================================================*/

#include <iostream>
using namespace std;

int main() {
    int numeroCifrado, dc1, dc2, dc3, dc4;//Todos enteros por que no estamos trabajando con decimales en este caso.
    int d1, d2, d3, d4;
    int numeroOriginal;//es la misma variable (original) del primer programa. 

    cout << "Introduce el entero cifrado de cuatro digitos: ";// En esta parte debo ingresar el numero cifrado que me dio el ejemplo19Cifrado.
    cin >> numeroCifrado;

    //Ahora debo extrajer los digitos como lo hice anteriormente, pero con el orden diferente.
    dc3 = numeroCifrado / 1000;
    dc4 = (numeroCifrado / 100) % 10;
    dc1 = (numeroCifrado / 10) % 10;
    dc2 = numeroCifrado % 10;

    /*En esta parte tengo que recuperar los numeros originales que digite antes del cifrado del primer programa. 
    Y para conseguirlo, estoy aplicando el +3, es la llave perfecta para completar la decena ya que en el programa
    anterior puse +7.
    */
    d1 = (dc1 + 3) % 10;
    d2 = (dc2 + 3) % 10;
    d3 = (dc3 + 3) % 10;
    d4 = (dc4 + 3) % 10;

    //En esta parte reconstrui el orden del numero original.
    numeroOriginal = (d1 * 1000) + (d2 * 100) + (d3 * 10) + d4;

    cout << "El numero original descifrado de 4 difras fue: " << numeroOriginal << endl;

    return 0;
}