#ifndef MENU
#define MENU

#include <iostream>
using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include "Abp.hpp"

class Menu
{
private:
    void clear();
    void separaTexto();
    void printTitulo(string titulo);
    void retorna();

public:
    Abp arvoreAvl;
    void lerValores();
    void show();
};

#endif
