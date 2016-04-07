#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funciones.h"


/** \brief Función que permite realizar cálculos básicos y el factorial de un número dado hasta 65
 *
 * \param No se ingresan parametros
 * \return No se devuelven parametros
 *
 */

int main()
{
    float operandoUno=0, operandoDos=0;
    char seguir='s';
    int opcion=0;
    unsigned long int resultadoFactorial; // se usa este tipo de variable para poder calcular el factorial y tener un rango de respuesta más amplio (hasta 65)

    while(seguir=='s')
    {
        do
        {
            printf("1- Ingresar 1er operando (A = %.2f)\n", operandoUno); //Se imprimen solo dos decimales para que no quede excesivamente largo
            printf("2- Ingresar 2do operando (B = %.2f)\n", operandoDos); //Se imprimen solo dos decimales para que no quede excesivamente largo
            printf("3- Calcular la suma (A+B)\n");
            printf("4- Calcular la resta (A-B)\n");
            printf("5- Calcular la division (A/B)\n");
            printf("6- Calcular la multiplicacion (A*B)\n");
            printf("7- Calcular el factorial (A!)\n");
            printf("8- Calcular todas las operacione\n");
            printf("9- Salir\n");
            scanf("%d",&opcion);

        }while(opcion <1||opcion>9);

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
                fflush(stdin);
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
                while(operandoDos==0) // valido que el divisor no sea cero
                {
                    printf("A = %.2f y B = %.2f\n", operandoUno,operandoDos);
                    printf("Por favor ingrese un número diferente a cero para el divisor: ");
                    scanf("%f",&operandoDos);
                }
                division(operandoUno, operandoDos);
                break;
            case 6:
                system("clear");
                multiplicacion(operandoUno, operandoDos);
                break;
            case 7:
                while(operandoUno<0||floor(operandoUno)!= operandoUno) //valido que el número sea entero positivo
                {
                    printf("A = %.2f y B = %.2f\n", operandoUno,operandoDos);
                    printf("Por favor ingrese un número entero positivo para calcular el factorial: ");
                    scanf("%f",&operandoUno);
                }
                resultadoFactorial=factorial((unsigned long int)operandoUno); //convierto el tipo de dato a unsigned long int
                system("clear");
                printf("El resultado del factorial de %.2f es: %lu.\n", operandoUno, resultadoFactorial);
                break;
            case 8:
                while(operandoDos==0) // valido que el divisor no sea cero
                {
                    printf("A = %.2f y B = %.2f\n", operandoUno,operandoDos);
                    printf("Por favor ingrese un número diferente a cero para el divisor: ");
                    scanf("%f",&operandoDos);
                }
                while(operandoUno<0||floor(operandoUno)!= operandoUno) //valido que el número sea entero positivo
                {
                    printf("A = %.2f y B = %.2f\n", operandoUno,operandoDos);
                    printf("Por favor ingrese un número entero positivo para calcular el factorial: ");
                    scanf("%f",&operandoUno);
                }
                system("clear");
                sumar(operandoUno, operandoDos);
                resta(operandoUno, operandoDos);
                division(operandoUno, operandoDos);
                multiplicacion(operandoUno, operandoDos);
                resultadoFactorial=factorial((unsigned long int)operandoUno); //convierto el tipo de dato a unsigned long int
                printf("El resultado del factorial de %.2f es: %lu.\n\n", operandoUno, resultadoFactorial);
                break;
            case 9:
                seguir = 'n';
                break;
        }



    }

    return 0;
}
