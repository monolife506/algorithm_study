M = int(input()); N = int(input())
min_decimal = 0; total = 0
decimals = [True for i in range(N + 1)]
decimals[0] = False; decimals[1] = False
for num, isdecimal in enumerate(decimals) :
    if (isdecimal == False) : continue
    else : 
        multi = 2
        while (num * multi <= N) :
            decimals[num * multi] = False
            multi += 1
for i in range(M, N + 1) :
    if (decimals[i] == True and min_decimal == 0) : 
        min_decimal = i; total += i
    elif (decimals[i] == True) : total += i
if (total == 0) : print(-1) 
else : 
    print(total); print(min_decimal)