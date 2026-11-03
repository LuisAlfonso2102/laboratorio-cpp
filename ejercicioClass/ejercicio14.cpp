/*====================================================
    =   Programa: Ejemplo14.cpp
    =   Fecha: 30 de septiembre de 2026
    =   Autor: Luis Alfonso Reyes
    =   Asignaruta: DIA044-Programacion Basica
    =   No. de cuenta: 20192002012
    =   Desarrolle un programa en C++ que utilice una instrucción while para determinar el sueldo bruto para cada uno de
    =   varios empleados. La empresa paga la cuota normal en las primeras 40 horas de trabajo de cada empleado,
    =   y paga cuota y media en todas las horas trabajadas que excedan de 40. Usted recibe una lista
    =   de los empleados de la empresa, el número de horas que trabajó cada empleado la semana pasada y la tarifa
    =   por horas de cada empleado. Su programa debe recibir como entrada esta información para cada empleado, debe determinar
    =   y mostrar el sueldo bruto de cada empleado.
  =====================================================*/
#include<iostream>
using namespace std;

int main() {
    int horasTrabajadas;
    double tarifa, salario; // Las variables nombradas con DOUBLE porque las la tarifa puede llevar decimales y el salario tambien.

    cout<<"Digite las horas trabajadas del empleado(-1 si quiere salir):";//aun que el problema no lo pide agrege un centinela (-1) para que el usuario pueda detener la ejecucion del programa.
    cin>>horasTrabajadas;

    while (horasTrabajadas != -1) {// El simbolo != (diferente a=) de ser diferente a -1 se repite el siclo. pag49
        cout<< "Ingrese la tarifa por hora del empleado:";
        cin>>tarifa;
        
        if (horasTrabajadas<=40){
            salario=horasTrabajadas*tarifa;
        }
        else{
            salario=(tarifa*40)+(horasTrabajadas-40)*(tarifa*1.5);
        }

        cout<<"El total del salario es:"<<salario<<endl;

        cout<<"Ingrese las horas trabajadas del empleado(-1 si quiere salir):";
        cin>>horasTrabajadas;

    }

    return 0;
}