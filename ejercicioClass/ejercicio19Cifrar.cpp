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

main(){
  int numeroCifrado, numero;//Todos enteros por que no estamos trabajando con decimales en este caso.
  int d1,d2,d3,d4;//estos son los digitos
  int dc1,dc2,dc3,dc4;//estos son los digitos cifrados

  cout<<"Ingrese el Numero Entero de 4 digitos para Cifrar:";
  cin>> numero;
  //Ahora tengo que extraer cada digito del numero de 4 cifras. Esto con el proposito de aplicar el Criptograma.
  d1=numero/1000;
  d2=(numero/100)%10;
  d3=(numero/10)%10;
  d4=numero%10;

  //Aqui estoy reemplazando cada digito con la operacion(digito+7)%10---------%=Modulo. pag45
  dc1=(d1+7)%10;
  dc2=(d2+7)%10;
  dc3=(d3+7)%10;
  dc4=(d4+7)%10;

  /*Ahora tengo que intercambiar los digitos como me lo pide el problema.
  Al final el orden quedaria asi: dc3, dc4, dc1, dc2
  */

  numeroCifrado=(dc3 * 1000) + (dc4 * 100) + (dc1 * 10) + dc2;

  cout<<"El numero de 4 digitos cifrado es:"<<numeroCifrado<<endl;

  return 0;
}