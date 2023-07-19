#include <stdio.h>
#include <stdlib.h>
#include "f_nombres.h"
#include "arte_asci_nombres.h"
#include "string.h"
#include "f_de_pago_solo_nombres.h"
#define cantmax 100

#define ANIOACTUAL 2022
#define MAX_LEN 128

#define DMcomidas "DMcomidas.bin"  //comidas de desayuno y merienda
#define DMbebidas "DMbebidas.bin"  //bebidas de desayuno y merienda

#define ACcomidas "ACcomidas.bin"  //comidas de almuerzo y cena
#define ACbebidas "ACbebidas.bin"  //bebidas de almuerzo y cena

///METODO DE PAGO

void main_metodo_de_pago(int total_compra)
{
    int op;
    char control = 's';

    char *filename21 = "imagen2.txt";
    FILE *fptr2 = NULL;

    if((fptr2 = fopen(filename21,"r")) == NULL)
    {
        fprintf(stderr,"error opening %s\n",filename21);
        return 1;
    }

    printf("\n\n\n");
    print_image2(fptr2);
    //printf("\n");
    do
    {

        printf("[1] PAGAR CON TARJETA \n\n");
        printf("[2] PAGAR CON EFECTIVO \n\n");
        printf("[3] PAGAR CON CUENTA DNI \n\n");

        printf("CON CUAL OPCION DESEA REALIZAR EL PAGO ? -> ");
        scanf("%d", &op);
        printf("\n");

        switch (op)
        {
        case 1:
            carga_y_muestra_tarjeta(total_compra);
            break;
        case 2:
            fflush(stdin);
            pago_efectivo(total_compra);
            break;
        case 3:
            pago_cdni(total_compra);
            break;

        default:
            printf("INGRESO NO VALIDO");
            break;
        }

        fflush(stdin);
        scanf("%c", &control);

    }
    while(control=='s');

    fflush(stdin);
    char *filename29 = "imagen7.txt";
    FILE *fptr7 = NULL;

    if((fptr7 = fopen(filename29,"r")) == NULL)
    {
        fprintf(stderr,"error opening %s\n",filename29);
        return 1;
    }
    system("cls");
    print_image7(fptr7);

}

///CARGAR TARJETA

void carga_y_muestra_tarjeta(int total_a_pagar)
{
    int numeros[cantmax];
    int tope=16;
    fflush(stdin);

    char *filename22 = "imagen3.txt";
    FILE *fptr3 = NULL;

    if((fptr3 = fopen(filename22,"r")) == NULL)
    {
        fprintf(stderr,"error opening %s\n",filename22);
        return 1;
    }

    printf("\n");
    printf("\n");
    printf("\n");
    print_image4(fptr3);

    cargar_numeros_tarjeta(numeros,tope);

    int ccv = codigo_de_seguridad();
    int mes = mes_expiracion();
    int anio = anio_expiracion();

    system("cls");
    printf("\nDATOS DE SU TARJETA \n\n");
    mostrar_numeros_tarjeta(numeros,tope);
    printf("\nCODIGO DE SEGURIDAD: [%d]   \n", ccv);
    printf("MES DE EXPIRACION: [%i] \n",mes);
    printf("ANIO DE EXPIRACION: [%i] \n\n",anio);
char seguir;
    printf("\nDatos de tarjeta correctos? s/n -> ");
    fflush(stdin);
    scanf("%c",&seguir);

    if(seguir!='s')
    {
        system("cls");
        cargar_numeros_tarjeta(numeros,tope);
    }

    printf("\n");
    system("pause");
    system("cls");
    Cuotas(total_a_pagar);
}

///NUMEROS DE LA TAJETA

void cargar_numeros_tarjeta(int a[],int n)
{
    int validos=0;
    printf("Ingrese numero de tarjeta:");
    while(validos<n)
    {
        printf("\nX - ");
        fflush(stdin);
        scanf("%d", &a[validos]);
        validos++;
    }


}

void numeros_tarjeta ()
{
    int tarjetita[cantmax];
    int n=16;

    printf("\n");
    cargar_numeros_tarjeta(tarjetita,n);
    printf("\n");
}

void mostrar_numeros_tarjeta(int a[],int validos)
{
    int i=0;
    printf("NUMERO DE SU TARJETA: ");
    while(i<validos)
    {
        printf("%d", a[i]);
        i++;
    }
}

///CODIGO DE SEGURIDAD

int codigo_de_seguridad ()
{
    int cant_cod, ccv;

    printf("\nIngrese codigo de seguridad - ");
    scanf("%d",&ccv);

    cant_cod=contarDigitos(ccv);

    if(cant_cod==3)
    {
        return ccv;
    }
    else
    {
        printf ("-------------------------------------------------------");
        printf("\nCodigo de seguridad INCORRECTO, vuelva a ingresarlo...\n");
        printf ("-------------------------------------------------------\n");
        codigo_de_seguridad();
    }

}

