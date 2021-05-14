from random import randint

# formato csv: 1230, 129387, 127, 194, 4, 534

arquivo = open('out/aleatorios.csv', 'w')

tamanho = int(input('digite quantos números você quer no CSV: '))

for i in range(tamanho):
    arquivo.write(str(randint(-10000, 10000)))
    if i != tamanho - 1:
        arquivo.write(', ')

arquivo.close()
