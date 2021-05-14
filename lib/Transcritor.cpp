#include "Transcritor.hpp"

void Transcritor::abrirArquivo(string nomeArq)
{
    this->Arquivo.open(nomeArq);
}

void Transcritor::gerarAVL(Abp &arvore)
{
    char cur[10];
    int c, valor, pos = 0;

    while ((c = Arquivo.get()) != EOF) // Percorre arquivo caracter por caracter
    {
        if (c == ',') // Se o caracter for uma virgula, transforma o array em um inteiro e insere ele na árvore.
        {
            cur[pos] = '\0';
            pos = 0;
            sscanf(cur, "%d", &valor);
            arvore.insert(valor);
        }
        else if (c > 47 && c < 58) // Se o caracter for um digito, adiciona ele no array do numero atual.
        {
            cur[pos] = c;
            pos++;
        }
    }

    // Inserindo o último número na árvore.
    sscanf(cur, "%d", &valor);
    arvore.insert(valor);
}

bool Transcritor::isOpen()
{
    return this->Arquivo.is_open();
}
