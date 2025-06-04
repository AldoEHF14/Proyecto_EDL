/*Proyecto Final*/
/*Integrantes
1.Aldo Enrique Hernandez Flores
2.Bryan Alexander Gomez Miranda
*/
/*Prototipos y/o funciones*/
/*Estructuras principales*/

typedef struct Alimento
{
    char Tipo_de_Alimento[100];
    char Nombre_de_Alimento[100];
    int Precio_compra;
    int fecha_compraD;
    int fecha_compraM;
    int fecha_compraA;
    int fecha_caducidadD;
    int fecha_caducidadM;
    int fecha_caducidadA;
    int estatus_disponibilidad;
} Alimento;

typedef struct Nodo
{
    Alimento *datos;
    struct Nodo *sig;
} Nodo;

typedef struct ListaS
{
    Nodo *cabeza;
} ListaS;

Alimento *crear_Alimento(char TIPO_DE_ALIMENTO[100], char NOMBRE_DE_ALIMENTO[100], int PRECIO_COMPRA, int FECHA_COMPRAD, int FECHA_COMPRAM, int FECHA_COMPRAA, int FECHA_CADUCIDADD, int FECHA_CADUCIDADM, int FECHA_CADUCIDADA, int ESTATUS_DISPONIBLES);
Nodo *crear_Nodo(Alimento *Alimento);
ListaS *crear_ListaS();
int isEmpty(ListaS lista);
void insertar_cabeza(ListaS *lista, Nodo *aux);
void insertar_cola(ListaS *lista, Nodo *aux);
void insertar_enmedio(ListaS *lista, Nodo *anterior, Nodo *elemento);
void quitar_cabeza(ListaS *lista);
void quitar_cola(ListaS *lista);
void quitar_enmedio(ListaS *lista, Nodo *elemento);
int vaciarLista(ListaS *lista);
int printLista(ListaS *lista);
void Agregar_categoria(ListaS *lista, char tipoAlimento[100]);
Nodo *busqueda_binaria_iterativa(ListaS *lista, Nodo *elemento);
Nodo *busqueda_binaria_recursiva(ListaS *lista, int inferior, int superior, Nodo *elemento);
void Ordenamiento_Burbuja(ListaS *lista);
void quickSort(ListaS *listad, int inicio, int final);
int Alimentos(ListaS *lista, char tipo[50]);
