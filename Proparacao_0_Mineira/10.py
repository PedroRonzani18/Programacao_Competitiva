import statistics
import math
import datetime
import collections
from time import perf_counter as clk
import sys

a = None
b = None
c = None

def solve():
    result = str(round(5 * (math.tan(math.radians(a)) * b + c),2))
    partes = result.split('.')
    while(len(partes[1]) < 2): partes[1] += '0' 
    print(f"{partes[0]}.{partes[1]}")

# if __name__ == '__main__':
def main():
    st = clk()

    # lê infinitas linhas agrupadas de 2 em 2
    # pra infinitos valores em 1 linha pode armazenar em uma lista
    while True:
        global a, b, c
        try: a, b, c = input().split()
        except (EOFError): break #permite ler todas as linahs dentro do .txt
        except (ValueError): pass # consegue ler até linhas em branco
        else:
            a, b, c = float(a), float(b), float(c)
        solve()

    sys.stderr.write(f"Run Time : {(clk() - st):.6f} seconds\n")
    
main()