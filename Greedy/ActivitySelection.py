''''
minimum coins required to form a amount 

greedy may not work always

here greedy is to take maximum elements first '''

coins = list(map(int,input().split()))
res = int(input())
coins.sort(reverse=True)
count = 0
i = 0
while(res!=0 and i < len(coins)):
    q = res//coins[i]
    count += q
    res -= q*coins[i]
    i += 1
print(count)

def ActivitySelection(l):
    l.sort(key = lambda x:x[1])
    prev = l[0]
    count = 1
    for i in range(1,len(l)):
        if l[i][0] >= prev[1]:
            prev = l[i]
            count += 1
    return count
s = list(input())
print(s)

