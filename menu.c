#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

#include "prototypes.h"

void goY(int y)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD pos;
    pos.X = 0;
    pos.Y = y+3;

    SetConsoleCursorPosition(hConsole, pos);
}

void Logo()
{
    printf(" L O G O \n");
}

void SelectCantInmigrantes(int * cantInmigrantes)
{
    printf("\t Ingrese la cantidad total de inmigrantes con los que desea jugar: \n");
    printf("\t 10 | 20 | 30 \n");
    scanf("%i", cantInmigrantes);
    while(!(*cantInmigrantes == 10 | *cantInmigrantes == 20 | *cantInmigrantes == 30))
    {
        printf("Numero de inmigrantes para jugar incorrecto. \n");
        printf("Por favor cargue un numero entre el rango de valores \n");
        scanf("%i", cantInmigrantes);
    }
}








