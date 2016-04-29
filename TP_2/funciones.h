#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    unsigned long int dni;

}EPersona;
int crearMenu(int* retorno,char items[], int desde, int hasta);
int inicializarEstado(EPersona persona[],int length);
int obtenerEspacioLibre(EPersona lista[],int*i,int length);
int agregarPersona(EPersona lista[],int*aux,int length);
int buscarPorDni(EPersona lista[],int*aux,int length);
int imprimirLista(EPersona persona[],int length);
int borrarPersona(EPersona lista[],int*aux,int length);
int imprimirGrafico(EPersona lista[],int length);
#endif // FUNCIONES_H_INCLUDED
