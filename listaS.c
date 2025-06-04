/*Proyecto Final*/
/*Integrantes
1.Aldo Enrique Hernandez Flores
2.Bryan Alexander Gomez Miranda
*/
/*Librerias*/
#include "listaS.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Funciones y/o procedimientos*/
Alimento *crear_Alimento(char TIPO_DE_ALIMENTO[100], char NOMBRE_DE_ALIMENTO[100], int PRECIO_COMPRA, int FECHA_COMPRAD, int FECHA_COMPRAM, int FECHA_COMPRAA, int FECHA_CADUCIDADD, int FECHA_CADUCIDADM, int FECHA_CADUCIDADA, int ESTATUS_DISPONIBLES)
{

    Alimento *aux = (Alimento *)malloc(sizeof(Alimento));

    strcpy(aux->Tipo_de_Alimento, TIPO_DE_ALIMENTO);
    strcpy(aux->Nombre_de_Alimento, NOMBRE_DE_ALIMENTO);
    aux->Precio_compra = PRECIO_COMPRA;
    aux->fecha_compraD = FECHA_COMPRAD;
    aux->fecha_compraM = FECHA_COMPRAM;
    aux->fecha_compraA = FECHA_COMPRAA;
    aux->fecha_caducidadD = FECHA_CADUCIDADD;
    aux->fecha_caducidadM = FECHA_CADUCIDADM;
    aux->fecha_caducidadA = FECHA_CADUCIDADA;
    aux->estatus_disponibilidad = ESTATUS_DISPONIBLES;

    return (aux);
}

Nodo *crear_Nodo(Alimento *Alimento)// Se crea el nodo con el Alimento dentro
{ 
    Nodo *aux = (Nodo *)malloc(sizeof(Nodo));
    aux->datos = Alimento;
    aux->sig = NULL;
    return (aux);
}

ListaS *crear_ListaS()// se crea las listas con los nodos dentro
{ 
    ListaS *aux = (ListaS *)malloc(sizeof(ListaS));
    aux->cabeza = NULL;
    return (aux);
}

int isEmpty(ListaS lista) // verifica que la lista no este vacia
{ 
    if (lista.cabeza == NULL)
    {
        return (1);
    }
    else
    {
        return (0);
    }
}

void insertar_cabeza(ListaS *lista, Nodo *aux) // inserta cabeza en la lista
{ 
    if (isEmpty(*lista) == 1)
    {
        lista->cabeza = aux;
    }
    else
    {
        aux->sig = lista->cabeza;
        lista->cabeza = aux;
    }
}

void insertar_cola(ListaS *lista, Nodo *aux) // inserta cola en la lista
{ 
    Nodo *cola;
    cola = lista->cabeza;
    if (isEmpty(*lista) == 1)
    {
        insertar_cabeza(lista, aux);
    }
    else
    {
        while (cola->sig != NULL)
        {
            cola = cola->sig;
        }
        cola->sig = aux;
        cola = aux;
    }
}

void insertar_enmedio(ListaS *lista, Nodo *anterior, Nodo *aux) // inserta nodos en medio
{ 
    if (isEmpty(*lista) == 1)
    {
        lista->cabeza = aux;
    }
    else
    {
        aux->sig = anterior->sig;
        anterior->sig = aux;
    }
}

void quitar_cabeza(ListaS *lista) // quita la cabeza de la lista
{ 
    Nodo *aux = NULL;
    if (!isEmpty(*lista))
    {
        aux = lista->cabeza;
        lista->cabeza = lista->cabeza->sig;
        free(aux);
    }
    else
    {
    }
}

void quitar_cola(ListaS *lista) // quita la cola de la lista
{ 
    Nodo *cola;
    Nodo *anterior;
    if (isEmpty(*lista) == 1)
    {
    }
    else
    {
        if (lista->cabeza->sig == NULL)
        {
            lista->cabeza = NULL;
        }
        else
        {
            cola = lista->cabeza;
            while (cola->sig != NULL)
            {
                anterior = cola;
                cola = cola->sig;
            }
            anterior->sig = NULL;
            free(cola);
        }
    }
}

