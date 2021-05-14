#include <iostream>
#include "lib/Abp.hpp"
#include "lib/Menu.h"
using namespace std;

int main(int argc, char const *argv[])
{
    Abp arvoreAVL;

    int inputMenu;

    do
    {
        menu();

        do
        {
            printf("Selecionar : ");
            scanf("%d", &inputMenu);

            if(inputMenu<0 || inputMenu>3)
            {
                printf("\n------------------------------------------------------------\n");
                printf("Erro: Selecione uma opcao valida!");
                printf("\n------------------------------------------------------------\n");
            }
        }
        while(inputMenu<0 || inputMenu>0);

        clear();

        switch(inputMenu)
        {
            case(1):

                break;

            case(2):

                break;

            case(3):

                break;

            case(0):

                printf("Programa Encerrado");

                return 0;

                break;

            return 0;
        }
        retornaMenu();
    }while(1);





}
