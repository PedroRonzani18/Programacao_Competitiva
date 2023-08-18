import string
alphabet = list(string.ascii_lowercase)

num = int(input())

for i in range(num):
    frase = input()
    freq = list()
    
    for j in range(26):
        freq.append(0)
        
    for letra in frase:
        try: ind = alphabet.index(letra)
        except (ValueError): pass
        else: freq[ind] += 1
        
    conta = 0
    for x in freq:
        if(x != 0): conta += 1
        
    if(conta == 26): print("frase completa")
    elif(conta > 12): print("frase quase completa")
    else: print("frase mal elaborada")