void quitar_enmedio(ListaS *lista, Nodo *elemento) // quita el nodo de enmedio 
{ 
    Nodo *anterior;
    Nodo *borrar;
    if (isEmpty(*lista) == 1)
    {
        printf("\nLa lista esta vacia.\n");
    }
    else
    {
        borrar = busqueda_binaria_iterativa(lista, elemento);
        if (borrar == NULL)
        {
            printf("\nEl Alimento con el precio = %d no se encuentra en la lista.\n", elemento->datos->Precio_compra);
        }
        else
        {
            if (lista->cabeza == borrar)
            {
                printf("\nSe a eliminado el Alimento.\n");
                printf("\nNombre = %s", borrar->datos->Nombre_de_Alimento);
                printf("\nPrecio Compra = %d", borrar->datos->Precio_compra);
                printf("\nEstatus = %d", borrar->datos->estatus_disponibilidad);
                quitar_cabeza(lista);
            }
            else
            {
                anterior = lista->cabeza;
                while (anterior->sig != borrar)
                {
                    anterior = anterior->sig;
                }
                printf("\nSe a eliminado el Alimento.\n");
                printf("\nNombre = %s", borrar->datos->Nombre_de_Alimento);
                printf("\nPrecio Compra = %d", borrar->datos->Precio_compra);
                printf("\nEstatus = %d", borrar->datos->estatus_disponibilidad);
                anterior->sig = borrar->sig;
                free(borrar);
            }
        }
    }
}

Nodo *busqueda_binaria_recursiva(ListaS *lista, int inferior, int superior, Nodo *elemento) //Busca nodos de manera recursiva
{
    Nodo *aux = lista->cabeza;
    Nodo *aux2 = lista->cabeza;
    Alimento *alu;
    int central;
    int i, j;
    int tr = 0;
    int reco = 0;
    if (!isEmpty(*lista))
    {

        if (inferior > superior)
        {
            return (NULL);
        }
        else
        {
            reco = 0;
            aux2 = lista->cabeza;
            central = (inferior + superior) / 2;

            while (reco < central && aux2->sig != NULL)
            {
                aux2 = aux2->sig;
                reco++;
            }

            alu = aux2->datos;

            if (elemento->datos->Precio_compra == alu->Precio_compra)
            {
                printf("\n El Nombre del Alimento %s se encuentra en la posicion %d", aux2->datos->Nombre_de_Alimento, central);
                return (aux2);
                tr = 0;
            }
            else if (elemento->datos->Precio_compra < alu->Precio_compra)
            {
                return busqueda_binaria_recursiva(lista, inferior, central - 1, elemento);
            }
            else
            {
                return busqueda_binaria_recursiva(lista, central + 1, superior, elemento);
            }
        }
    }
    else
    {
        printf("\n EL ELEMENTO NO SE ENCUENTRA LA LISTA NO TIENE NADA. \n");
        return (NULL);
    }
}

Nodo *busqueda_binaria_iterativa(ListaS *lista, Nodo *elemento) //Busca nodos de manera iterativa
{
    Nodo *aux = lista->cabeza;
    Nodo *aux1 = lista->cabeza;
    Alimento *valorCentral;

    int alto = 0, bajo = 0, central = 0;
    int tr = 1;
    if (!isEmpty(*lista))
    {
        while (aux->sig != NULL)
        {
            aux = aux->sig;
            alto++;
        }
        alto++;
        int reco = 0;
        while (bajo <= alto)
        {
            central = (bajo + alto) / 2;

            reco = 0;
            aux1 = lista->cabeza;
            while (reco < central && aux1->sig != NULL)
            {
                aux1 = aux1->sig;
                reco++;
            }
            valorCentral = aux1->datos;

            if (elemento->datos->Precio_compra == valorCentral->Precio_compra)
            {
                printf("\nEl Precio del Alimento %d se encuentra en la posicion %d\n", aux1->datos->Precio_compra, central);
                return (aux1);
                tr = 0;
                break;
            }
            else if (elemento->datos->Precio_compra < valorCentral->Precio_compra)
            {
                alto = central - 1;
            }
            else
            {
                bajo = central + 1;
            }
        }

        if (tr == 1)
        {
            return NULL;
        }
    }
    else
    {
        return NULL;
    }
}

