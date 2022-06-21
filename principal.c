#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <dos.h>
#include "prototypes.h"



void Principal(stInmigrante inmigrantes[], int validos)
{
    int i=0;
    char dejarPasar[TAM];

    system("cls");
    /** test para ver los errores **/
    printf("\t\t DATOS DE TEST \n");
    mostrar_tarjetas(inmigrantes, validos);
    getch();

    /** Game **/
    for(i=0;i<validos;i++)
    {
        system("cls");

        /** Data **/
        InmigrantesRestantes(validos, i);
        MostrarDNIyPermiso(inmigrantes, i);

        /** Input deja pasar o no **/
        inputDejarPasar(&dejarPasar);
        validarDejarPasar(dejarPasar);

        /** Se guarda la respuesta **/
        if((strcmp(dejarPasar, "SI") == 0))
            inmigrantes[i].visado = 1;
         else
            inmigrantes[i].visado = 0;

        getch();
    }

    /** Se guarda el resumen en archivo **/
    guardarResumen(inmigrantes, validos);

    /** Se muestra el resumen al usuario **/
    ResumenPartida(inmigrantes, validos);
}

void InmigrantesRestantes(int validos, int i)
{
    int restantes = 0;
    restantes = validos - i - 1;
    printf("\n\t Cantidad de inmigrantes restantes: %i \n", restantes);
}

void mostrar_tarjetas(stInmigrante inmigrantes[], int validos)
{
    int i=0;
    for(i=0;i<validos;i++)
    {
        printf("--------------------------------------------------\n");
        printf("Fecha en el juego:1860                            |\n");
        printf("Pasaporte:                                        |\n");
        printf("                                                  |\n");
        printf("Nombre:%-43s|\n", inmigrantes[i].nombre);
        printf("Apellido:%-41s|\n", inmigrantes[i].apellido);
        printf("DNI:%-46i|\n", inmigrantes[i].dni);
        printf("Genero=%-43c|\n",inmigrantes[i].genero);
        printf("Fecha de nacimiento:%i/%i/%-25i|\n",inmigrantes[i].diaNacimineto, inmigrantes[i].mesNacimineto, inmigrantes[i].anoNacimineto);
        printf("Edad:%-45i|\n", inmigrantes[i].edad);
        printf("zona=%-45s|\n", inmigrantes[i].zona);
        printf("vencimiento dni:%-34i|\n",inmigrantes[i].vencimientoDNI);
        printf("---------------------------------------------------\n");
        printf("Permiso:                                          |\n");
        printf("Nombre:%-43s|\n", inmigrantes[i].permiso.nombre);
        printf("Apellido:%-41s|\n", inmigrantes[i].permiso.apellido);
        printf("DNI:%-46i|\n", inmigrantes[i].permiso.dni);
        printf("Proposito:%-40s|\n", inmigrantes[i].permiso.proposito);
        if(inmigrantes[i].permiso.duracion>=10 && inmigrantes[i].permiso.duracion<=30)
        printf("Duracion: %i Dias \n", inmigrantes[i].permiso.duracion);
            else if(inmigrantes[i].permiso.duracion>=3 && inmigrantes[i].permiso.duracion<=8)
        printf("Duracion: %i Meses \n", inmigrantes[i].permiso.duracion);
            else if(inmigrantes[i].permiso.duracion==2 || inmigrantes[i].permiso.duracion==1)
        printf("Duracion: %i Dias \n", inmigrantes[i].permiso.duracion);
            else if(inmigrantes[i].permiso.duracion==0)
        printf("Duracion: Permanente \n", inmigrantes[i].permiso.duracion);

        printf("\n\n\n");
    }
}

void printff(stInmigrante I[], int posicion, char tipoduracion[])
{
    printf("\n\n\n\n");
    printf( "  ____________________________________________________\t ________________________________________\n"
            "  |______________  PASAPORTE                          |\t| _______ PERMISO DE IMIGRACION         |\n"
            "  |    ______    |                                   |\t||__   __|                              |\n"
            "  |   /______\\  | Nombre:%-28s|\t|   | |    Nombre:%-22s|\n"
            "  |   | o  o |   | Apellido:%-26s|\t| __|_|    Apellido:%-20s|\n"
            "  |   |  /   |   | DNI:%-31i|\t||  |____  DNI:%-25i|\n"
            "  |   |  -   |   | Genero:%-28c|\t||_______|                              |\n"
            "  |    \\____/   | Fecha de nacimiento:%2i/%2i/%-9i|\t|          Proposito:                   |\n"
            "  |______________| Edad:%-30i|\t|          %-29s|\n"
            "  |                                                  |\t|          Duracion:                    |\n"
            "  | ____________                        _________    |\t|          %-2i %-26s|\n"
            "  ||Certificado |                      |___   ___|   |\t|_______________________________________|\n"
            "  ||Por         |                          | |       |                                        \n"
            "  ||%-12s|                       ___|_|       |                                        \n"
            "  ||____________|                      |   |_____    |                                       \n"
            "  |                                    |_________|   |\n"
            "  |__________________________________________________|\n",
           I[posicion].nombre, I[posicion].permiso.nombre,
           I[posicion].apellido, I[posicion].permiso.apellido,
           I[posicion].dni, I[posicion].permiso.dni,
           I[posicion].genero,
           I[posicion].diaNacimineto, I[posicion].mesNacimineto, I[posicion].anoNacimineto,
           I[posicion].edad, I[posicion].permiso.proposito,
           I[posicion].permiso.duracion, tipoduracion,
           I[posicion].zona);
}

