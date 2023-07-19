#include <stdio.h>
#include <stdlib.h>
#include "f_nombres.h"
#include "arte_asci_nombres.h"
#include "f_de_pago_solo_nombres.h"
#include "string.h"
#define cantmax 100

#define ANIOACTUAL 2022
#define MAX_LEN 128

#define DMcomidas "DMcomidas.bin"  //comidas de desayuno y merienda
#define DMbebidas "DMbebidas.bin"  //bebidas de desayuno y merienda

#define ACcomidas "ACcomidas.bin"  //comidas de almuerzo y cena
#define ACbebidas "ACbebidas.bin"  //bebidas de almuerzo y cena


void cargarNombres (Comidas arr[], int val)
{
    printf("pos 0 ");
    fflush(stdin);
    scanf("%s",&arr[0].nombre);

    printf("pos 1 ");
    fflush(stdin);
    scanf("%s",&arr[1].nombre);

    printf("pos 2 ");
    fflush(stdin);
    scanf("%s",&arr[2].nombre);

    printf("pos 3 ");
    fflush(stdin);
    scanf("%s",&arr[3].nombre);
}

///PRODUCTOS

void cargarProducto (char archivo[cantmax])
{
    char seguir='s';
    Producto p;

    do
    {
        printf("CODIGO: ");
        scanf("%i",&p.codigo);

        printf("NOMBRE DEL PRODUCTO:");
        fflush(stdin);
        gets(p.nombreProducto);

        printf("PRECIO:");
        scanf("%i",&p.precio);

        printf("Otro producto?");
        fflush(stdin);
        scanf("%c",&seguir);

        persistencia(p, archivo);    //lo agrega al archivo

        printf("\n");

    }
    while (seguir=='s');

}

void muestraProducto (Producto p)
{
    printf("%i - ", p.codigo);
    printf("%s ....... ", &p.nombreProducto);
    printf("$%i", p.precio);
    printf("\n");
}

///ARCHIVOS

void persistencia (Producto p, char archivo[cantmax])
{
    FILE* fp = fopen(archivo, "ab");

    if (fp != NULL)
    {
        fwrite(&p, sizeof(Producto), 1, fp);
        fclose(fp);
    }
}

void muestraArchivo (char archivo[cantmax])
{
    Producto p;

    FILE* fp = fopen(archivo, "rb"); //read

    if(fp!=NULL)
    {
        while(fread(&p, sizeof(Producto), 1, fp)>0)
        {
            muestraProducto(p);
        }

        fclose(fp);
    }
}

///Carga de archivos de productos

int Carga_de_archivos ()
{
    printf("ARCHIVO DE COMIDAS DE DESAYUNO/MERIENDA\n");
    cargarProducto(DMcomidas);

    system("cls");

    printf("ARCHIVO DE BEBIDAS DE DESAYUNO/MERIENDA\n");
    cargarProducto(DMbebidas);

    system("cls");

    printf("ARCHIVO DE COMIDAS DE ALMUERZO/CENA\n");
    cargarProducto(ACcomidas);

    system("cls");

    printf("ARCHIVO DE BEBIDAS DE ALMUERZO/CENA\n");
    cargarProducto(ACbebidas);

    system("cls");

    muestra_carga();

    return 0;
}

void muestra_carga ()
{
    printf("COMIDAS DESAYUNO/MERIENDA\n");
    muestraArchivo(DMcomidas);

    printf("\n");

    printf("BEBIDAS DESAYUNO/MERIENDA\n");
    muestraArchivo(DMbebidas);

    printf("\n");

    printf("COMIDAS ALMUERZO/CENA\n");
    muestraArchivo(ACcomidas);

    printf("\n");

    printf("BEBIDAS ALMUERZO/CENA\n");
    muestraArchivo(ACbebidas);
}

///LISTAS

Lista * iniclista()
{
    return NULL;
}

Lista * crearNodo (Producto p)
{
    Lista*nuevoNodo=(Lista*)malloc(sizeof(Lista));
    nuevoNodo->producto=p;
    nuevoNodo->sig=NULL;

    return nuevoNodo;
}

