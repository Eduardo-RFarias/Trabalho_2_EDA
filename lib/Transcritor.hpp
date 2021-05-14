#ifndef TRANSCRITOR
#define TRANSCRITOR

#include <iostream>
#include <fstream>
#include "Abp.hpp"
using namespace std;

class Transcritor
{
private:
    ifstream Arquivo;

public:
    void abrirArquivo(string nomeArq);
    void gerarAVL(Abp &arvore);
    bool isOpen();
};

#endif