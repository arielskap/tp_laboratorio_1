#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"
#include "funciones.h"
#include <string.h>
void mostrar_un_cliente(eClientes* returnAux)
{
    printf("Nombre: %s, Correo: %s\n",returnAux->nombre,returnAux->correo);
}

void mostrar_clientes(ArrayList* lista)
{
    int i, flag=0;
    eClientes* aux=NULL;

    for(i=0; i<lista->size; i++)
    {
        aux = (eClientes*) lista->get(lista,i);
        mostrar_un_cliente(aux);
        flag=1;
    }
    if(flag==0)
    {
        printf("No hay nada para mostrar");
    }
}
int lee_archivo_cliente(ArrayList* lista)
{

    FILE* archivo=NULL;
    eClientes* returnAux;
    char auxNombre[100];
    char auxCorreo[200];
    char nombrearchivo[50];
    int salida=-1;
    printf("Ingrese nombre del Archivo: ");
    fflush(stdin);
    gets(nombrearchivo);
    archivo = fopen(nombrearchivo,"r");
    if(archivo!= NULL && lista != NULL)
    {
        while(!feof(archivo))
        {
            fflush(stdin);
            fscanf(archivo,"%[^,],%[^\n]",auxNombre,auxCorreo);
            returnAux = (eClientes*) malloc(sizeof(eClientes));
            if(feof(archivo))
            {
                break;
            }
            else
            {
                if(returnAux!=NULL)
                {
                    strcpy(returnAux->nombre,auxNombre);
                    strcpy(returnAux->correo,auxCorreo);
                    lista->add(lista,returnAux);
                    salida=0;
                }
            }
        }
        if(salida==0)
        {
            system("color 02");
            printf("Cargado con exito!!\n\n");
            system("pause");
        }
    }
    else
    {
        printf("ERROR; No se pudo abrir el archivo");
        exit(1);
    }
    fclose(archivo);
    return salida;
}
int menu()
{
    int respuesta;

    printf("1- Cargar Destinatarios.\n");
    printf("2- Cargar Lista Negra.\n");
    printf("3- Depurar.\n");
    printf("4- Listar\n");
    printf("5- Salir\n");
    printf("Respuesta : ");

    scanf("%d",&respuesta);

    return respuesta;
}

ArrayList* compararString (ArrayList* lista, ArrayList* auxListanegra)
{
    int i,j;
    eClientes* cliente;

    eClientes*  clienteNegro;
    ArrayList* nuevalista;
    nuevalista = al_newArrayList();
    if(nuevalista!=NULL)
    {
        nuevalista=nuevalista->clone(lista);

        if(nuevalista!=NULL)
        {
            for (i=0; i<auxListanegra->size; i++)
            {
                clienteNegro=(eClientes*)auxListanegra->get(auxListanegra,i);
                for(j=0; j<nuevalista->size; j++)
                {
                    cliente = (eClientes*)nuevalista->get(nuevalista,j);
                    if (strcmp(cliente->nombre,clienteNegro->nombre) == 0 &&strcmp(cliente->correo,clienteNegro->correo)==0)
                    {
                        nuevalista->remove(nuevalista,j);
                    }
                }
            }
        }
    }
    else
    {
        printf("\nERROR AL CREAR NUEVA LISTA\n");
    }
    return nuevalista;
}

