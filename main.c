#include <stdio.h>
#include <stdlib.h>
#include "f_nombres.h"
#include "string.h"
#include "arte_asci_nombres.h"
#include "f_de_pago_solo_nombres.h"
#define cantmax 100

#define ANIOACTUAL 2022
#define MAX_LEN 128

#define DMcomidas "DMcomidas.bin"  //comidas de desayuno y merienda
#define DMbebidas "DMbebidas.bin"  //bebidas de desayuno y merienda

#define ACcomidas "ACcomidas.bin"  //comidas de almuerzo y cena
#define ACbebidas "ACbebidas.bin"  //bebidas de almuerzo y cena



int main()
{
    //Carga_de_archivos();

    Comidas menu[cantmax]; //arreglo que va a tener las comidas de desayuno-almuerzo-merienda-cena
    int val=4;

    system("color F0");

    char *filename = "imagen.txt";
    FILE *fptr = NULL;

    if((fptr = fopen(filename,"r")) == NULL)
    {
        fprintf(stderr,"error opening %s\n",filename);
        return 1;
    }
    print_image(fptr);

    strcpy(menu[0].nombre,"DESAYUNO");
    strcpy(menu[1].nombre,"ALMUERZO");
    strcpy(menu[2].nombre,"MERIENDA");
    strcpy(menu[3].nombre,"CENA");

    CargarArreglo(menu,val);


    char *filename23 = "imagen5.txt";
    FILE *fptr5 = NULL;

    if((fptr5 = fopen(filename23,"r")) == NULL)
    {
        fprintf(stderr,"error opening %s\n",filename23);
        return 1;
    }
    print_image(fptr5);







    Pedido(menu,val);
    printf("\n");



    return 0;
}