void MostrarDNIyPermiso(stInmigrante I[], int posicion)
{
    char tipoduracion[TAM];

    if(I[posicion].permiso.duracion>=10 && I[posicion].permiso.duracion<=30)
    {
        strcpy(tipoduracion,"Dia");
        printff(I, posicion, tipoduracion);
    }
    else if(I[posicion].permiso.duracion>=3 && I[posicion].permiso.duracion<=9)
    {
        strcpy(tipoduracion,"Meses");
        printff(I, posicion, tipoduracion);
    }
    else if(I[posicion].permiso.duracion==2 || I[posicion].permiso.duracion==1)
    {
        strcpy(tipoduracion,"Dia");
        printff(I, posicion, tipoduracion);
    }
    else if(I[posicion].permiso.duracion == 0)
    {
        strcpy(tipoduracion,"Permanente");
        printff(I, posicion, tipoduracion);
    }
}

void validarDejarPasar(char dejarPasar[])
{
    while( !((strcmp(dejarPasar, "SI") == 0) || (strcmp(dejarPasar, "NO") == 0 )) )
    {
        printf("Las opciones son SI o NO, vuelva a cargar: \n");
        fflush(stdin);
        gets(dejarPasar);
    }
}

void inputDejarPasar(char dejarPasar[])
{
    printf("\n\t Dejar Pasar [SI / NO] \n\n");
    fflush(stdin);
    gets(dejarPasar);
}

void ResumenPartida(stInmigrante inmigrantes[], int validos)
{
    int infiltrados = 0, acertados = 0, fallidos = 0;
    infiltrados = cantidadInfiltrados(inmigrantes, validos);
    acertados = cantidadAcertados(inmigrantes, validos);
    fallidos = cantidadFallidos(inmigrantes, validos);

    system("cls");

    printf("\n\t\t RESUMEN \n\n");

    printf("\t\t INMIGRANTES: %i \n", validos);
    printf("\t\t INFILTRADOS: %i \n", infiltrados);
    printf("\t\t ACERTADOS: %i \n", acertados);
    printf("\t\t FALIDOS: %i \n", fallidos);

    getch();
}

int cantidadInfiltrados(stInmigrante inmigrantes[], int validos)
{
    int i=0, infiltrados=0;

    for(i=0;i<validos;i++)
    {
        if(inmigrantes[i].infiltrado)
        {
            infiltrados++;
        }
    }

    return infiltrados;
}

int cantidadAcertados(stInmigrante inmigrantes[], int validos)
{
    int i=0, acertados=0;

    for(i=0;i<validos;i++)
    {
        if(inmigrantes[i].infiltrado && !inmigrantes[i].visado)
        {
            acertados++;
        }
    }

    return acertados;
}

int cantidadFallidos(stInmigrante inmigrantes[], int validos)
{
    int i=0, fallidos=0;

    for(i=0;i<validos;i++)
    {
        if(inmigrantes[i].infiltrado && inmigrantes[i].visado)
        {
            fallidos++;
        }
    }

    return fallidos;
}

void guardarResumen(stInmigrante inmigrantes[], int validos)
{

    FILE * archi = fopen(historial, "ab");
    stResumenPartida resumen;
    struct tm tm;


    if(archi != NULL)
       {
            resumen.totalInfiltrados = cantidadInfiltrados(inmigrantes, validos);
            resumen.totalInmigrantes = validos;
            resumen.infiltradosAcertados = cantidadAcertados(inmigrantes, validos);
            resumen.infiltradosFallidos = cantidadFallidos (inmigrantes, validos);
            date(&resumen);
            strcpy(resumen.usuario, "test");
            fwrite(&resumen, sizeof(stResumenPartida), 1, archi);
       }
    fclose(archi);
}

void date(stResumenPartida *resumen)
{


    time_t t = time(NULL);
    struct tm tm = * localtime(&t);
    //printf("now: %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    resumen->fecha[0] = tm.tm_mday;
    resumen->fecha[1] = tm.tm_mon + 1;
    resumen->fecha[2] = tm.tm_year + 1900;

}
