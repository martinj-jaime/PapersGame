#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

#include "prototypes.h"

#define MenuInicio 1
#define MenuFin 3
#define LineaInicio 1

int main()
{
    srand(time(NULL));
    stResumenPartida resumen;
    /** Usuarios **/
    stUsuarios usuarios;
    iniciarSesion(&usuarios);
    //getch();

    /** Inmigrantes **/
    int cantInmigrantes = 0;
    stInmigrante inmigrantes[CANT_INMIGRANTES];

    int opMenu = Menu(cantInmigrantes, inmigrantes);

    if(opMenu==1)
    {
        SelectCantInmigrantes(&cantInmigrantes);
        randomizarInmigrantes(inmigrantes, cantInmigrantes);
        printf("\t\t  J U G A R  \n");
        getch();
        Principal(inmigrantes, cantInmigrantes);
    }
    if(opMenu==2)
    {
        Historial();
        getch();
    }
    if(opMenu==3)
    {
        printf("\t opcion 3 \n");
        getch();

    }

    getch();
    return 0;
}

int Menu(int * cantInmigrantes, stInmigrante inmigrantes[])
{

    system("cls");

    int Menu = 0;
    // Logo();
    goY(LineaInicio);
    printf("\t Seleccionar cant de inmigrantes \n");
    printf("\t Ver historial \n");
    printf("\t Vista admin (oculto) \n");

    Menu = 1;
    goY(LineaInicio);
    printf("--->");


    while(1)
    {
        Sleep(200);


        if(GetAsyncKeyState(VK_UP))
        {
            Menu = Menu == MenuInicio ? MenuFin : --Menu;
            printf("\r     ");
            goY(LineaInicio + Menu-1);
            printf("--->");
        }
        else if(GetAsyncKeyState(VK_DOWN))
        {
            Menu = Menu == MenuFin ? MenuInicio : ++Menu;
            printf("\r     ");
            goY(LineaInicio + Menu-1);
            printf("--->");
        }
        else if(GetAsyncKeyState(VK_RETURN))
        {

            break;
        }
    }

    printf("\n\n\n\n\n");

    return Menu;
}

void Historial()
{
    system("cls");
    FILE * archi = fopen(historial, "rb");
    stResumenPartida resumen;
    if(archi != NULL)
    {
        while (fread(&resumen, sizeof(stResumenPartida), 1, archi) > 0)
        {
            mostrarHistorial(resumen);
        }
        getch();
    }
    fclose(archi);
}

void mostrarHistorial(stResumenPartida resumen)
{

    printf("\t   ______________________________________________\n");
    printf("\t   |          %s                               | \n", resumen.usuario);
    printf("\t   |   Fecha : %i/%i/%i                        | \n", resumen.fecha[0], resumen.fecha[1], resumen.fecha[2]);
    printf("\t   |   Total Inmigrantes: %i                    | \n", resumen.totalInmigrantes);
    printf("\t   |   Inmigrantes Infiltrados: %i               | \n", resumen.totalInfiltrados);
    printf("\t   |   Infiltrados Acertados: %i                 | \n" , resumen.infiltradosAcertados);
    printf("\t   |   Infiltrados Fallidos: %i                  | \n", resumen.infiltradosFallidos);
    printf("\t   |____________________________________________| \n");
}

void iniciarSesion(stUsuarios * user)
{

    int num = 0;
    FILE * archi = fopen(USER, "a+b");

    printf("Ya tengo cuenta = 1 \n");
    printf("Registrarse = 2\n");
    scanf("%i", &num);

    if (num == 1)
    {
        login (archi, &user);

    }


    if (num == 2)

    {
        registrarse(archi, &user);
    }

    fclose(archi);
}

void login (FILE * archi, stUsuarios * user)
{
   system("cls");
   int flag = 0, num =0;
    char name[TAM];
    char password[TAM];
   if (archi != NULL)
   {

      while (flag == 0)
      {
        printf("\n Ingrese el nombre de usuario: \n");
        fflush(stdin);
        gets(name);

        flag = buscarUser(name);
        if (flag == 1)
        {
            break;
        }

        printf ("\n Usuario incorrecto.\n Intentar de nuevo = 1.\n Registrarse = 2.\n");
        scanf("%i",&num);

        if (num == 2)
            {
                goto registrarse;
                registrarse: registrarse(archi, &user);

            }
        }

   }
}

void registrarse(FILE * archi, stUsuarios * user)
{
    system("cls");
    char name[TAM];
    char password[TAM];




    archi = fopen(USER, "ab");

    if (archi!= NULL)
    {
        printf("\n Ingrese un nombre de usuario valido: [MAX 41 CARACTERES]\n");
        fflush(stdin);
        gets(name);
        controlString(name);

        while (buscarUser(name))
        {
           printf("\n El nombre de usuario ya existe, porfavor ingrese otro nombre.\n");
           fflush(stdin);
            gets(name);
            controlString(name);
        }

        printf("\n Ingrese una contraseña \n");
        fflush(stdin);
        gets(password);
        controlString(password);

        strcpy(user->nombre, name);
        strcpy(user->password, password);

        fwrite(user, sizeof(stUsuarios), 1, archi);
    }
    fclose(archi);

}

int buscarUser(char name[TAM])
{
    FILE * archi = fopen(USER, "rb");
    int flag = 0;
    stUsuarios user;


    if (archi != NULL)
    {
        while (fread(&user, sizeof(stUsuarios), 1, archi) > 0 && flag == 0)
            {
                if (strcmp(name, user.nombre) == 0)
                {
                    flag = 1;
                }

            }
    }
    fclose(archi);

    return flag;
}

void controlString(char x[])
{

    while (strlen(x) > TAM)
    {
        printf("\n MAXIMO DE CARACTERES SUPERADO, VUELVE A INTENTARLO.\n");
        fflush(stdin);
        gets(x);
    }
}
