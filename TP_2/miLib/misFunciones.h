#ifndef MISFUNCIONES_H_INCLUDED
#define MISFUNCIONES_H_INCLUDED
int getInt(int* retorno, char msg[], char errormsg[], int minimo,int maximo);
int getFloat(float* retorno, char msg[], char errormsg[], int minimo,int maximo);
int getChar(char* input,char msg[],char errorMsg[], char lowLimit, char hiLimit);
int getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit);
int validarS_N(char* input);
int crearMenu(int* retorno,char items[], int desde, int hasta);
int getUnsignedLongInt(unsigned long int* retorno, char msg[], char errormsg[], int minimo,int maximo);


//No usado en el TP 2
int esNumerico(char str[]);
int esTelefono(char str[]);
int esAlfanumerico(char str[]);
int esSoloLetras(char str[]);

#endif // FUNCIONES_H_INCLUDED
