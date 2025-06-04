# UEA_Estructura De Datos Lineales

📖 Este proyecto es una aplicación de consola en lenguaje C que simula la gestión del contenido de un refrigerador. Utiliza listas simplemente enlazadas para organizar y manipular diferentes categorías de alimentos.

## 👥 Integrantes: <br>
Aldo Enrique Hernández Flores. <br>
Bryan Alexander Gómez Miranda. <br>

## 🧑‍💻 Estructura del Proyecto


| Archivo           | Descripción                                                                                                   |
| ----------------- | ------------------------------------------------------------------------------------------------------------- |
| `listaS.h`        | Definiciones de estructuras (`Alimento`, `Nodo`, `ListaS`) y prototipos de funciones.                         |
| `listaS.c`        | Implementación de las funciones para manipular la lista enlazada (insertar, eliminar, buscar, ordenar, etc.). |
| `ProyectoFinal.c` | Archivo principal que contiene la interfaz por consola para gestionar el refrigerador.                        |

## 📌  Funcionalidades: <br>
El programa permite al usuario administrar seis tipos de alimentos:

Bebidas <br>
- Embutidos <br>
- Frutas <br>
- Lácteos <br>
- Proteínas <br>
- Verduras <br> 


Cada tipo de alimento se gestiona mediante su propia lista enlazada. Para cada lista, se pueden realizar las siguientes operaciones:

- 🟢 Agregar nuevos alimentos
- ❌ Eliminar alimento por precio
- 🔍 Buscar alimento por precio (búsqueda binaria iterativa o recursiva)
- 📋 Visualizar el contenido actual del refrigerador
- 🔃 Ordenar alimentos por precio (QuickSort o Burbuja)
- 🧹 Vaciar lista
- 🚪 Salir de la categoría


Cada alimento contiene los siguientes campos:

 Tipo de alimento
- Nombre
- Precio de compra
- Fecha de compra
- Fecha de caducidad
- Estatus de disponibilidad (1 = disponible, 0 = no disponible)

El programa está diseñado con una interfaz interactiva por consola que guía al usuario paso a paso, lo que lo hace ideal para fines educativos o como base para sistemas de inventario más complejos.

Este proyecto también refuerza conocimientos en:

- Uso de memoria dinámica en C
- Diseño y manejo de estructuras (`struct`)
- Manipulación de listas enlazadas
- Implementación de algoritmos de búsqueda y ordenamiento (binario, burbuja, quicksort)

✅ Es una práctica completa para el manejo de estructuras de datos dinámicas en C, aplicadas a un contexto realista.

## 📝 Ejecución

```bash
gcc ProyectoFinal.c listaS.c -o inventario
./inventario