int vaciarLista(ListaS *lista) // vacia el contenido de la lista
{ 
    Nodo *aux = lista->cabeza;
    if (isEmpty(*lista) != 1)
    {
        while (aux != NULL)
        {
            aux = aux->sig;
            quitar_cabeza(lista);
        }
        return (0);
    }
    else
    {
        return (1);
    }
    free(aux);
}

int printLista(ListaS *lista) // imprime todo el contenido de la lista y regresa el numero de elementos
{ 
    Nodo *aux = lista->cabeza;
    Alimento *ali;
    int i = 0;
    if (isEmpty(*lista) != 1)
    {
        while (aux != NULL)
        {
            ali = aux->datos;
            printf("\n Tipo de Alimento: %s", ali->Tipo_de_Alimento);
            printf("\n Nombre del Alimento: %s", ali->Nombre_de_Alimento);
            printf("\n Precio Compra: %d", ali->Precio_compra);
            printf("\n Fecha Compra: %d/%d/%d", ali->fecha_compraD, ali->fecha_compraM, ali->fecha_compraA);
            printf("\n Fecha Caducidad: %d/%d/%d", ali->fecha_caducidadD, ali->fecha_caducidadM, ali->fecha_caducidadA);
            printf("\n Estatus Disponibilidad: %d", ali->estatus_disponibilidad);
            printf("\n");
            aux = aux->sig;
        }
    }
    else
    {
        printf("\n LISTA SIN NADA \n");
    }
    return i;
}

void Agregar_categoria(ListaS *lista, char tipoAlimento[100]) //agrega elementos a la lista correspondiente
{
    int Preciocompra;
    char fechacompra[100];
    char fechacaducidad[100];
    int fecha_compraD;
    int fecha_compraM;
    int fecha_compraA;
    int fecha_caducidadD;
    int fecha_caducidadM;
    int fecha_caducidadA;
    int estatusdisponibilidad;
    char NombreAlimento[100];

    printf("\n- Ingresa el nombre de el/la %s\n", tipoAlimento);
    scanf("%*c%[^\n]", NombreAlimento);
    printf("\n- Ingresa el precio de compra del Alimento\n");
    scanf("%d", &Preciocompra);
    printf("\n- Ingresa la fecha de compra del Alimento\n");
    printf("DIA: ");
    scanf("%d", &fecha_compraD);
    printf("MES: ");
    scanf("%d", &fecha_compraM);
    printf("ANIO: ");
    scanf("%d", &fecha_compraA);
    printf("\n- Ingresa la fecha de caducidad del Alimento\n");
    printf("DIA: ");
    scanf("%d", &fecha_caducidadD);
    printf("MES: ");
    scanf("%d", &fecha_caducidadM);
    printf("ANIO: ");
    scanf("%d", &fecha_caducidadA);
    while (fecha_compraA >= fecha_caducidadA && fecha_compraM >= fecha_caducidadM && fecha_compraD >= fecha_caducidadD)
    {
        printf("\n- Ya caduco tu alimento, ingresa una nueva fecha\n");
        printf("DIA: ");
        scanf("%d", &fecha_caducidadD);
        printf("MES: ");
        scanf("%d", &fecha_caducidadM);
        printf("ANIO: ");
        scanf("%d", &fecha_caducidadA);
    }
    printf("\n- Ingresa El estatus de disponibilidad\n");
    printf("\n\t 0 / no disponible\n");
    printf("\n\t 1 / disponible\n");
    scanf("%d", &estatusdisponibilidad);
    while ((estatusdisponibilidad != 1) && (estatusdisponibilidad != 0))
    {
        printf("\n- El estatus de disponibilidad solo debe ser 1 o 0\n");
        printf("\n\t 0 / no disponible\n");
        printf("\n\t 1 / disponible\n");
        scanf("%d", &estatusdisponibilidad);
    }
    insertar_cola(lista, crear_Nodo(crear_Alimento(tipoAlimento, NombreAlimento, Preciocompra, fecha_compraD, fecha_compraM, fecha_compraA, fecha_caducidadD, fecha_caducidadM, fecha_caducidadA, estatusdisponibilidad)));
}

