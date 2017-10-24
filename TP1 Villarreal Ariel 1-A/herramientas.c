#include <stdio.h>
#include <stdlib.h>

float pedirnumero(char mensaje[])
{
    float numero;
    printf("%s",mensaje);
    scanf("%f",&numero);
    fflush(stdin);
    return numero;
}

int suma(float a, float b)
{
    printf("La suma es: %f\n\n",a+b);
    return 0;
}

int resta(float a, float b)
{
    printf("La resta es: %f\n\n",a-b);
    return 0;
}

int division(float a, float b)
{
    if (a==0 || b==0)
    {
        printf("No se puede dividir por cero\n\n");
    }
    else
    {
        printf("La division es: %f\n\n",(float)a/b);
    }
    return 0;
}

int multiplicacion(float a, float b)
{
    printf("La multiplicacion es: %f\n\n",a*b);
    return 0;
}

int factor(float a)
{
    int b;
    float factoreo=1;
    for(b=a;b>1;b--)
        {
            factoreo=factoreo*b;
        }
    printf("El factorial es: %f\n\n",factoreo);
    return 0;
}
