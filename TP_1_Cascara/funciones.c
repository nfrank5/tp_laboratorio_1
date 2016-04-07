#include <stdio.h>
#include <stdlib.h>


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */


int sumar(float numero1, float numero2)
{
    float resultado;
    resultado = numero1 + numero2;
    printf("El resultado de la suma es: %.2f\n", resultado);
    return 0;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */


int resta(float numero1, float numero2)
{
    float resultado;
    resultado = numero1 - numero2;
    printf("El resultado de la resta es: %.2f\n", resultado);
    return 0;
}


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */


int division(float numero1, float numero2)
{
    float resultado;
    resultado = numero1 / numero2;
    printf("El resultado de la division es: %.2f\n", resultado);
    return 0;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int multiplicacion(float numero1, float numero2)
{
    float resultado;
    resultado = numero1 * numero2;
    printf("El resultado de la multiplicación es: %.2f\n", resultado);
    return 0;
}


/** \brief
 *
 * \param
 * \param
 * \return
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