void Ordenamiento_Burbuja(ListaS *lista) //ordena usando algoritmo burbuja
{
    Nodo *aux = lista->cabeza;
    Nodo *aux1;
    int longitud = 0;
    int interruptor = 1;
    int pasada, j;
    if (!isEmpty(*lista))
    {
        while (aux->sig != NULL)
        {
            aux = aux->sig;
            longitud++;
        }
        longitud++;

        for (int i = 0; i < longitud; i++)
        {
            aux1 = lista->cabeza;

            for (j = 0; j < longitud - 1 - i; j++)
            {
                Nodo *aux2 = aux1->sig;
                if (aux1->datos->Precio_compra > aux2->datos->Precio_compra)
                {
                    Alimento *aux3;
                    aux3 = aux1->datos;
                    aux1->datos = aux2->datos;
                    aux2->datos = aux3;
                }
                aux1 = aux1->sig;
            }
        }

        printLista(lista);
    }
    else
    {
        printf("\n La lista esta vacia \n");
    }
}

void quickSort(ListaS *listad, int inicio, int final) //ordena usando algoritmo quicksort
{
    int izq = inicio; 
    int der = final;  
    int piv = (izq + der) / 2;
    Nodo *pivote = listad->cabeza;
    int ini2 = 0;
    while (ini2 < piv)
    {
        pivote = pivote->sig;
        ini2++;
    }

    Nodo *auxI = listad->cabeza;
    ini2 = 0;
    while (ini2 < izq)
    {
        auxI = auxI->sig;
        ini2++;
    }
    Nodo *auxD = listad->cabeza;
    ini2 = 0;
    while (ini2 < der)
    {
        auxD = auxD->sig;
        ini2++;
    }
    do
    {
        while ((auxI->datos->Precio_compra < pivote->datos->Precio_compra) && (izq < final))
        {
            izq++;
            auxI = listad->cabeza;
            ini2 = 0;
            while (ini2 < izq)
            {
                auxI = auxI->sig;
                ini2++;
            }
        }

        while ((pivote->datos->Precio_compra < auxD->datos->Precio_compra) && (der > inicio))
        {
            der--;
            auxD = listad->cabeza;
            ini2 = 0;
            while (ini2 < der)
            {
                auxD = auxD->sig;
                ini2++;
            }
        }

        if (izq <= der)
        {
            Alimento *temporal = auxI->datos;
            auxI->datos = auxD->datos;
            auxD->datos = temporal;
            izq++;
            der--;
            auxD = listad->cabeza;
            ini2 = 0;
            while (ini2 < der)
            {
                auxD = auxD->sig;
                ini2++;
            }

            while (ini2 < izq)
            {
                auxI = auxI->sig;
                ini2++;
            }
            temporal = NULL;
        }
    } while (izq <= der);

    if (inicio < der)
        quickSort(listad, inicio, der);

    if (final > izq)
        quickSort(listad, izq, final);
}

