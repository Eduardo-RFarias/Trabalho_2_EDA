#ifndef MENU
#define MENU

#include <iostream>
using namespace std;

#include "Abp.hpp"
#include "Transcritor.hpp"

class Menu
{
private:
    Abp *arvoreAvl;
    void clear();                    // Limpa o Terminal
    void separaTexto();              //Printa "-"
    void printTitulo(string titulo); // Printa o titulo das opcoes do menu
    void retorna();                  //Retornar a tela inicial

public:
    Menu(bool avl = true);
    ~Menu();
    void show();   //Mostra o menu
    void case_1(); // Gerar ABP
    void case_2(); // Calcular Fator de Balanceamento
    void case_3(); // Imprimir ABP
};

#endif
