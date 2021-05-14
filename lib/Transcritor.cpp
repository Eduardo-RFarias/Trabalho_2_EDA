#include "Transcritor.hpp"

void lerValores(Abp& arvoreAVL) {
    char nomeArq[50];
    FILE* fp = NULL;

    do {
        printf("Insira o nome do arquivo: ");
        scanf("%s", nomeArq);
        fp = fopen(nomeArq, "r");

        if (fp == NULL) {
            printf("Nome do arquivo invalido. Tente novamente\n");
        } else {
            printf("Arquivo encontrado!\n");
            break;
        }
    } while (fp == NULL);

    char cur[10];
    int c, valor, pos = 0;

    while((c = fgetc(fp)) != EOF) {
        if (c == ',') {
            cur[pos] = '\0';
            pos = 0;
            sscanf(cur, "%d", &valor);
            arvoreAVL.insert(valor);
        } else if (c > 47 && c < 58) {
            cur[pos] = c;
            pos++;
        }
    }
    sscanf(cur, "%d", &valor);
    arvoreAVL.insert(valor);


}