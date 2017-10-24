#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"
#define TAM 20
int main()
{
    char seguir='s';
    int opcion=0;
    ePersona equipo[TAM];
    inicializarvector(equipo,TAM);
    while(seguir=='s')
    {
        printf("\nOPCIONES: \n\n");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");
        printf("\nIngrese Opcion: ");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            altaPersona(equipo,TAM);
            break;
        case 2:
            bajaPersona(equipo,TAM);
            break;
        case 3:
            organizarpersonas(equipo,TAM);
            break;
        case 4:
            organizaredades (equipo,TAM);
            break;
        case 5:
            seguir = 'n';
            system("cls");
            printf("CHAU!!!\n");
            break;
        default:
            system("cls");
            printf("OPCION INVALIDA!!!!\n\n");
            system("pause");
            system("cls");
            break;
        }
    }

    return 0;
}
