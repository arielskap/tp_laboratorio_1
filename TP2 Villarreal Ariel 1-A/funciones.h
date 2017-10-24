#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    char nombre[50];
    int edad;
    int dni;
    int estado;
} ePersona;

void variablesCero(ePersona lista[],int i);
/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 *@param Inicializa todos los parametros de la escructura en 0.
 */

void inicializarvector(ePersona lista[],int tam);
/**
 *  Obtiene el indice que coincide con el dni pasado por parametro.
 *  @param utliza VariablesCero y lo repite por la cantidad de estructuras.
 */
int buscarLibre(ePersona lista[],int tam);
/**
 *  Obtiene el indice que coincide con el dni pasado por parametro.
 *  @param Busca espacio.
 */
int buscarPersona(int dni, ePersona lista[],int tam);
/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 *  @param Busca el DNI.
 */
void altaPersona(ePersona lista[],int tam);
/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 *  @param Da valores a los parametros de la estructura ePersona y pone su estado en 1.
  */

void mostrarPersona(ePersona lista);
/**
* @param Muestra los datos de una persona.
 */

void bajaPersona(ePersona lista[], int tam);
/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 *  @param Deja una estructura en estado 0. Lo que la da de "baja".
  */

void organizarpersonas(ePersona lista[],int tam);
/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param Ordena las personas por orden alfabetico y las muestra mediante mostrarPersona.
  */

void organizaredades (ePersona lista[],int tam);
/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 *@param Cuanta la cantidad de personas ingresadas segun du edad: menores de 18, entre 18 y 35 y mayores de 35.
 *@param Las grafica segun la edad que pertenezca.
  */
#endif // FUNCIONES_H_INCLUDED