Lista * Agregar_a_Lista (Lista* lista, Lista* nuevoNodo)
{
    if(lista==NULL)
    {
        lista=nuevoNodo;
    }
    else
    {
        if(nuevoNodo->producto.codigo < lista->producto.codigo)
        {
            lista=agregar_al_ppio(lista,nuevoNodo);
        }
        else
        {
            Lista*ante=lista;
            Lista*aux=lista;

            while(aux!=NULL && nuevoNodo->producto.codigo > aux->producto.codigo)
            {
                ante=aux;
                aux=aux->sig;
            }

            ante->sig=nuevoNodo;
            nuevoNodo->sig=aux;
        }
    }

    return lista;
}

Lista* agregar_al_ppio(Lista*lista, Lista* nuevoNodo)
{
    if(lista!=NULL)
    {
        lista=nuevoNodo;
    }
    else
    {
        nuevoNodo->sig=lista;
        lista=nuevoNodo;
    }

    return lista;
}

void recorrer_y_mostrar (Lista*lista)
{
    Lista*seg=lista;

    while(seg!=NULL)
    {
        mostrar(seg);
        seg=seg->sig;
    }
}

void mostrar (Lista*aux)
{
    printf("%i - ", aux->producto.codigo);
    printf("%s ....... ", aux->producto.nombreProducto);
    printf("$%i", aux->producto.precio);
    printf("\n");
}

/// Pasar lo del archivo a las listas

Lista* despersistencia (char archivo[cantmax])
{
    FILE* fp = fopen(archivo, "rb");

    Producto p;
    Lista* nuevoNodo;
    Lista* lista = iniclista();

    if (fp != NULL)
    {
        ///entra 4 veces
        while (fread(&p, sizeof(Producto), 1, fp) > 0)
        {
            nuevoNodo = crearNodo(p);
            lista = Agregar_a_Lista(lista,nuevoNodo);
        }

        fclose(fp);
    }

    return lista;
}

/// ARREGLO

void CargarArreglo (Comidas arr[], int val)
{
    for(int i=0; i<val; i++)
    {
        if ((strcmp(arr[i].nombre,"DESAYUNO")==0)||(strcmp(arr[i].nombre,"MERIENDA")==0))
        {
            arr[i].OP_comida = despersistencia(DMcomidas);
            arr[i].bebidas = despersistencia(DMbebidas);
        }
        else
        {
            if((strcmp(arr[i].nombre,"ALMUERZO")==0)||(strcmp(arr[i].nombre,"CENA")==0))
            {
                arr[i].OP_comida = despersistencia(ACcomidas);
                arr[i].bebidas = despersistencia(ACbebidas);
            }
        }
    }
}

void RecoridoyMuestra_Arreglo (Comidas arr[], int val)
{
    for (int i=0; i<val; i++)
    {
        printf("------------------\n");
        puts(arr[i].nombre);
        printf("-------------------\n");
        recorrer_y_mostrar(arr[i].OP_comida);
        recorrer_y_mostrar(arr[i].bebidas);
        printf("--------------------\n");
    }
}

void mostrarPorPos (Comidas arr[], int val, int pos)
{
    if (pos<val)
    {
        printf("------------------\n");
        puts(arr[pos].nombre);
        printf("-------------------\n");
        recorrer_y_mostrar(arr[pos].OP_comida);
        recorrer_y_mostrar(arr[pos].bebidas);
        printf("--------------------\n");
    }
}

void Pedido (Comidas arr[], int val)
{
    int op=Opciones();

    if(op==2)
    {
        pedidoAlMozo();
    }
    else
    {
        pedidoPorApp(arr,val,op);
    }
}

int Opciones ()                                     //retorna 1 o 2 (1 para seguir por aca, 2 para llamar a un mozo)
{
    int op=0;
    char seguir='s';
    do
    {
        printf("Como desea ordenar? Ingrese 1 o 2 segun corresponda\n\n");
        printf("[1] MEDIANTE LA APP\n");
        printf("[2] MEDIANTE UN MOZO\n");
        printf("\n OPCION: ");
        scanf("%i", &op);


        if(op==1 || op==2)
        {
            printf("\n");

            if(op==1)
            {
                printf("\n");
                printf("Usted ingreso la opcion %i -> MEDIANTE LA APP  \n ", op);
                printf("\nEs correcto? s/n -> ");
                fflush(stdin);
                scanf("%c",&seguir);
                printf("\n");
                system("pause");
                printf("\n");
            }
            else
            {
                printf("Usted ingreso la opcion %i -> MEDIANTE UN MOZO\n", op);
                printf("\nEs correcto? s/n -> ");
                fflush(stdin);
                scanf("%c",&seguir);
                printf("\n");
                system("pause");
                printf("\n");
            }
        }
        else
        {
            printf("\nLa opcion ingresada es INCORRECTA, intentelo nuevamente...\n\n");
            Opciones();
        }
    }
    while(seguir!='s');

    return op;
}

