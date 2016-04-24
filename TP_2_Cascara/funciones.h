#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define MAXIMO 20
typedef struct {

    char nombre[50];
    int edad;
    int estado;
    unsigned long int dni;

}EPersona;
int crearMenu(int* retorno,char items[], int desde, int hasta);
int inicializarEstado(EPersona persona[]);
int obtenerEspacioLibre(EPersona lista[],int*i);
int agregarPersona(EPersona lista[],int*aux);
int buscarPorDni(EPersona lista[],int*aux);
int imprimirLista(EPersona persona[]);
int borrarPersona(EPersona lista[],int*aux);
int imprimirGrafico(EPersona lista[]);
#endif // FUNCIONES_H_INCLUDED
