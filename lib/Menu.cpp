#include "Menu.hpp"

void Menu::show() // Imprime Menu
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
    cin.get();
    clear();
}

void Menu::case_1() // Gerar ABP
{
    if (!arvoreAvl.isEmpty())
    {
        arvoreAvl.reset();
    }

    string nomeArq;
    Transcritor tr;

    clear();
    printTitulo("Gerar ABP");

    do // Validação do nome do arquivo.
    {
        cout << "Insira o nome do arquivo: ";
        cin >> nomeArq;
        tr.abrirArquivo(nomeArq);
        if (tr.isOpen())
        {
            clear();
            separaTexto();
            cout << "Arquivo encontrado!" << endl;
            break;
        }
        else
        {
            cout << "Nome do arquivo invalido. Tente novamente" << endl;
        }
    } while (true);

    tr.gerarAVL(this->arvoreAvl);

    retorna();
}

void Menu::case_2() // Calcular Fator de Balanceamento
{
    clear();
    printTitulo("Calcular Fator de Balanceamento");
    cout << '\t' << "Fator de Balanceamento (Valor:FatBal) : \n"
         << endl;
    arvoreAvl.updateBalFactor();
    retorna();
}

void Menu::case_3() // Imprimir ABP
{
    clear();
    printTitulo("Imprimir ABP");
    arvoreAvl.displayTree();
    retorna();
}