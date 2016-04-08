#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funciones.h"

/** \brief Función que permite realizar cálculos básicos y el factorial de un número dado
 *
 * \param No se ingresan parametros
 * \return No se devuelven parametros
 *
 */
int main()
{
    float operandoUno=0.0, operandoDos=0.0; //  inicializo para que no lea basura en el menu
    char seguir='s'; // para salir del menú
    unsigned long int resultadoFactorial; // utilizo este tipo de variable para poder calcular el factorial y tener un rango de respuesta más amplio (hasta 65)
    int opcion; //opcion del menú
    while(seguir=='s')
    {
        do
        {
            if(opcion>2&&opcion<9)
            {
                operandoUno=0.0;//reinicio los operandos a cero despues de cada cálculo como nos indicó el profesor
                operandoDos=0.0;//reinicio los operandos a cero despues de cada cálculo como nos indicó el profesor
            }
            printf("1- Ingresar 1er operando (A = %.2f)\n", operandoUno); //Se imprimen solo dos decimales para que no quede excesivamente largo
            printf("2- Ingresar 2do operando (B = %.2f)\n", operandoDos);
            printf("3- Calcular la suma (A+B)\n");
            printf("4- Calcular la resta (A-B)\n");
            printf("5- Calcular la division (A/B)\n");
            printf("6- Calcular la multiplicacion (A*B)\n");
            printf("7- Calcular el factorial (A!)\n");
            printf("8- Calcular todas las operacione\n");
            printf("9- Salir\n");
            scanf("%d",&opcion);
        }while(opcion<1||opcion>9);

        switch(opcion)
        {
            case 1:
                system("clear");
                printf("Ingrese el primer operando: ");
                scanf("%f", &operandoUno);
                break;
            case 2:
                system("clear");
                printf("Ingrese el segundo operando: ");
                scanf("%f", &operandoDos);
                break;
            case 3:
                system("clear");
                sumar(operandoUno, operandoDos);
                break;
            case 4:
                system("clear");
                resta(operandoUno, operandoDos);
                break;
            case 5:
                system("clear");
                operandoDos=validoDivisor(operandoUno,operandoDos);
                division(operandoUno, operandoDos);
                break;
            case 6:
                system("clear");
                multiplicacion(operandoUno, operandoDos);
                break;
            case 7:
                operandoUno=validarFactorial(operandoUno, operandoDos);
                resultadoFactorial=factorial((unsigned long int)operandoUno); //convierto el tipo de dato a unsigned long int
                system("clear");
                printf("El resultado de %.0f! = %lu\n\n", operandoUno, resultadoFactorial);
                break;
            case 8:
                system("clear");
                operandoUno=validarFactorial(operandoUno, operandoDos);
                operandoDos=validoDivisor(operandoUno,operandoDos);
                sumar(operandoUno, operandoDos);
                resta(operandoUno, operandoDos);
                division(operandoUno, operandoDos);
                multiplicacion(operandoUno, operandoDos);
                resultadoFactorial=factorial((unsigned long int)operandoUno); //convierto el tipo de dato a unsigned long int
                printf("El resultado de %.0f! = %lu\n\n", operandoUno, resultadoFactorial);
                break;
            case 9:
                seguir = 'n';
                break;
        }
    }
    return 0;
}
