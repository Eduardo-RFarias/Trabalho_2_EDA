#ifndef MENU
#define MENU

#include <iostream>
using namespace std;

#include "Abp.hpp"

class Menu
{
private:
    Abp arvoreAvl;
    void clear();
    void separaTexto();
    void printTitulo(string titulo);
    void retorna();

public:
    void show();
};

#endif
