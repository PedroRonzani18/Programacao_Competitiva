while True:
    try: n1, n2 = input().split()
    except (EOFError): break #permite ler todas as linahs dentro do .txt
    except (ValueError): pass # consegue ler até linhas em branco
    else:
        n1, n2 = str(n1), str(n2)
    
    n2 = n2.replace(str(n1),'')

    
    if (len(n2) == 0 or n2.count('0') == len(n2)):
        print('0')
    else:
        print(n2)
    