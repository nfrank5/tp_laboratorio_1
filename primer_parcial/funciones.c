#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#include "utn.h"

/** \brief inicializa el estado en todos los indices del array de la estructura
 *
 * \param el array de la estructura
 * \param largo del array de la estructura
 * \return 0 si inicializo -1 si hubo error
 *
 */
int initializeUserArrayStatus(EUser lista[],int length)
{
    int i;
    int retorno=-1;
    if(lista!=NULL&&length>0)
    {
        for(i=0;i<length;i++) //inicializo flag de estado
        {
            lista[i].status=0;
            retorno=0;
        }
    }

    return retorno;
}


/** \brief inicializa el estado en todos los indices del array de la estructura
 *
 * \param el array de la estructura
 * \param largo del array de la estructura
 * \return 0 si inicializo -1 si hubo error
 *
 */

int initializeCommentArrayStatus(EComments lista[],int length)
{
    int i;
    int retorno=-1;
    if(lista!=NULL&&length>0)
    {
        for(i=0;i<length;i++) //inicializo flag de estado
        {
            lista[i].status=0;
            retorno=0;
        }
    }

    return retorno;
}

/** \ Obtiene el primer indice libre del array.
 *
 * \param el array de la estructura
 * \param puntero para indicar el indice del espacio libre
 * \param largo del array de la estructura
 * \return 0 si hay espacio libre -1 si no lo hay
 */
int obtenerEspacioLibre(EUser lista[],int*aux,int length)
{
    int i;
    int flagEncontrado=0;
    int retorno=-1;
    if(lista!=NULL&&length>0)
    {
        for(i=0;i<length;i++)
        {
            if(lista[i].status==0)
            {
                *aux=i;
                flagEncontrado=1;
                retorno=0;
                return retorno;
            }
        }
        if(flagEncontrado==0)
        {
            system("@cls||clear");
            printf("No hay espacio libre\n");
        }
    }
    return retorno;
}

/** \brief Agregar un item
 *
 * \param el array de la estructura de usuarios
 * \param el array de la estructura de comentarios
 * \param el puntero del indice del array
 * \param largo del array de la estructura de usuarios
 * \param largo del array de la estructura de comentarios
 * \return 0 si se agrego al item -1 si es duplicado
 *
 */
int addItem(EUser lista[],EComments commentArray[],int*aux,int length,int lengthComment)
{
    system("@cls||clear");
    int i/*,flagCommentCode=-1*/;
    char auxNickname[51];
    int retorno=-1/*,auxCommentCode*/;
    if(lista!=NULL&&length>0&&commentArray!=NULL&&lengthComment>0)
    {
        while(getString(auxNickname,"Ingrese nick del usuario: ","Error, intente nuevamente",1,51)==-1);
        for(i=0;i<length;i++)
        {
            if((strcmp(auxNickname,lista[i].nickname)==0)&&lista[i].status==1)
            {
                printf("¡Error! nick duplicado\n");
                return retorno;
            }
            else
            {
                strcpy(lista[*aux].nickname,auxNickname);
            }
        }
        while(getString(lista[*aux].name,"Ingrese nombre del usuario: ","Error, intente nuevamente",1,51)==-1);
        while(getString(lista[*aux].eMail,"Ingrese correo electronico del usuario: ","Error, intente nuevamente",1,51)==-1);
        while(getInt(&lista[*aux].password,"Ingrese una contraseña numerica [100-999999]: ","Error, intente nuevamente[100-999999]",100,999999)==-1);
        retorno=0;
        lista[*aux].status=1;
    }
    return retorno;
}

/** \brief busca a un usuario por el nick
 *
 * \param El array de la estructura users
 * \param un puntero para retornar el indice
 * \param largo del array de la estructura users
 * \return 0 encontrado -1 no se encontro
 *
 */
int findUserByNick(EUser lista[],int*aux,int length)
{
    char auxNickname[51];
    int i, flagEncontrado=0;
    printf("Ingrese el nick del usuario\n");
    scanf("%s",auxNickname);
    int retorno=-1;
    if(lista!=NULL&&length>0)
    {
        for(i=0;i<length;i++)
        {
            if(strcmp(auxNickname,lista[i].nickname)==0&&lista[i].status==1)
            {
                flagEncontrado=1;
                *aux=i;
                system("@cls||clear");
                retorno=0;
            }
        }
        if(flagEncontrado==0)
        {
            system("@cls||clear");
            printf("No se encontro el nick\n");
        }

    }

    return retorno;
}

