# https://www.beecrowd.com.br/judge/pt/problems/view/1936

num = int(input())
quant = 0

fatoriais = []
fatoriais.append(1)

for i in range(1,11):
    fatoriais.append(fatoriais[i-1] * i)

while True:
    for i in range(1, num+1):
        if fatoriais[i+1] > num and fatoriais[i] <= num:
            quant += 1
            num -= fatoriais[i]
            break
    if(num == 0): break
    
print(quant)