void pedidoAlMozo()
{
    int numMesa=0;
    system("cls");
    printf("Ingrese su numero de mesa: ");
    scanf("%i",&numMesa);
    printf("\n");
    char *filename45 = "imagen15.txt";
    FILE *fptr15 = NULL;

    if((fptr15 = fopen(filename45,"r")) == NULL)
    {
        fprintf(stderr,"error opening %s\n",filename45);
        return 1;
    }
    print_image15(fptr15);
    printf("\n\n");

    printf("Un mozo a sido enviado a la mesa %i, aguarde un momento y su pedido sera tomado por el mismo.\n", numMesa);
    printf("\nMuchas gracias!!\n");
}

int OpcionDelMENU ()
{
    int opCom=0;
    system("cls");
    char *filename30 = "imagen8.txt";
    FILE *fptr8 = NULL;

    if((fptr8 = fopen(filename30,"r")) == NULL)
    {
        fprintf(stderr,"error opening %s\n",filename30);
        return 1;
    }
    system("cls");
    print_image(fptr8);
    printf("\n");
    printf("\nINGRESE SU OPCION DE MENU \n");
    printf("\n[1] DESAYUNAR \n");
    printf("[2] ALMORZAR \n");
    printf("[3] MERENDAR\n");
    printf("[4] CENAR\n\n");
    printf("OPCION: ");
    scanf("%i",&opCom);

    return opCom;
}

void pedidoPorApp(Comidas arr[], int val, int opCom)
{
    int flag=0;
    do
    {
        opCom = OpcionDelMENU();

        if(opCom<5 && opCom>0)
        {
            flag=1;
        }
        else
        {
            printf("\nLa opcion ingresada es INCORRECTA, intentelo nuevamente\n\n");
        }

    }
    while(flag==0);

    system("cls");
    printf("\n\nA continuacion le mostraremos el menu\n\n");

    if (opCom == 1)
    {
        char *filename71 = "imagen13.txt";
        FILE *fptr13 = NULL;

        if((fptr13 = fopen(filename71,"r")) == NULL)
        {
            fprintf(stderr,"error opening %s\n",filename71);
            return 1;
        }
        print_image13(fptr13);
        printf("\n\n");
        mostrarPorPos(arr, val, 0);
    }

    if(opCom == 2)
    {
        char *filename86 = "imagen11.txt";
        FILE *fptr11 = NULL;

        if((fptr11 = fopen(filename86,"r")) == NULL)
        {
            fprintf(stderr,"error opening %s\n",filename86);
            return 1;
        }
        system("cls");
        print_image11(fptr11);
        printf("\n");

        mostrarPorPos(arr, val, 1);
    }

    if(opCom == 3)
    {

        char *filename74 = "imagen14.txt";
        FILE *fptr14 = NULL;

        if((fptr14 = fopen(filename74,"r")) == NULL)
        {
            fprintf(stderr,"error opening %s\n",filename74);
            return 1;
        }
        print_image14(fptr14);
        printf("\n");

        mostrarPorPos (arr, val, 2);
    }

    if (opCom == 4)
    {

        char *filename99 = "imagen12.txt";
        FILE *fptr12 = NULL;

        if((fptr12 = fopen(filename99,"r")) == NULL)
        {
            fprintf(stderr,"error opening %s\n",filename99);
            return 1;
        }
        system("cls");
        print_image12(fptr12);
        printf("\n");

        mostrarPorPos(arr, val, 3);
    }

    tomarPedido(arr,val,opCom);
}

