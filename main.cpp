#include <iostream>
using namespace std;

#include "lib/Menu.hpp"

int main(int argc, char const *argv[])
{
    int option;
    Menu menu;
    menu.show();
    do
    {
        cout << "Digite a Opcao : ";
        cin >> option;
        switch (option)
        {

        case 1:
            for (int i = 1; i < 13; i++)
            {
                cout << i << "\t";
                menu.arvoreAvl.insert(i);
            }
            break;
        case 2:
            menu.arvoreAvl.showBalance();
            break;
        case 3:
            menu.arvoreAvl.display();
            break;
        case 4:
            cout << "";
            break;
        default:
            cout << "ERRO: Opcao invalida\n";
        }
    } while (option != 4);

    return 0;
}