/** \brief borra al usuario seleccionado por el usuario
 *
 * \param el array de la estructura
 * \param un puntero con el indice del libro elegido para ser borrado
 * \param largo del array de la estructura
 * \return 0 si fue eliminada -1 si no lo fue
 *
 */
int deleteUser(EUser lista[],int*aux,int length)
{
    char auxBorrado='n';
    int retorno=-1;
    if(lista!=NULL&&length>0)
    {
        if(lista[*aux].status==1)
        {
            printf("Usted va a eliminar a %s.\n",lista[*aux].name);
            validarS_N(&auxBorrado);
            if(auxBorrado=='s')
            {
                lista[*aux].status=0;
                printf("Usuario eliminado\n");
                retorno=0;
                return retorno;
            }
        }
        else
        {
            printf("Error, no existe el usuario\n");
        }
    }
    return retorno;
}

/** \brief modificar un usuario
 *
 * \param el array de la estructura de users
 * \param el array de la estructura comments
 * \param el puntero del indice del array
 * \param largo del array de la estructura users
 * \param largo del array de la estructura comments
 * \return 1 si se agrego la persona -1 si hubo error
 *
 */
int modifyUser(EUser lista[],EComments commentArray[],int*aux,int length,int lengthComment)
{
    system("@cls||clear");
    char continuar='s';
    int opcion;
    int flagCommentCode=0/*,auxCommentCode,i,auxNickname*/;
    int retorno=-1;
    if(lista!=NULL&&length>0)
    {
        while(continuar=='s')
        {
            system("@cls||clear");
            printf("Usted va a modificar el perfil del usuario: %s\n", lista[*aux].nickname);
            crearMenu(&opcion,"1-Modificar el nombre\n2-Modificar el correo\n3-Modificar la contraseña\n4-Salir\n",1,4);
            switch(opcion)
            {
                case 1:
                    while(getString(lista[*aux].name,"Ingrese nuevo nombre del usuario: ","Error, intente nuevamente",1,51)==-1);
                    break;
                case 2:
                    while(getString(lista[*aux].eMail,"Ingrese el nuevo correo electronico del usuario: ","Error, intente nuevamente",1,51)==-1);
                    break;
                    if(flagCommentCode==-1)
                    {
                        printf("ERROR\nCodigo autor no existe\n");
                    }
                    if(flagCommentCode==0)
                    {
                        retorno=0;
                        lista[*aux].status=1;
                    }
                break;
                case 3:
                while(getInt(&lista[*aux].password,"Ingrese una nueva contraseña numerica [100-999999]: ","Error, intente nuevamente[100-999999]",100,999999)==-1);
                    break;
                case 4:
                    continuar='n';
                    retorno=0;
                    break;
            }
        }
    }
    return retorno;
}

/** \ Obtiene el primer indice libre del array de comentarios.
 *
 * \param el array de la estructura
 * \param puntero para indicar el indice del espacio libre
 * \param largo del array de la estructura
 * \return 0 si hay espacio libre -1 si no lo hay
 */
int obtenerEspacioLibreComments(EComments lista[],int*aux,int length)
{
    int i;
    int flagEncontrado=0;
    int retorno=-1;
    if(lista!=NULL&&length>0)
    {
        for(i=0;i<length;i++)
        {
            if(lista[i].status==0)
            {
                *aux=i;
                flagEncontrado=1;
                retorno=0;
                return retorno;
            }
        }
        if(flagEncontrado==0)
        {
            system("@cls||clear");
            printf("No hay espacio libre\n");
        }
    }
    return retorno;
}

/** \ añade un comentario en el array de comentarios.
 *
 * \param el array de la estructura de usuarios
 * \param el array de la estructura de comentarios
 * \param puntero con el indice del espacio libre
 * \param largo del array de la estructura user
 * \param largo del array de la estructura comments
 * \return 0 si hay espacio libre -1 si no lo hay
 */
