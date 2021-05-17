from random import randint

# formato csv: 1230, 129387, 127, 194, 4, 534

arquivo = open('aleatorios.csv', 'w')

# Modifique aqui
tamanho = 10
intervalo = 50
# ---------------

for i in range(tamanho - 1):
    arquivo.write(str(randint(-intervalo, intervalo)))
    arquivo.write(', ')

arquivo.write(str(randint(-intervalo, intervalo)))
arquivo.close()