int contarDigitos(int Num)
{
    int Contador, Num2;
    Num2 = Num;
    Contador = 0;
    while(Num != 0)
    {
        Contador++;
        Num=(Num / 10);
    }

    return Contador;
}

///MES

int mes_expiracion ()
{
    int mes;
    printf("\nIngrese mes de expiracion con numeros - ");
    scanf("%i", &mes);

    if(mes>0 && mes<13)
    {
        return mes;
    }
    else
    {
        printf ("------------------------------------------");
        printf("\nMes INCORRECTO, intentelo nuevamente...\n");
        printf ("------------------------------------------");
        mes_expiracion();
    }
}

///AÑO

int anio_expiracion()
{
    int a_exp;
    printf("\nIngrese anio de expiracion - ");
    scanf("%i", &a_exp);

    if(a_exp>ANIOACTUAL)
    {
        return a_exp;
    }
    else
    {
        printf ("------------------------------------------");
        printf("\nAnio INCORRECTO, intentelo nuevamente...\n");
        printf ("------------------------------------------");
        anio_expiracion();
    }
}

///CUOTAS

void Cuotas (int total_compra)
{
    int opcion;
    //TITULO PIOLON
    char *filename25 = "imagen6.txt";
    FILE *fptr6 = NULL;

    if((fptr6 = fopen(filename25,"r")) == NULL)
    {
        fprintf(stderr,"error opening %s\n",filename25);
        return 1;
    }
    print_image6(fptr6);
    printf("\nOPCION [1] -> 3 CUOTAS SIN INTERES de $%d.\n ", total_compra/3);
    printf("\nOPCION [2] -> 6 CUOTAS SIN INTERES de $%d.\n ",total_compra/6);
    printf("\nOPCION [3] -> 12 CUOTAS SIN INTERES de $%d.\n ", total_compra/12);
    printf("\nOPCION [4] -> 1 SOLO PAGO de $%d \n ", total_compra);

    printf("\nSeleccione su opcion de cuotas -> ");
    fflush(stdin);
    scanf("%d", &opcion);

    switch (opcion)
    {
    case 1:
        printf("\nTOTAL DE COMPRA [$%d]. Fue agregado a su tarjeta en 3 CUOTAS SIN INTERES de [$%d] ",total_compra, total_compra/3);
        break;
    case 2:
        printf("\nTOTAL DE COMPRA [$%d]. Fue agregado a su tarjeta en 6 CUOTAS SIN INTERES de [$%d] ",total_compra, total_compra/6 );
        break;
    case 3:
        printf("\nTOTAL DE COMPRA [$%d]. Fue agregado a su tarjeta en 12 CUOTAS SIN INTERES de [$%d] ", total_compra, total_compra/12);
        break;
    case 4:
        fflush(stdin);
        printf("\nTOTAL DE COMPRA [$%d].", total_compra);
        break;
    default:
        printf("\nINGRESO NO VALIDO \n ");
        Cuotas(total_compra);
        break;
    }

}

///EFECTIVO

void pago_efectivo(int total)
{
    char seguir='s';
    int descuento, total_con_descuento;

    printf("Esta seguro de pagar en efectivo? s/n -> ");
    fflush(stdin);
    scanf("%c", &seguir);
    system("cls");

    if(seguir=='s')
    {
        char *filename35 = "imagen9.txt";
        FILE *fptr9 = NULL;

        if((fptr9 = fopen(filename35,"r")) == NULL)
        {
            fprintf(stderr,"error opening %s\n",filename35);
            return 1;
        }

        printf("\n\n\n");
        print_image9(fptr9);
        printf("\n\n\n");
        printf("\nSu monto total a pagar es de [$%i] \n", total);

        printf("\nRecibira un 15 de descuento por pagar en efectivo\n");
        descuento=total*0.15;

        total_con_descuento=total - descuento;
        printf("\n\nTOTAL CON DESCUENTO --> $%i <-- \n",total_con_descuento);
    }
    else
    {
        main_metodo_de_pago(total);
    }

}

///DNI

void pago_cdni(int total)
{
    char seguir='s';

    int validos=0;
    char codigo[validos];

    int dni;

    printf("Esta seguro de usar cuenta DNI?  s/n -> ");
    fflush(stdin);
    scanf("%c", &seguir);

    if(seguir=='s')
    {
        system("cls");
        char *filename40 = "imagen10.txt";
        FILE *fptr10 = NULL;

        if((fptr10 = fopen(filename40,"r")) == NULL)
        {
            fprintf(stderr,"error opening %s\n",filename40);
            return 1;
        }

        printf("\n\n\n");
        print_image10(fptr10);
        printf("\n\n\n");
        printf("Ingrese su DNI -> ");
        fflush(stdin);
        scanf("%d", &dni);

        printf("\nSu total es de %i, ingreselo en la app\n", total);

        while(validos<6)
        {
            printf("\nIngrese codigo cuenta dni X - ");
            fflush(stdin);
            scanf("%d", &codigo[validos]);
            validos++;
        }
    }
    else
    {
        main_metodo_de_pago(total);
    }

    printf("\n\nPago confirmado!...");
}
