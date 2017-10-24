#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"
#define TAM 20
void variablesCero(ePersona lista[],int i)
{
    strcpy(lista[i].nombre,"\0");
    lista[i].edad=0;
    lista[i].estado=0;
    lista[i].dni=0;
}

void inicializarvector(ePersona lista[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        variablesCero(lista,i);
    }
}

int buscarLibre(ePersona lista[],int tam)
{
    int indice=-1;
    for(int i=0; i<tam; i++)
    {
        if(lista[i].estado==0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

int buscarPersona(int dni, ePersona lista[],int tam)
{
    int indice=-1;
    for(int i=0; i<tam; i++)
    {
        if(lista[i].dni==dni&&lista[i].estado==1)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

void altaPersona(ePersona lista[],int tam)
{
    system("cls");
    printf("Opcion 1");
    ePersona nuevaPersona;
    int lugar;
    int dni;
    int esta;
    lugar=buscarLibre(lista,tam);
    if(lugar==-1)
    {
        printf("\nNo hay lugar en el sistema.\n");
        system("pause");
    }
    else
    {
        printf("\nIngrese DNI: ");
        fflush(stdin);
        scanf("%d",&dni);
        esta=buscarPersona(dni,lista,tam);
        if(esta!=-1)
        {
            printf("\nEl DNI: %d ya se encuentra registrado en el sistema. \n",dni);
            system("pause");
        }
        else
        {
            nuevaPersona.dni=dni;
            printf("\nIngrese nombre: ");
            fflush(stdin);
            gets(nuevaPersona.nombre);
            printf("\nIngrese edad: ");
            fflush(stdin);
            scanf("%d",&nuevaPersona.edad);
            nuevaPersona.estado=1;
            lista[lugar]=nuevaPersona;
            system("pause");
        }
    }
    system("cls");
}

void mostrarPersona(ePersona lista)
{
    printf("\nDNI: %d----Nombre: %s----Edad: %d\n",lista.dni,lista.nombre,lista.edad);
}

void bajaPersona(ePersona lista[], int tam)
{
    system("cls");
    printf("Opcion 2");
    int dni;
    int indice;
    char confirma;
    printf("\nIngrese dni: ");
    scanf("%d",&dni);
    indice=buscarPersona(dni,lista,tam);
    if(indice!=-1)
    {
        mostrarPersona(lista[indice]);
        printf("\nConfirma la baja? s/n: ");
        fflush(stdin);
        confirma=getchar();
        if(confirma=='s')
        {
            lista[indice].estado=0;
            printf("\nPersona Eliminada\n");
            system("pause");
        }
        else
        {
            printf("\nBaja cancelada por el usuario\n");
            system("pause");
        }
    }
    else
    {
        printf("\nDNI no encontrada.\n");
        system("pause");
    }
    system("cls");
}

void organizarpersonas(ePersona lista[],int tam)
{
    system("cls");
    printf("Opcion 3");
    int i, j;
    int auxint;
    char auxstring[20];
    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(lista[i].estado==1 && lista[j].estado==1)
            {
                if(strcmp(lista[i].nombre,lista[j].nombre)>0)
                {
                    strcpy(auxstring,lista[i].nombre);
                    strcpy(lista[i].nombre, lista[j].nombre);
                    strcpy(lista[j].nombre, auxstring);
                    auxint=lista[i].dni;
                    lista[i].dni=lista[j].dni;
                    lista[j].dni=auxint;
                    auxint=lista[i].edad;
                    lista[i].edad=lista[j].edad;
                    lista[j].edad=auxint;
                    auxint=lista[i].estado;
                    lista[i].estado=lista[j].estado;
                    lista[j].estado=auxint;
                }
                else
                {
                    if(strcmp(lista[i].nombre, lista[j].nombre)==0)
                    {
                        if(lista[i].dni>lista[j].dni)
                        {
                            auxint=lista[i].dni;
                            lista[i].dni=lista[j].dni;
                            lista[j].dni=auxint;
                            auxint=lista[i].edad;
                            lista[i].edad=lista[j].edad;
                            lista[j].edad=auxint;
                            auxint=lista[i].estado;
                            lista[i].estado=lista[j].estado;
                            lista[j].estado=auxint;
                        }
                    }
                }
            }
        }
    }
    printf("\nDatos de las personas registradas:\n\n");
    for(i=0; i<20; i++)
    {
        if(lista[i].estado!=0)
        {
            mostrarPersona(lista[i]);
        }
    }
    system("pause");
    system("cls");
}

void organizaredades (ePersona lista[],int tam)
{
    system("cls");
    printf("Opcion 4\n");
    int edades;
    int contadormenor18=0;
    int contador18y35=0;
    int contadormas35=0;
    int barramasgrande;
    for(int i=0; i<tam; i++)
    {
        edades=lista[i].edad;
        if(edades<18 && edades>0)
        {
            contadormenor18++;
        }
        else
        {
            if(edades>=18 && edades<=35)
            {
                contador18y35++;
            }
            else
            {
                if(edades==0)
                {
                }
                else
                {
                    contadormas35++;
                }
            }
        }
    }
    if(contadormenor18>=contador18y35 && contadormenor18>=contadormas35)
    {
        barramasgrande=contadormenor18;
    }
    else
    {
        if(contador18y35>=contadormenor18 && contador18y35>=contadormas35)
        {
            barramasgrande=contador18y35;
        }
        else
        {
            barramasgrande=contadormas35;
        }
    }
    for(int i=barramasgrande; i>0; i--)
    {
        if(i<=contadormenor18 && i>contador18y35 && i>contadormas35)
        {
            printf("*\n");
        }
        if(i<=contadormenor18 && i<=contador18y35 && i>contadormas35)
        {
            printf("*\t*\n");
        }
        if(i<=contadormenor18 && i>contador18y35 && i<=contadormas35)
        {
            printf("*\t\t*\n");
        }
        if(i>contadormenor18 && i<=contador18y35 && i>contadormas35)
        {
            printf("\t*\n");
        }
        if(i>contadormenor18 && i<=contador18y35 && i<=contadormas35)
        {
            printf("\t*\t*\n");
        }
        if(i>contadormenor18 && i>contador18y35 && i<=contadormas35)
        {
            printf("\t\t*\n");
        }
        if(i<=contadormenor18 && i<=contador18y35 && i<=contadormas35)
        {
            printf("*\t*\t*\n");
        }
    }
    printf("\n%d\t%d\t%d\n",contadormenor18,contador18y35,contadormas35);
    printf("<18\t18<>35\t>35\n");
    system("pause");
    system("cls");
}