int newComment(EUser lista[],EComments commentArray[],int*aux,int length,int lengthComment)
{
    system("@cls||clear");
    int i,flagCommentId=-1,auxPassword=-1,auxBusqueda,auxCommentId,flagNick=-1;
    char auxNickname[51];
    int retorno=-1;
    if(lista!=NULL&&length>0&&commentArray!=NULL&&lengthComment>0)
    {
        while(getString(auxNickname,"Ingrese nick: ","Error, intente nuevamente",1,51)==-1);
        for(i=0;i<length;i++)
        {
            if(strcmp(auxNickname,lista[i].nickname)==0&&lista[i].status==1)
            {
                strcpy(commentArray[*aux].nickname,auxNickname);
                flagNick=0;
                auxBusqueda=i;
            }
        }
        if(flagNick==-1)
        {
            printf("¡Error! Nick no existe\n");
            return retorno;
        }
        while(getInt(&auxPassword,"Ingrese su contraseña numerica: ","Error, intente nuevamente",100,999999)==-1);
        if(auxPassword==lista[auxBusqueda].password)
        {
            while(getInt(&auxCommentId,"Ingrese el identificador de comentario[0-10000]: ","Error, intente nuevamente[0-10000]",0,10000)==-1);
            for(i=0;i<lengthComment;i++)
            {
                if(auxCommentId==commentArray[i].commentId&&commentArray[i].status==1)
                {
                    printf("¡Error! Identificador de comentario duplicado\n");
                    return retorno;
                }
                else
                {
                    commentArray[*aux].commentId=auxCommentId;
                    flagCommentId=0;
                }
            }
        }
        else
        {
            printf("¡Error! contraseña equivocada\n");
            return retorno;
        }
        while(getString(commentArray[*aux].commentText,"Ingrese texto del comentario: ","Error, intente nuevamente",1,51)==-1);
        if(flagNick==0&&flagCommentId==0)
        {
            retorno=0;
            commentArray[*aux].status=1;
        }
    }
    return retorno;

}

/** \ añade un like en el array de comentarios.
 *
 * \param el array de la estructura de comentarios
 * \param largo del array de la estructura comments
 * \param el array de la estructura de usuarios
 * \param largo del array de la estructura user
 * \return 0 si hay añade exitosamente -1 si no
 */
int newLike(EComments lista[],int length,EUser userArray[],int lengthUser)
{
    system("@cls||clear");
    int i,flagNick=-1,flagCommentId=-1,flagPassword=-1,auxLikes,auxBusquedaUser,auxBusquedaComment,auxCommentId,auxPassword;
    char auxNickname[51];
    int retorno=-1;
    if(lista!=NULL&&length)
    {
        do
        {
            while(getInt(&auxCommentId,"Ingrese el identificador de comentario[0-10000]: ","Error, intente nuevamente[0-10000]\n",0,10000)==-1);
            for(i=0;i<length;i++)
            {
                if(auxCommentId==lista[i].commentId&&lista[i].status==1)
                {
                    flagCommentId=0;
                    auxBusquedaComment=i;
                }
            }
            if(flagCommentId==-1)
            {
                printf("No existe ese comentario\n");
            }
        }while(flagCommentId==-1);
        do
        {
            while(getString(auxNickname,"Ingrese nick: ","Error, intente nuevamente\n",1,51)==-1);
            for(i=0;i<lengthUser;i++)
            {
                if(strcmp(auxNickname,userArray[i].nickname)==0&&userArray[i].status==1)
                {
                    flagNick=0;
                    auxBusquedaUser=i;
                }
            }
            if(flagNick==-1)
            {
                printf("No existe ese Nick\n");
            }
        }while(flagNick==-1);
        do
        {
            while(getInt(&auxPassword,"Ingrese su contraseña numerica: ","Error, intente nuevamente\n",100,999999)==-1);
            if(auxPassword==userArray[auxBusquedaUser].password)
            {
                flagPassword=0;
            }
            else
            {
                printf("Contraseña Incorrecta\n");
            }
        }while(flagPassword==-1);

        if(flagCommentId==0&&flagNick==0&&flagPassword==0)
        {
            while(getInt(&auxLikes,"Ingrese 1 a 3 likes.\n","Error, intente nuevamente\n",1,3)==-1);
            lista[auxBusquedaComment].likesCounter+=auxLikes;
            retorno=0;
        }
    }
    return retorno;
}

