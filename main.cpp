#include <iostream>
#include "lib/Abp.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
    Abp arvoreAVL;

    for (int i = 0; i <= 15; i++)
    {
        arvoreAVL.insert(i);
    }

    cout << "Arvore Balanceada:" << endl;
    arvoreAVL.display();
    cout << "Valores e respectivos fatores de balanceamento:\n"
         << endl;
    arvoreAVL.showBalance();

    return 0;
}
