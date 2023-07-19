#ifndef F_NOMBRES_H_INCLUDED
#define F_NOMBRES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#define cantmax 100

#define ANIOACTUAL 2022
#define MAX_LEN 128

#define DMcomidas "DMcomidas.bin"  //comidas de desayuno y merienda
#define DMbebidas "DMbebidas.bin"  //bebidas de desayuno y merienda
#define ACcomidas "ACcomidas.bin"  //comidas de almuerzo y cena
#define ACbebidas "ACbebidas.bin"  //bebidas de almuerzo y cena

typedef struct
{
    int codigo; // cod del producto
    char nombreProducto[cantmax]; //CAFE
    int precio;     //$450

} Producto;

typedef struct
{
    Producto producto; //nodos de la lista
    struct Lista*sig; //mueve
} Lista;

typedef struct
{
    char nombre[cantmax];  //DESAYUNO/ALMUERZO/MERIENDA/CENA
    Lista* OP_comida; //lista que tiene los productos
    Lista* bebidas;  //lista que tiene los productos

} Comidas;



//PRODUCTOS
void cargarProducto (char archivo[cantmax]);
void muestraProducto (Producto p);

//ARCHIVOS
void persistencia (Producto p, char archivo[cantmax]);
void muestraArchivo (char archivo[cantmax]);

//Carga de archivos de productos
int Carga_de_archivos ();
void muestra_carga ();

//LISTAS
Lista * iniclista();
Lista * crearNodo (Producto p);
Lista * Agregar_a_Lista (Lista* lista, Lista* nuevoNodo);
Lista* agregar_al_ppio(Lista*lista, Lista* nuevoNodo);
void recorrer_y_mostrar (Lista*lista);
void mostrar (Lista*aux);

// Pasar lo del archivo a las listas
Lista* despersistencia (char archivo[cantmax]);

// ARREGLO
void CargarArreglo (Comidas arr[], int val);
void RecoridoyMuestra_Arreglo (Comidas arr[], int val);
void mostrarPorPos (Comidas arr[], int val, int pos);
void Pedido (Comidas arr[], int val);
int Opciones ();                                     //retorna 1 o 2 (1 para seguir por aca, 2 para llamar a un mozo)
void pedidoAlMozo();
int OpcionDelMENU ();
void pedidoPorApp(Comidas arr[], int val, int opCom);
void tomarPedido (Comidas arr[], int val, int op);
int corroboracionDelCodigo (Comidas arr[], int codigo, int op);
void arrCodigos (int arrCod[], int * val, int codigo);
void mostrarArrCod (Comidas arr[], int arrcod[], int val, int op);
void buscarNombreDelCod (Comidas arr[], int codigo, int op, char NombreDelProducto[]);
void mostrarNombreDelCod (Comidas arr[], int codigo, int op);
Producto encontrarProducto(Lista * lista, int codigo);
int total_a_pagar (Comidas arr[], int op, int arrcod[], int valCod, int codigo);






#endif // F_NOMBRES_H_INCLUDED
