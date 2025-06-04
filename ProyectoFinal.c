/*Proyecto Final*/
/*Integrantes
1.Aldo Enrique Hernandez Flores
2.Bryan Alexander Gomez Miranda
*/

#include "listaS.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int option = 1, opcion2 = 1;
    ListaS *Bebidas;
    ListaS *Embutidos;
    ListaS *Frutas;
    ListaS *Lacteos;
    ListaS *Proteinas;
    ListaS *Verduras;
    Bebidas = crear_ListaS(); // crea la lista principal
    Embutidos = crear_ListaS();
    Frutas = crear_ListaS();
    Lacteos = crear_ListaS();
    Proteinas = crear_ListaS();
    Verduras = crear_ListaS();
    char tipoalimento[50];

    do
    {
        system("cls||clear");
        printf("\n");
        printf("\n");
        printf("-----------------------------------------------------------\n");
        printf("\n");
        printf("    ooooo  oooo      o        oooo     oooo     Alimentos:\n");
        printf("     888    88      888        8888o   888      Bryan Alexander Gomez Miranda\n");
        printf("     888    88     8  88       88 888o8 88      Aldo Enrique Hernandez Flores\n");
        printf("     888    88    8oooo88      88  888  88     \n");
        printf("      888oo88   o88o  o888o   o88o  8  o88o    \n");
        printf("\n");
        printf("\n");
        printf("            /##\\   \\/########\\/   /#\\ \n");
        printf("           /##/ \\   \\##/   \\##\\  /\\##\\ \n");
        printf("          /##/   \\   \\/     \\##\\/  \\##\\ \n");
        printf("         /##/    /\\   \\    / \\##\\   \\##\\ \n");
        printf("        /##/    /##\\   \\__/   \\##\\   \\##\\ \n");
        printf("       /##/    /##/ \\________/ \\##\\   \\##\\ \n");
        printf("\n");
        printf("\n");
        printf("*********************************************************\n");
        printf("\n\t BIENVENIDO A LAS LISTAS DEL CONTENIDO DE TU REFRIGERADO  \n");
        printf("\n\t Estos son las categorias de los alimentos que podemos enlistar  \n");
        printf("\n\t1- Bebidas\n");
        printf("\n\t2- Embutidos\n");
        printf("\n\t3- Frutas\n");
        printf("\n\t4- Lacteos\n");
        printf("\n\t5- Proteinas\n");
        printf("\n\t6- Verduras\n");
        printf("\n\t7- Salir\n");
        printf("\n\t Dime el numero de la categoria a la que quieres ingresar:  \n");
        printf("*********************************************************\n");

        scanf("%d", &option);

        switch (option)
        {
        case 1: // crea los nodos y agrega nuevos Alimentos a la lista principal.
        {
            do
            {
                opcion2 = Alimentos(Bebidas, "Bebida");

            } while (opcion2 != 7);

            break;
        }
        case 2:
        {
            do
            {
                opcion2 = Alimentos(Embutidos, "Embutidos");

            } while (opcion2 != 7);
            break;
        }
        case 3:
        {
            do
            {
                opcion2 = Alimentos(Frutas, "Frutas");

            } while (opcion2 != 7);
            break;
        }
        case 4:
        {
            do
            {
                opcion2 = Alimentos(Lacteos, "Lacteos");

            } while (opcion2 != 7);

            break;
        }

        case 5:
        {
            do
            {
                opcion2 = Alimentos(Proteinas, "Proteinas");

            } while (opcion2 != 7);
            break;
        }

        case 6:
        {
            do
            {

                opcion2 = Alimentos(Verduras, "Verduras");
            } while (opcion2 != 7);

            break;
        }
        case 7:
        {
            system("cls||clear");
            printf("\n\t Fin del Programa.Adios... \n");
            break;
        }
        }
    } while (option != 7);
    free(Bebidas); // libera la lista principal
    free(Embutidos);
    free(Frutas);
    free(Lacteos);
    free(Proteinas);
    free(Verduras);
    return (0);
}
