#ifndef ARTE_ASCI_NOMBRES_H_INCLUDED
#define ARTE_ASCI_NOMBRES_H_INCLUDED
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


//IMAGENES ASCII
void print_image(FILE *fptr);// RESTO BUENARDO
void print_image2(FILE *fptr2);// METODO DE PAGO
void print_image4(FILE *fptr4);// TARJETA
void print_image5(FILE *fptr5);// DATOS TARJETA
void print_image6(FILE *fptr6);// CUOTAS
void print_image7(FILE *fptr7);// GRACIAS POR ELEGIRNOS
void print_image8(FILE *fptr8);// MENU PLATO
void print_image9(FILE *fptr9);// EFECTIVO
void print_image10(FILE *fptr10);// CUENTA DNI
void print_image11(FILE *fptr11);// HAMBURGUESA ALMUERZO
void print_image12(FILE *fptr12);// PIZZA CENA
void print_image13(FILE *fptr13);// DESAYUNO
void print_image14(FILE *fptr14);// MERIENDA
void print_image15(FILE *fptr15);// MOZO

#endif // ARTE_ASCI_NOMBRES_H_INCLUDED
