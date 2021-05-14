#ifndef MENU
#define MENU

#include <stdio.h>
#include <stdlib.h>

void menu()
{
    printf("\n------------------------------------------------------------\n");
    printf("     Menu\n");
    printf(".1 - Gerar ABP\n");
    printf(".2 - Calcular fator de balanceamento:\n");
    printf(".3 - Imprime ABP:\n");
    printf(".0 - Sair");
    printf("\n------------------------------------------------------------\n");


}

void clear() // Limpa o Terminal
{
    #if defined(_linux) || defined(unix) || defined(APPLE_)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}

void retornaMenu() //Pausa o terminal ate que o usuario aperte enter e volte ao menu
{
    printf("\n------------------------------------------------------------\n");
    printf("Aperte ENTER para voltar ao menu.");

    // Espera uma input do usuario e pausa o terminal
    getchar();
    getchar();
    clear();
}


#endif

