#include "Menu.hpp"

void Menu::show()
{

    printTitulo("Menu");
    cout << ".1 - Gerar ABP\n"
         << ".2 - Calcular fator de balanceamento:\n"
         << ".3 - Imprime ABP:\n"
         << ".0 - Sair";
    separaTexto();
}

void Menu::clear() // Limpa o Terminal
{
#if defined(_linux) || defined(unix) || defined(APPLE_)
    system("clear");
#endif

#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#endif
}

void Menu::separaTexto() // Imprime uma serie de - para separar o texto
{
    cout << "\n------------------------------------------------------------\n";
}

void Menu::printTitulo(string titulo) // Formata Titulo ao meio da pagina
{
    int tamTexto, tamDivisor;
    int quantEspacos, i;
    tamTexto = titulo.length();
    tamDivisor = 60;

    separaTexto();

    quantEspacos = (tamDivisor - tamTexto) / 2;
    for (i = 0; i < quantEspacos; i++)
    {
        cout << " ";
    }
    cout << titulo;

    separaTexto();
}

void Menu::retorna() //Pausa o terminal ate que o usuario aperte enter e volte ao menu
{
    separaTexto();
    cout << "Aperte ENTER para voltar ao menu.";

    // Espera uma input do usuario e pausa o terminal
    cin.get();
    //cin.get();
    clear();
}
