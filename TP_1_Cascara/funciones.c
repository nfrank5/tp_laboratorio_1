#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/** \brief operación de suma
 *
 * \param dos números en float
 * \return nada porque se imprime el resultado dentro de la función
 *
 */
int sumar(float numero1, float numero2)
{
    float resultado;
    resultado = numero1 + numero2;
    printf("El resultado de %.2f + %.2f = %.2f\n\n",numero1,numero2,resultado);
    return 0;
}

/** \brief operación de resta
 *
 * \param dos números en float
 * \return nada porque se imprime el resultado dentro de la función
 *
 */
int resta(float numero1, float numero2)
{
    float resultado;
    resultado = numero1 - numero2;
    printf("El resultado de %.2f - %.2f = %.2f\n\n",numero1,numero2,resultado);
    return 0;
}

/** \brief operación de división
 *
 * \param dos números en float
 * \return nada porque se imprime el resultado dentro de la función
 *
 */
int division(float numero1, float numero2)
{
    float resultado;
    resultado = numero1 / numero2;
    printf("El resultado de %.2f / %.2f = %.2f\n\n",numero1,numero2,resultado);
    return 0;
}

/** \brief operación de multiplicación
 *
 * \param dos números en float
 * \return nada porque se imprime el resultado dentro de la función
 *
 */
int multiplicacion(float numero1, float numero2)
{
    float resultado;
    resultado = numero1 * numero2;
    printf("El resultado de %.2f * %.2f = %.2f\n\n",numero1,numero2,resultado);
    return 0;
}

/** \brief cálculo de factorial
 *
 * \param un número en unsigned long int
 * \return un número en unsigned long int
 *
 */
unsigned long int factorial(unsigned long int numero)
{
    unsigned long int resultado;
    if(numero == 1)
    {
        return 1;
    }
    resultado = numero * factorial(numero-1);
    return resultado;
}



/** \brief valido que el número sea entero positivo para calcular el factorial
 *
 * \param float
 * \return el número entero y positivo en float
 *
 */
float validarFactorial(float numero1, float numero2)
{
    system("clear");
    while(numero1<0||floor(numero1)!= numero1)
    {
        printf("A=%.2f\t\tB=%.2f\n",numero1,numero2);
        printf("Por favor ingrese en A un número entero positivo para poder calcular el factorial: ");
        scanf("%f",&numero1);

    }
    return numero1;
}

/** \brief valido que el divisor no sea cero
 *
 * \param el divisor de la función main
 * \return el divisor validado
 *
 */
float validoDivisor(float numero1, float numero2)
{
    while(numero2==0)
    {
        printf("A=%.2f\t\tB=%.2f\n",numero1,numero2);
        printf("Por favor ingrese un número diferente a cero en B para el divisor: ");
        scanf("%f",&numero2);
    }
    return numero2;
}
