#ifndef F_DE_PAGO_SOLO_NOMBRES_H_INCLUDED
#define F_DE_PAGO_SOLO_NOMBRES_H_INCLUDED
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


//GENERAL
void main_metodo_de_pago(int total_compra);

//TARJETA
void carga_y_muestra_tarjeta();
void cargar_numeros_tarjeta(int a[],int n);
void numeros_tarjeta ();
void mostrar_numeros_tarjeta(int a[],int validos);
int codigo_de_seguridad ();
int contarDigitos(int Num);
int anio_expiracion();
int mes_expiracion ();
void Cuotas ();

//EFECTIVO
void pago_efectivo();

//CUENTA DNI
void pago_cdni();


#endif // F_DE_PAGO_SOLO_NOMBRES_H_INCLUDED
