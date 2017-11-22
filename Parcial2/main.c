#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"
#include "funciones.h"
int main()
{
    int salir = 0;
    int validarLista;
    int validarListaNegra;
    ArrayList* lista;
    ArrayList* auxListanegra;
    ArrayList* auxSinListaNegra;
    lista=al_newArrayList();
    auxListanegra=al_newArrayList();
    do
    {
        system("cls");
        system("color 07");
        switch (menu())
        {
        case 1:
            printf("ESTAS CARGANDO LA LISTA\n\n");
            system("cls");
            validarLista=lee_archivo_cliente(lista);
            break;
        case 2:
            printf("ESTAS CARGANDO LA LISTA NEGRA\n\n");
            system("cls");
            validarListaNegra=lee_archivo_cliente(auxListanegra);
            break;
        case 3:
            if(validarLista==0&&validarListaNegra==0)
            {
            auxSinListaNegra=compararString(lista,auxListanegra);
            }
            else
            {
                printf("No se cargo las dos listas!\n");
            }
            system("pause");
            break;
        case 4:
             if(validarLista==0&&validarListaNegra==0)
            {
               /* int z;
                eClientes* cliente2;
                for(z=0; z<auxSinListaNegra->size; z++)
        {
            cliente2 = (eClientes*)auxSinListaNegra->get(auxSinListaNegra,z);
            printf("%s",cliente2->nombre);
        }*/
            mostrar_clientes(auxSinListaNegra);
            }
            else
            {
                printf("No se cargo las dos listas!\n");
            }
            system("pause");
            break;
        case 5:
            salir = 1;
            break;
        default:
            printf("Opcion invalida.\n");
        }
    }
    while (salir == 0);

    return 0;
}