int Alimentos(ListaS *Lista, char tipo[50]) // menu del alimento correspondiente
{
    system("cls||clear");
    int option = 1, opcion2 = 1, otro = 0, aux = 0;
    char nombre;
    Nodo *ele1;
    Nodo *aux1;
    printf("\n\t Estas en la seccion de %s   \n", tipo);
    printf("\n\t Que deseas hacer: \n");
    printf("\n\t1- Ingresa un/una %s\n", tipo);
    printf("\n\t2- Quita un/una %s\n", tipo);
    printf("\n\t3- Mostrar la lista de %s\n", tipo);
    printf("\n\t4- Buscar un/una %s \n", tipo);
    printf("\n\t5- Ordenar %s por precio\n", tipo);
    printf("\n\t6- Vaciar lista de %s\n", tipo);
    printf("\n\t7- Salir\n");
    printf("\n\t Dime el numero de lo que quieres hacer:  \n");
    scanf("%d", &opcion2);
    switch (opcion2)
    {

    case 1: // crea los nodos y agrega nuevos bebidas a la lista principal.
    {
        do
        {
            system("cls||clear");
            Agregar_categoria(Lista, tipo);

            printf("\n\t- ¿Desea ingresar otra/otro %s?\n", tipo);
            printf("\n\t- 1 / Si\n");
            printf("\n\t- 2 / No\n");
            scanf("%d", &otro);
        } while (otro != 2);
        return (opcion2);
        break;
    }
    case 2: // Quita una bebida
    {
        do
        {
            system("cls||clear");
            int precio = 0;
            printf("\nIngresa el precio de el/la %s: ", tipo);
            scanf("%d", &precio);
            ele1 = crear_Nodo(crear_Alimento(tipo, "", precio, 0, 0, 0, 0, 0, 0, 1));
            quitar_enmedio(Lista, ele1);
            printf("\n\t- ¿Desea regresar al menu principal?\n");
            printf("\n\t- 1 / Si\n");
            printf("\n\t- 2 / No\n");
            scanf("%d", &otro);
        } while (otro != 1);
        return (opcion2);
        break;
    }
    case 3: // Imprime la lista de bebidas
    {
        do
        {
            system("cls||clear");
            printLista(Lista);
            printf("\n\t- ¿Desea regresar al menu principal?\n");
            printf("\n\t- 1 / Si\n");
            printf("\n\t- 2 / No\n");
            scanf("%d", &otro);
        } while (otro != 1);
        return (opcion2);
        break;
    }
    case 4: // Busca usando la binaria recursiva o iterativa
    {

        do
        {
            system("cls||clear");
            ListaS *SubLista;
            SubLista = crear_ListaS();
            vaciarLista(SubLista);
            Alimento *aul;
            int medida = 0;
            Nodo *tamano = Lista->cabeza;
            int precio = 0, inicio = 0, binaria = 0;
            printf("\nIngresa el precio de  el/la %s: ", tipo);
            scanf("%d", &precio);

            if (!isEmpty(*Lista))
            {

                while (tamano->sig != NULL)
                {
                    tamano = tamano->sig;
                    medida++;
                }
                medida++;
                ele1 = crear_Nodo(crear_Alimento(tipo, "", precio, 0, 0, 0, 0, 0, 0, 1));
                printf("\n Elije que metodo deseas utilizar para realizar tu busqueda  \n");
                printf("\n 1.-binaria recursiva  \n");
                printf("\n 2.-binaria iterativa  \n");
                scanf("%d", &binaria);
                while ((binaria != 1) && (binaria != 2))
                {
                    system("cls||clear");
                    printf("\n- Eleccion invalida\n");
                    printf("\n 1.-binaria recursiva  \n");
                    printf("\n 2.-binaria iterativa  \n");
                    scanf("%d", &binaria);
                }

                switch (binaria)
                {
                case 1:
                {
                    system("cls||clear");
                    aux1 = busqueda_binaria_recursiva(Lista, inicio, medida, ele1);
                    break;
                }
                case 2:
                {
                    system("cls||clear");
                    aux1 = busqueda_binaria_iterativa(Lista, ele1);
                    break;
                }
                }

                if (aux1 != NULL)
                {
                    tamano = Lista->cabeza;
                    while (tamano != NULL)
                    {
                        if (aux1->datos->Precio_compra == tamano->datos->Precio_compra)
                        {
                            insertar_cola(SubLista, crear_Nodo(crear_Alimento(tamano->datos->Tipo_de_Alimento, tamano->datos->Nombre_de_Alimento, tamano->datos->Precio_compra, tamano->datos->fecha_compraD, tamano->datos->fecha_compraM, tamano->datos->fecha_compraA, tamano->datos->fecha_caducidadD, tamano->datos->fecha_caducidadM, tamano->datos->fecha_caducidadA, tamano->datos->estatus_disponibilidad)));
                        }
                        tamano = tamano->sig;
                    }
                    printLista(SubLista);
                }
                else
                {
                    printf("\nError el elemento no se encuentra en ninguna posicion de la lista.");
                }
            }
            else
            {
                printf("\n EL ELEMENTO NO SE ENCUENTRA LA LISTA NO TIENE NADA.\n");
            }

            printf("\n\t- ¿Desea regresar al menu principal?.\n");
            printf("\n\t- 1 / Si.\n");
            printf("\n\t- 2 / No.\n");
            scanf("%d", &otro);
        } while (otro != 1);

        return (opcion2);
        break;
    }

    case 5://opcion de ordenamiento de quisort o burbuja
    {
        int ordenamiento = 0;
        do
        {
            system("cls||clear");
            printf("\n\t Elije que metodo deseas utilizar para realizar tu ordenamiento  \n");
            printf("\n\t 1.-QuickSort \n");
            printf("\n\t 2.-Burbuja  \n");
            printf("\n\t 3.-Salir  \n");
            scanf("%d", &ordenamiento);
            while ((ordenamiento != 1) && (ordenamiento != 2) && (ordenamiento != 3))
            {
                system("cls||clear");
                printf("\n- Eleccion invalida\n");
                printf("\n\t 1.-QuickSort \n");
                printf("\n\t 2.-Burbuja  \n");
                printf("\n\t 3.-Salir  \n");
                scanf("%d", &ordenamiento);
            }

            switch (ordenamiento)
            {
            case 1:
            {
                system("cls||clear");
                int medida = 0;
                Nodo *tamano = Lista->cabeza;
                int precio = 0, inicio = 0, binaria = 0;
                if (!isEmpty(*Lista))
                {
                    while (tamano->sig != NULL)
                    {
                        tamano = tamano->sig;
                        medida++;
                    }
                    medida++;
                    quickSort(Lista, inicio, medida - 1);
                    printLista(Lista);
                }
                else
                {
                    printf("\n LA LISTA NO TIENE NADA \n");
                }
                break;
            }
            case 2:
            {
                system("cls||clear");
                Ordenamiento_Burbuja(Lista);
                break;
            }
            case 3:
            {
                break;
            }
            }
            printf("\n\t- ¿Desea regresar al menu principal?\n");
            printf("\n\t- 1 / Si\n");
            printf("\n\t- 2 / No\n");
            scanf("%d", &otro);
        } while (otro != 1);
        return (opcion2);
        break;
    }

    case 6://Vaciar lista,esto dependiendo del alimento donde estemos para vaciar 
    {
        int confirma = 0;
        do
        {
            system("cls||clear");

            confirma = vaciarLista(Lista);

            if (confirma == 1)
            {
                printf("\n LISTA SIN NADA PROCEDIMIENTO VACIAR LISTA.\n");
            }
            else
            {
                printf("\n LA LISTA YA SE ENCUENTRA VACIA.\n");
            }

            printf("\n\t- ¿Desea regresar al menu principal?.\n");
            printf("\n\t- 1 / Si.\n");
            printf("\n\t- 2 / No.\n");
            scanf("%d", &otro);
        } while (otro != 1);
        return (opcion2);
        break;
    }

    case 7: //Salir del menu de alimentos
    {
        system("cls||clear");
        printf("\n\t Adios... \n");
        return (opcion2);
        break;
    }
    }
}


