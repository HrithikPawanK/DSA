print("Enter Two Sorted Lists:")
a = list(map(int,input().split()))
b = list(map(int,input().split()))
c = []
i = j = k = 0
while(i<len(a) and j<len(b)):
    if a[i]<b[j]:
        c.append(a[i])
        i+=1
    else:
        c.append(b[j])
        j+=1
while(i<len(a)):
    c.append(a[i])
    i+=1
while(j<len(b)):
    c.append(b[j])
    j+=1
for _ in c:
    print(_)