/** \ imprime el usuario con mayor contidad de comentarios, el comentario con mayor contidad de likes y el valor promedio de me gusta
 *
 * \param el array de la estructura de comentarios
 * \param largo del array de la estructura comments
 * \return 0 si imprime exitosamente -1 si no
 */
int printInformar(EComments lista[],int length)
{
    int nickComment=0,nickCommentMax;
    int commentLikeMax,commentLikeMaxId;
    char commentLikeMaxText[51];
    float likeAveragePerCommentCounter=0.00;
    float average,likeAveragePerCommentAcumulador=0.00;
    char auxnick[51];
    int flagMax=0;
    int i,j;
    int retorno=-1;
    if(lista!=NULL&&length)
    {
        for(i=0;i<length-1;i++)
        {
            for(j=i+1;j<length;j++)
            {
                if(lista[i].status==1&&strcmp(lista[i].nickname,lista[j].nickname)==0)
                {
                    nickComment++;
                }
                if(flagMax==0)
                {
                    nickCommentMax=nickComment;
                    strcpy(auxnick,lista[i].nickname);
                    flagMax=1;
                }
                if(flagMax==1&&nickComment>nickCommentMax)
                {
                    nickCommentMax=nickComment;
                    strcpy(auxnick,lista[i].nickname);
                }
            }
        }
        printf("El usuario con mayor contidad de comentarios es: %s\n",auxnick);

        commentLikeMax=lista[0].likesCounter;
        commentLikeMaxId=lista[0].commentId;
        for(i=0;i<length;i++)
        {
                if(lista[i].status==1&&lista[i].likesCounter>commentLikeMax)
                {
                    commentLikeMax=lista[i].likesCounter;
                    commentLikeMaxId=lista[i].commentId;
                    strcpy(commentLikeMaxText,lista[i].commentText);
                }
        }
        printf("El comentario con mayor cantidad de likes es:%s (codigo %d)\n",commentLikeMaxText, commentLikeMaxId);

        for(i=0;i<length;i++)
        {
            if(lista[i].status==1)
            {
                likeAveragePerCommentAcumulador= likeAveragePerCommentAcumulador+lista[i].likesCounter;
                likeAveragePerCommentCounter++;
            }
        }
        average=likeAveragePerCommentAcumulador/likeAveragePerCommentCounter;
        printf("El valor promedio de me gusta es: %.2f\n", average);
    }

    retorno=0;


    return retorno;
}


/**
 * \brief Imprime nombre, Nick, comentarios y likes.
 * \param el array de la estructura de usuarios
 * \param el array de la estructura de comentarios
 * \param largo del array de la estructura comments
 * \param largo del array de la estructura user
 * \return -1 Error y 0 Ok
 */

