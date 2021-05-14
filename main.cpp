#include <iostream>
using namespace std;
#include "lib/Menu.hpp"

/*
    Grupo :
    - 200056981_Arthur Ferreira Rodrigues
    - 190086521_Eduardo Rodrigues de Farias
    - 200019015_Guilherme Puida Moreira
    - 200042360_Nícolas Roberto de Queiroz
    - 200025937_Paulo Maciel Torres Filho

    README @ https://github.com/Eduardo-RFarias/Trabalho_2_EDA/tree/master
*/

int main(int argc, char const *argv[])
{
    int option;
    Menu menu;

    do
    {
        menu.show(); // Display menu
        cout << "Digite a Opcao : ";
        cin >> option;
        switch (option)
        {
        case 1: // Gerar ABP
            menu.case_1();
            break;
        case 2: // Calcular Fator de Balanceamento
            menu.case_2();
            break;
        case 3: // Imprimir ABP
            menu.case_3();
            break;
        case 4: // Sair
            cout << "Programa Encerrado!";
            break;
        default: // ERRO
            cout << "ERRO: Opcao invalida" << endl;
        }
    } while (option != 4);

    return 0;
}
