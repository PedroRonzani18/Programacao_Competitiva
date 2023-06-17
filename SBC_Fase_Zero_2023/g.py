linhas = int(input())

lista = []
adicionar = []
for i in range(linhas):
    linha = input()

    j = 1
    while(j <= len(linha)):


        adicionar.append(linha[j-1])

        tent = ''
        tent += linha[j-1]
        if(j != len(linha)): 
            tent += linha[j]

        if(tent in [', ',',,', '. ','..', ',.', ' ,', ' .', '.,']):
            adicionar.pop()

            adicionar_str = ''

            for x in adicionar:
                adicionar_str += x

            lista.append(adicionar_str)
            
            adicionar = []

        j += 1

adicionar_str = ''

for x in adicionar:
    adicionar_str += x

lista.append(adicionar_str)

for index in range(len(lista)):
    lista[index] = str(lista[index]).strip()

# print('lista:',lista)

# separar numeros isolados

lista_intervalos = []
adicionar = []
for possibilidade in lista:
    lista_numeros_separados = []
    j = 0
    for j in range(len(possibilidade)):

        adicionar.append(possibilidade[j])
    
        if(possibilidade[j] in [' ', '.', ',']):
            
            if not(str(possibilidade[j-1]).isnumeric() and str(possibilidade[j+1]).isnumeric()):
                adicionar.pop()

                adicionar_str = ''

                for x in adicionar:
                    adicionar_str += x
                    
                if(str(adicionar_str).isnumeric()):
                    lista_numeros_separados.append(adicionar_str)
                    
                adicionar = []
                
    if(len(adicionar) > 0):
        adicionar_str = ''

        for x in adicionar:
            adicionar_str += x
            
        lista_numeros_separados.append(adicionar_str)
            
        adicionar = []
    
# todos os numeros sao guardados com separadores entre
    
    if len(lista_numeros_separados) > 0: 
        lista_intervalos.append(lista_numeros_separados.copy())

adicionar_str = ''

for x in adicionar:
    adicionar_str += x
    
if(str(adicionar_str).isnumeric()):
    lista_numeros_separados.append(adicionar_str)
    
    if len(lista_numeros_separados) > 0: lista_intervalos.append(lista_numeros_separados.copy())

# print('lista_intervalos:',lista_intervalos)
# remove os casos ai dentro q n tem nenhum numero

lista_intervalos_nova = []

for l_num in lista_intervalos:
    for num in l_num:
        encontrou = False
        for cas in num:
            if (str(cas).isnumeric()):
                encontrou = True
                
        if(encontrou):
            lista_intervalos_nova.append(num)
        
# print(lista_intervalos_nova)

nova_lista_sem_sep = []

for num in lista_intervalos_nova:
    num_novo = ''
    for casa in num:
        if str(casa).isnumeric(): num_novo += casa
    if(len(num_novo) > 0): nova_lista_sem_sep.append(num_novo)
    
# print(nova_lista_sem_sep) 

numeross = []

for number in nova_lista_sem_sep:
    numeross.append(int(number))

# print(numeross)

if(len(numeross) < 3): 
    print(':)')
    exit()

passou = True
for xx in range(len(numeross)-1):
    if(numeross[xx] + 1 != numeross[xx+1]): passou = False
    
if(passou): print(123)
else: print(':)')