int printUserCommentList(EUser userArray[],EComments commentArray[],int commentArrayLenght,int userArrayLenght)
{
    int i,j,h,flagUserWithComment;
    EUser AuxUserArray;
    int retorno=-1;
    if(userArray!=NULL&&userArrayLenght>0&&commentArray!=NULL&&commentArrayLenght>0)
    {
        for(i=0;i<userArrayLenght-1;i++)
        {
            for(j=i+1;j<userArrayLenght;j++)
            {
                if(strcmp(userArray[i].name,userArray[j].name)<0)
                {
                    AuxUserArray=userArray[i];
                    userArray[i]=userArray[j];
                    userArray[j]=AuxUserArray;
                }
                if(strcmp(userArray[i].name,userArray[j].name)==0)
                {
                    if(strcmp(userArray[i].nickname,userArray[j].nickname)>0)
                    {
                        AuxUserArray=userArray[i];
                        userArray[i]=userArray[j];
                        userArray[j]=AuxUserArray;
                    }
                }
            }
        }
        printf("Nombre\t\t\t\tNick\t\tComentarios\t\tLikes\n");
        for(i=0;i<userArrayLenght;i++)
        {

            flagUserWithComment=0;
            for(h=0;h<commentArrayLenght;h++)
            {
                if(strcmp(userArray[i].nickname,commentArray[h].nickname)==0&&userArray[i].status==1)
                {
                    flagUserWithComment=1;
                }
            }

            if(userArray[i].status==1&&flagUserWithComment==1)
            {
                printf("_____________________________________________________________________________\n");
                printf("%10s\t\t%10s:\t\t\t\n",userArray[i].name,userArray[i].nickname);

            }
            for(j=0;j<commentArrayLenght;j++)
            {
                if(strcmp(userArray[i].nickname,commentArray[j].nickname)==0&&commentArray[j].status==1)
                {
                    printf("\t\t\t\t\t\t%20s\t%5d\n",commentArray[j].commentText,commentArray[j].likesCounter);
                }
            }
        }
        printf("_____________________________________________________________________________\n");


    }

    return retorno;
}


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
/*
int findCommentById(EUser user[], EComments comment[], int userArrayLenght, int commentArrayLenght, int auxSearch)
{
    int i;
    int retorno=-1;
    if(user!=NULL&&userArrayLenght>0&&comment!=NULL&&commentArrayLenght>0)
    {
        for(i=0;i<userArrayLenght;i++)
        {
            if(user[auxSearch].nickname==comment[i].nickname&&comment[auxSearch].status==1)
            {
                retorno=i;
                return retorno;
            }
        }
    }
    return retorno;
}

*/


/** \brief ordena la lista
 *
 * \param el array de la estructura
 * \param largo del array de la estructura
 * \return 0 si ordeno -1 si hubo error
 *
 */
 /*
int ordenarLista(EUser lista[],int length)
{
    int i,j,t,largo1,largo2;
    char auxBookTitleOne[51],auxBookTitleTwo[51];
    EUser auxLista;
    int retorno=-1;
    system("@cls||clear");
    if(lista!=NULL&&length>0)
    {
        for(i=0;i<length-1;i++)
        {
            for(j=i+1;j<length;j++)
            {
                if(lista[i].status==1&&lista[j].status==1)
                {
                    if(lista[i].authorCode<lista[j].authorCode)
                    {
                        auxLista=lista[i];
                        lista[i]=lista[j];
                        lista[j]=auxLista;
                    }
                }
            }
        }

        for(i=0;i<length-1;i++)
        {
            for(j=i+1;j<length;j++)
            {
                if(lista[i].status==1&&lista[j].status==1)
                {
                    if(lista[i].authorCode==lista[j].authorCode)
                    {
                        strcpy(auxBookTitleOne,lista[i].bookTitle);
                        strcpy(auxBookTitleTwo,lista[j].bookTitle);
                        largo1=strlen(auxBookTitleOne);
                        largo2=strlen(auxBookTitleTwo);
                        for(t=0;t<largo1; t++)
                        {
                            auxBookTitleOne[t] = tolower(auxBookTitleOne[t]);
                        }
                        for(t=0;t<largo2; t++)
                        {
                            auxBookTitleTwo[t] = tolower(auxBookTitleTwo[t]);
                        }
                        if(strcmp(auxBookTitleOne,auxBookTitleTwo)>0)
                        {
                            auxLista=lista[i];
                            lista[i]=lista[j];
                            lista[j]=auxLista;
                        }
                    }
                }
            }
        }


    }
    return retorno;
}
*/

/** \brief Imprime el array
 *
 * \param array
 * \param largo del array
 * \return 0 si no hubo error -1 si lo hubo
 *
 */
 /*
int printBookList(EUser lista[],int length)
{
    int i;
    int retorno=-1;
    if(lista!=NULL&&length>0)
    {
        system("@cls||clear");
        printf("Cod. libro\tCod. autor\tCantidad\tTitulo del libro\t\t\n");
        for(i=0;i<length;i++)
        {
            if(lista[i].status==1)
            {
                printf("%d\t\t",lista[i].bookCode);
                printf("%d\t\t",lista[i].authorCode);
                printf("%d\t\t",lista[i].bookStock);
                printf("%s\n",lista[i].bookTitle);

            }
        }
    }

    retorno = 0;
    return retorno;
}
*/

