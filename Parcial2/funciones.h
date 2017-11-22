
typedef struct
{

    char nombre[50];
    char correo [50];

}eClientes;

int menu ();
int parsearArchivo (ArrayList* lista);
ArrayList* compararString (ArrayList* lista, ArrayList* auxListanegra);
int lee_archivo_cliente(ArrayList* lista);
void mostrar_clientes(ArrayList* lista);
void mostrar_un_cliente(eClientes* returnAux);
