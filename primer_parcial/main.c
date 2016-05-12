#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "funciones.h"


void adminUsers (EUser userArray[],EComments commentArray[]);
void adminComments(EComments commentArray[],EUser userArray[]);

int main()
{
    EUser userArray[MAX_USER];
    EComments commentArray[MAX_COMMENT];

    initializeUserArrayStatus(userArray, MAX_USER);
    initializeCommentArrayStatus(commentArray,MAX_COMMENT);
    int i;

    char AUXnickname[5][51]={"Julito","Juli","Fedor","Cortina","Mir"};
    char AUXname[5][51]={"Julio Verne","Julio Verne","Dostoyevsky","Julio Cortazar","Mircea Eliade"};
    char AUXeMail[5][51]={"julioV@gmail.com","juveE@gmail.com","fedord@gmail.com","jcortazar@gmail.com","meliade@gmail.com"};
    int AUXpassword[5]={123123,654654,987987,753753,951951};
    int AUXcommentId[5]={32,11,98,45,26};
    int AUXlikesCounter[5]={3,10,9,4,2};
    char AUXcommentText[5][51]={"Hola que tal","Todo bien?","saludos a la familia","Nos vemos!","No estoy de acuerdo"};
    char AUXnicknameComment[5][51]={"Julito","Juli","Fedor","Cortina","Mir"};
    for(i=0;i<5;i++)
    {

        strcpy(userArray[i].nickname,AUXnickname[i]);
        strcpy(userArray[i].name,AUXname[i]);
        strcpy(userArray[i].eMail,AUXeMail[i]);
        userArray[i].password=AUXpassword[i];


        strcpy(commentArray[i].nickname,AUXnicknameComment[i]);
        commentArray[i].commentId=AUXcommentId[i];
        commentArray[i].likesCounter=AUXlikesCounter[i];

        strcpy(commentArray[i].commentText,AUXcommentText[i]);
        userArray[i].status=1;
        commentArray[i].status=1;
    }

    int addUserCounter=0,addCommentCounter=0;
    char follow='s';
    int opcion;
    while(follow=='s')
    {
        for(i=0;i<MAX_USER;i++)
        {
            if(userArray[i].status==1)
            {
                addUserCounter++;
            }
        }
        for(i=0;i<MAX_COMMENT;i++)
        {
            if(commentArray[i].status==1)
            {
                addCommentCounter++;
            }
        }
        crearMenu(&opcion,"1-Menu de usuarios\n2-Menu de comentarios\n3-Informar\n4-Listar\n5-Salir\n",1,5);
        switch(opcion)
        {
            case 1:
                system("@cls||clear");
                adminUsers(userArray,commentArray);
                break;
            case 2:
                if(addUserCounter>0)
                {
                    system("@cls||clear");
                    adminComments(commentArray,userArray);
                }
                else
                {
                    system("@cls||clear");
                    printf("No hay altas\n");
                }
                break;
            case 3:
                if(addCommentCounter>0)
                {
                    system("@cls||clear");
                    printInformar(commentArray,MAX_COMMENT);
                }
                else
                {
                    system("@cls||clear");
                    printf("No hay altas\n");
                }
                break;
            case 4:
                if(addUserCounter>0&&addCommentCounter>0)
                {
                    system("@cls||clear");
                    printUserCommentList(userArray,commentArray,MAX_COMMENT,MAX_USER);
                }
                else
                {
                    system("@cls||clear");
                    printf("No hay altas\n");
                }
                break;
            case 5:
                follow='n';
                break;
        }

    }

    return 0;
}



void adminUsers(EUser userArray[],EComments commentArray[])
{
    char follow='s';
    int opcion,i;
    int auxBuscar;
    int contadorAltas=0;
    for(i=0;i<MAX_USER;i++)
    {
        if(userArray[i].status==1)
        {
            contadorAltas++;
        }
    }
    while(follow=='s')
    {
        crearMenu(&opcion,"1-Altas\n2-Modificar\n3-Bajas\n4-Menu Principal\n",1,4);
        switch(opcion)
        {
            case 1:
                if(obtenerEspacioLibre(userArray,&auxBuscar,MAX_USER)==0)
                {
                    if(addItem(userArray,commentArray,&auxBuscar,MAX_USER,MAX_COMMENT)==0)
                    {
                        contadorAltas++;
                    }
                }
                break;
            case 2:
                if(contadorAltas>0)
                {
                    if(findUserByNick(userArray,&auxBuscar,MAX_USER)==0)
                    {
                        modifyUser(userArray,commentArray,&auxBuscar,MAX_USER,MAX_COMMENT);
                    }
                }
                else
                {
                    system("@cls||clear");
                    printf("No hay altas\n");
                }
                break;
            case 3:
                if(contadorAltas>0)
                {
                    if(findUserByNick(userArray,&auxBuscar,MAX_USER)==0)
                    {
                        if(deleteUser(userArray,&auxBuscar,MAX_USER)==0)
                        {
                            contadorAltas--;
                        }
                    }
                }
                else
                {
                    system("@cls||clear");
                    printf("No hay altas\n");
                }
                break;
            case 4:
                system("@cls||clear");
                follow='n';
                break;
        }
    }
}

void adminComments(EComments commentArray[],EUser userArray[])
{
    char follow='s';
    int opcion,i;
    int auxBusqueda;
    int contadorAltas=0;
    for(i=0;i<MAX_USER;i++)
    {
        if(userArray[i].status==1)
        {
            contadorAltas++;
        }
    }
    while(follow=='s')
    {
        crearMenu(&opcion,"1-Nuevo Comentario\n2-Nuevo Me gusta\n3-Menu principal\n",1,3);
        switch(opcion)
        {
            case 1:
                system("@cls||clear");
                if(contadorAltas>0)
                {
                    if(obtenerEspacioLibreComments(commentArray,&auxBusqueda,MAX_COMMENT)==0)
                    {
                        newComment(userArray,commentArray,&auxBusqueda,MAX_USER,MAX_COMMENT);
                    }

                }
                else
                {
                    system("@cls||clear");
                    printf("No hay altas\n");
                }
                break;
            case 2:
                system("@cls||clear");
                if(contadorAltas>0)
                {
                    newLike(commentArray,MAX_COMMENT,userArray,MAX_USER);
                }
                else
                {
                    system("@cls||clear");
                    printf("No hay altas\n");
                }
                break;
            case 3:
                system("@cls||clear");
                follow='n';
                break;
        }

    }



}
