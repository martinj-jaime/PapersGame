#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include "prototypes.h"

void randomizarInmigrantes(stInmigrante inmigrantes[], int cantInmigrantes)
{
    char aux;
    int num=0;
    int edad_random=0;
    int i=0;

    /** Funcion de Randomizacion **/
    for(i=0;i<cantInmigrantes;i++) {
        /** Randomiza Pasaporte **/
        inmigrantes[i].genero=random_genero();

        random_nombre(inmigrantes, i);

        random_apellido(inmigrantes, i);

        inmigrantes[i].dni=random_dni();

        inmigrantes[i].diaNacimineto=random_dia();
        inmigrantes[i].mesNacimineto=random_mes();
        inmigrantes[i].anoNacimineto=random_ano();

        edad_random=random_edad(inmigrantes, i);
        inmigrantes[i].edad=edad_random;

        random_zona(inmigrantes, i);

        inmigrantes[i].vencimientoDNI=random_vencimiento();

        inmigrantes[i].genero=random_genero();

        /** Randomiza Permiso **/
        strcpy(inmigrantes[i].permiso.nombre, inmigrantes[i].nombre);

        strcpy(inmigrantes[i].permiso.apellido, inmigrantes[i].apellido);

        inmigrantes[i].permiso.dni = inmigrantes[i].dni;

        random_proposito(inmigrantes, i);

        random_duracion(inmigrantes, i);

        /** por default no es infiltrado **/
        inmigrantes[i].infiltrado = 0;

        /** Randomiza con un error (Si es infiltrado) **/
        random_error(inmigrantes, i);
    }
}

int random_dni()
{
    int num=0;
    int dni_random=0;
    int multiplo=1;

    for(int i=0; i<8; i++)
    {
        num=rand()%9;
        num=num*multiplo;
        dni_random=dni_random+num;
        multiplo=multiplo*10;
    }

    return dni_random;
}

int random_dia()
{
    int dia_random;

    do
    {
        dia_random=rand()%29;
    }
    while(dia_random ==0);

    return dia_random;
}

int random_mes()
{
    int mes_random;

    do
    {
        mes_random=rand()%12;
    }
    while(mes_random ==0);

    return mes_random;
}

int random_ano()
{
    int num=0;
    int ano_random=1700;
        num=((rand()%50)+70);
    ano_random=ano_random+num;

    return ano_random;
}

int random_edad(stInmigrante inmigrante[], int i)
{
    int edad=FECHA_JUEGO;

    edad=edad-inmigrante[i].anoNacimineto;

    return edad;
}

void random_zona(stInmigrante inmigrante[], int i)
{
    int num=0;
    char aux[15];
    char zonas[10][15]= {"Imporia","Doffensmirt","Jaimist","Arstotzka","Union Federal","Kolechia","Antegria","Rodtriz","Obristán","Noggrs"};
    num=rand()%9;
    strcpy(inmigrante[i].zona,zonas[num]);
}

int random_vencimiento()
{
    int num=0;
    int vencimiento_random=1770;
    num=((rand()%50)+70);
    vencimiento_random=vencimiento_random+num;

    return vencimiento_random;
}

char random_genero()
{
    int num=0;
    char hombre='M';
    char mujer='F';
    num=((rand()%2)+1);
    if(num==1)
    {
     return hombre;
    }
    else if(num==2)
    {
    return mujer;
    }
}

void random_nombre(stInmigrante inmigrante[], int contador)
{
    int num=0;
    char hombres[][TAM]= {"Alek","Alexey","Dmitry","Faddei","Jasha","Mijail","Nikolay","Gavrel","Yuri","Alexander"};
    char mujeres[][TAM]= {"Anna","Calina","Dasha","Irina","Karenina","Kira","Laika","Natascha","Tasya","Zaria"};
    num=rand()%9;

    if(inmigrante[contador].genero=='M')
    {
        strcpy(inmigrante[contador].nombre, hombres[num]);
    }
    else if(inmigrante[contador].genero=='F')
    {
        strcpy(inmigrante[contador].nombre, mujeres[num]);
    }
}

void random_apellido(stInmigrante inmigrante[],int contador)
{
    // srand(time(NULL));
    int num=0;
    char apellidos[10][15]= {"Jaimist","Rodtriz","Noggrs","Nicoletich","Rojtz","Royolit","Garatz","Mariz","mir","Zevs"};
    num=rand()%9;

    strcpy(inmigrante[contador].apellido,apellidos[num]);
}

void random_proposito(stInmigrante inmigrantes[], int i)
{
    int num=0;

    char proposito[4][TAM]= {"Vacaciones","Trabajo","Inmigrar","Escala"};
    num=rand()%4;

    strcpy(inmigrantes[i].permiso.proposito, proposito[num]);
}

void random_duracion(stInmigrante inmigrantes[], int i)
{
    int num=0;

    if(strcmp(inmigrantes[i].permiso.proposito, "Vacaciones")==0)
    {
        inmigrantes[i].permiso.duracion=((rand()%21)+9);
    }
    else if(strcmp(inmigrantes[i].permiso.proposito, "Trabajo")==0)
    {
        inmigrantes[i].permiso.duracion=((rand()%6)+3);
    }
    else if(strcmp(inmigrantes[i].permiso.proposito, "Escala")==0)
    {
        inmigrantes[i].permiso.duracion=((rand()%2));
    }
    else if(strcmp(inmigrantes[i].permiso.proposito, "Inmigrar")==0)
    {
        inmigrantes[i].permiso.duracion=0;
    }
}

int randomizar_edad()
{
    int num=0;
    int edad_random=0;

    do
    {
        num=((rand()%60)+20);
    }
    while(num ==0);
    edad_random=edad_random+num;

    return edad_random;
}


void random_error(stInmigrante inmigrante[], int i)
{
    int num=0;
    int infiltrado=0;

    /** Hay una probabilidad del 33% de que sea infiltrado **/
    infiltrado=rand()%3;

    /** Es infiltrado **/
    if(infiltrado==2)
    {
        inmigrante[i].infiltrado = 1;

        /** Carga un error **/
        num = ((rand()%5)+1);

        /** printf de test **/
        printf("Infiltrado pos %i ERROR %i \n", i, num);


        /** 1: DNI pasaporte **/ // funciona
        if(num==1)
        {
            inmigrante[i].dni=random_dni();
        }
        /** 2: DNI permiso **/ // funciona
        else if(num==2)
        {
            inmigrante[i].permiso.dni=random_dni();
        }

        /** 3: NOMBRE pasaporte **/ // funciona
        else if(num==3)
        {
            random_nombre(inmigrante, i);
        }

        /** **/
        else if(num==5)
        {
            inmigrante[i].edad=randomizar_edad();
        }

        /** NUM 4 NO TIENE SENTIDO **/
        else if(num==4)
        {

            if(inmigrante[i].genero=='M')
            {
                inmigrante[i].genero='F';
            }
            else if(inmigrante[i].genero=='F')
            {
                inmigrante[i].genero='M';
            }
        }
    }
}







