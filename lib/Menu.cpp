#include "Menu.hpp"

void Menu::show()
{

    printTitulo("Menu");
    cout << ".1 - Gerar ABP" << endl
         << ".2 - Calcular fator de balanceamento:" << endl
         << ".3 - Imprime ABP:" << endl
         << ".4 - Sair" << endl;
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
    cout << endl
         << "------------------------------------------------------------" << endl;
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

void Menu::lerValores()
{
    string nomeArq;
    FILE *fp = NULL;

    do
    {
        cout << "Insira o nome do arquivo: ";
        cin >> nomeArq;
        fp = fopen(nomeArq.c_str(), "r");

        if (fp == NULL)
        {
            cout << "Nome do arquivo invalido. Tente novamente" << endl;
        }
        else
        {
            cout << "Arquivo encontrado!" << endl;
            break;
        }
    } while (fp == NULL);

    char cur[10];
    int c, valor, pos = 0;

    while ((c = fgetc(fp)) != EOF)
    {
        if (c == ',')
        {
            cur[pos] = '\0';
            pos = 0;
            sscanf(cur, "%d", &valor);
            this->arvoreAvl.insert(valor);
        }
        else if (c > 47 && c < 58)
        {
            cur[pos] = c;
            pos++;
        }
    }
    sscanf(cur, "%d", &valor);
    this->arvoreAvl.insert(valor);
}