/** \brief imprime un grafico con un asterisco por persona en cada rango de edad
 *
 * \param el array de la estructura
 * \param largo del array de la estructura
 * \return 1
 *
 */
 /*
int imprimirGrafico(EPersona lista[],int length)
{
    int retorno=-1;
    int i,j,contador18Menos=0,contador19A35=0,contador35Mas=0;
    system("@cls||clear");
    if(lista!=NULL&&length>0)
    {
        for(i=0;i<length;i++) //creo contadores de cada rango de edad
        {
            if(lista[i].edad<=18&&lista[i].edad>=0&&lista[i].estado==1)
            {
                contador18Menos++;
            }
            else if(lista[i].edad>18&&lista[i].edad<=35&&lista[i].estado==1)
            {
                contador19A35++;
            }
            else if(lista[i].edad>35&&lista[i].edad<=110&&lista[i].estado==1)
            {
                contador35Mas++;
            }
        }
        for(i=0;i<length;i++) //imprimo
        {
            for(j=0;j<3;j++)
            {
                if(j==0)
                {
                    if(i>=(length-contador18Menos))
                    {
                        printf(" * \t");
                    }
                    else
                    {
                        printf("   \t");
                    }
                }
                if(j==1)
                {
                    if(i>=(length-contador19A35))
                    {
                        printf(" * \t");
                    }
                    else
                    {
                        printf("   \t");
                    }
                }
                if(j==2)
                {
                    if(i>=(length-contador35Mas))
                    {
                        printf(" * \n");
                    }
                    else
                    {
                        printf("   \n");
                    }
                }
            }
    }
    printf("<18\t19-35\t>35\t\n");
    retorno=0;
    }
    return retorno;
}

*/



/** \brief ordena por dos parametros la lista de libros
 *
 * \param array de la estructura
 * \param longitud del array
 * \return -1 Error 0 Ok
 *
 */
 /*
int menorMayor(EUser lista[],int length)
{
    int  i;
    int menor, mayor,indiceMenor,indiceMayor;
    int retorno=-1;
    if(lista!=NULL&&length>0)
    {
        for(i=0;i<length;i++)
        {
            if(lista[i].status==1)
            {
                menor=lista[i].bookStock;
                mayor=lista[i].bookStock;
                break;
            }
        }
        for(i=0;i<length;i++)
        {
            if(lista[i].bookStock<menor&&lista[i].status==1)
            {
                menor=lista[i].bookStock;
                indiceMenor=i;
            }
            if(lista[i].bookStock>mayor&&lista[i].status==1)
            {
                mayor=lista[i].bookStock;
                indiceMayor=i;
            }
        }
        system("@cls||clear");
        printf("Menor cantidad:\n");
        printf("Cod.Libro\tCod.Autor\tCantidad\tTitulo del libro\n");
        printf("%d\t\t",lista[indiceMenor].bookCode);
        printf("%d\t\t",lista[indiceMenor].authorCode);
        printf("%d\t\t",lista[indiceMenor].bookStock);
        printf("%s\n",lista[indiceMenor].bookTitle);
        printf("Mayor bookStock:\n");
        printf("Cod.Libro\tCod.Autor\tCantidad\tTitulo del libro\n");
        printf("%d\t\t",lista[indiceMayor].bookCode);
        printf("%d\t\t",lista[indiceMayor].authorCode);
        printf("%d\t\t",lista[indiceMayor].bookStock);
        printf("%s\n",lista[indiceMayor].bookTitle);
        retorno=0;
    }
    return retorno;
}
*/
/*
int printAuthorList(EComments lista[],int length)
{
    {
    int i;
    int retorno=-1;
    if(lista!=NULL&&length>0)
    {
        system("@cls||clear");
        printf("Cod. autor\tDescripcion Autor\t\t\n");
        for(i=0;i<length;i++)
        {
            if(lista[i].status==1)
            {
                printf("%d\t\t",lista[i].authorCode);
                printf("%s\n",lista[i].authorDescription);

            }
        }
    }

    retorno = 0;
    return retorno;
}



}
*/

