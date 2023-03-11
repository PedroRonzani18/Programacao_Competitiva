import string
letras = list(string.ascii_uppercase)

casos = int(input())

for _ in range(casos):
    etradas = str(input()).split()
    
    desloc = int(etradas[0])
    frase = etradas[1]

    for let in frase:
        novo = int(letras.index(let) + desloc)
        
        if(novo < len(letras)):
            print(letras[novo],end='')
            
        else:
            certo = novo - len(letras)
            print(letras[certo], end='')
    print()