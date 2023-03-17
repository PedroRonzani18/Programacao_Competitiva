import statistics
import math
import datetime
import collections
from time import perf_counter as clk
import sys

def ident(*args):
    """ Always returns the same value that was used as its argument.
    """
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
    # while(cin >> x >> y)
    while True:
        try: n1, n2 = input().split()
        except (EOFError): break #permite ler todas as linahs dentro do .txt
        except (ValueError): pass # consegue ler até linhas em branco
        else:
            n1, n2 = int(n1), int(n2)

    # int l; cin >> l; while(l--){for(i=0; i<vpl; i++)}
    # retorna listas com inputs de cada linha
    parsin(l=2, vpl=5) 

if __name__ == '__main__':
    st = clk()

    n = 1
    # n = int(input())
    while(n>0):
        solve()
        n-=1   
    
    sys.stderr.write(f"Run Time : {(clk() - st):.6f} seconds\n")