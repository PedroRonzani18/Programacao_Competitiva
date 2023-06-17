def occurrences(string, sub):
    if not sub:
        return 0
    
    count = 0
    index = -1
    while True:
        try:
            index = string.index(sub, index + 1)
            count += 1
        except ValueError:
            return count

input()
orig = input()
nov = input()
quant = int(input())

for _ in range(quant):
    ini, end = input().split()
    ini = int(ini)
    end = int(end)
    
    ini -= 1
    end -= 1
    
    sub = nov[ini:end+1]
    
    print(occurrences(orig, sub))