void tomarPedido (Comidas arr[], int val, int op)
{
    int codProducto;
    int FLAG=0;
    char seguir='s';

    int ArrCod[cantmax];
    int valCod=0;

    int total=0;

    do
    {
        printf("\n\nIngrese el codigo del producto que desea consumir -> ");
        scanf("%i",&codProducto);

        FLAG = corroboracionDelCodigo (arr,codProducto,op);

        if (FLAG != 0)
        {
            printf("\nDesea pedir algo mas? s/n -> ");
            fflush(stdin);
            scanf("%c",&seguir);

            arrCodigos (ArrCod,&valCod,codProducto);
        }
        else
        {
            printf ("\n---------------------------------------------------------------------------------");
            printf("\nERROR el codigo ingresado es incorrecto, INGRESE SU PEDIDO DESDE EL PRINCIPIO\n");
            printf ("---------------------------------------------------------------------------------");
            tomarPedido(arr,val,op);
        }

    }
    while(seguir == 's');

    system("cls");
    mostrarArrCod(arr,ArrCod,valCod,op);
    total = total_a_pagar (arr,op,ArrCod,valCod,FLAG);
    printf("\nSu total a pagar es de [$%i] \n ",total);
    printf("\n");
    system("pause");

    main_metodo_de_pago(total);
}

int corroboracionDelCodigo (Comidas arr[], int codigo, int op)
{
    int flag=0;

    Lista * listabebidas = arr[op-1].bebidas;
    Lista * listacomidas = arr[op-1].OP_comida;

    int codigoBebida=0;
    int codigoComida=0;

    while(flag == 0 && listabebidas != NULL)
    {
        if(listabebidas->producto.codigo == codigo)
        {
            codigoBebida=codigo;
            flag = 1;
        }
        listabebidas = listabebidas->sig;
    }

    while(flag == 0 && listacomidas != NULL)
    {
        if(listacomidas->producto.codigo == codigo)
        {
            codigoComida=codigo;
            flag = 1;
        }
        listacomidas = listacomidas->sig;
    }

    return flag;
}

void arrCodigos (int arrCod[], int * val, int codigo)
{
    arrCod[*val] = codigo;
    (*val)++;
}

void mostrarArrCod (Comidas arr[], int arrcod[], int val, int op)
{
    printf("\nLo elegido del menu es:\n");

    for(int i=0; i<val; i++)
    {
        printf("\n|%i| - ", arrcod[i]);
        mostrarNombreDelCod(arr,arrcod[i],op);
    }
}

void buscarNombreDelCod (Comidas arr[], int codigo, int op, char NombreDelProducto[])
{
    Lista * listabebidas = arr[op-1].bebidas;
    Lista * listacomidas = arr[op-1].OP_comida;

    int flag=0;

    while(flag == 0 && listabebidas != NULL)
    {
        if(listabebidas->producto.codigo == codigo)
        {
            strcpy(NombreDelProducto,listabebidas->producto.nombreProducto);
            flag=1;
        }

        listabebidas = listabebidas->sig;
    }

    while(flag == 0 && listacomidas != NULL)
    {
        if(listacomidas->producto.codigo == codigo)
        {
            strcpy(NombreDelProducto,listacomidas->producto.nombreProducto);
            flag=1;
        }
        listacomidas = listacomidas->sig;
    }
}

void mostrarNombreDelCod (Comidas arr[], int codigo, int op)
{
    char nombre[cantmax];

    buscarNombreDelCod(arr,codigo,op, nombre);
    printf(" PRODUCTO: %s\n", nombre);
}

Producto encontrarProducto(Lista * lista, int codigo)
{
    Producto producto = {0};

    while(lista != NULL && lista->producto.codigo != codigo )
    {
        lista = lista->sig;
    }

    if(lista != NULL)
    {
        producto = lista->producto;
    }

    return producto;
}

int total_a_pagar (Comidas arr[], int op, int arrcod[], int valCod, int codigo)
{
    int totalBebida=0, totalComida=0;
    Producto p;

    Lista * listabebidas = arr[op-1].bebidas;
    Lista * listacomidas = arr[op-1].OP_comida;

    for(int i=0; i<valCod; i++)
    {

        p=encontrarProducto(listabebidas,arrcod[i]);

        if(p.codigo!=0)
        {
            totalBebida=totalBebida+p.precio;
        }

        p=encontrarProducto(listacomidas,arrcod[i]);

        if(p.codigo!=0)
        {
            totalComida=totalComida+p.precio;
        }
    }
    return totalBebida+totalComida;
}



