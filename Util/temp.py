import statistics
import math
import datetime
import collections
from time import perf_counter as clk
import sys

a = None
b = None
lista = None

def ident(*args):
    if len(args) == 1: 
        return args[0]
    return args


def parsin(*, l=1, vpl=1, s=" "):
    if l == 1:
        if vpl == 1: return ident(input())
        else: return list(map(ident, input().split(s)))
    else:
        if vpl == 1: return [ident(input()) for _ in range(l)]
        else: return [list(map(ident, input().split(s))) for _ in range(l)]


def solve():
    pass

# if __name__ == '__main__':
def main():
    st = clk()
    
    escolha = "in"
    #escolha = "num"
    
    match escolha:
        case "in":
            # lê infinitas linhas agrupadas de 2 em 2
            # pra infinitos valores em 1 linha pode armazenar em uma lista
            while True:
                global a, b
                try: a, b = input().split()
                except (EOFError): break #permite ler todas as linahs dentro do .txt
                except (ValueError): pass # consegue ler até linhas em branco
                else:
                    a, b = int(a), int(b)
                solve()
    
        case "num":
            global lista
            # int l; cin >> l; while(l--){for(i=0; i<vpl; i++)}
            # retorna listas com inputs de cada linha
            # leia l linhas com vpl valores em cada uma delas
                # caseo seja mais de uma linha, retorna lista com listas de inputs
            lista = parsin(l=2, vpl=5) 
            solve()
    
    sys.stderr.write(f"Run Time : {(clk() - st):.6f} seconds\n")
    
main()