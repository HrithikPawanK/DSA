def partition(l,h):
    pivot = arr[l]
    i=l;j=h
    while(i<j):
        i+=1
        while(arr[i]<=pivot):
            i+=1
        while(arr[j]>pivot):
            j-=1
        if i<j:
            arr[i],arr[j] = arr[j],arr[i]
    arr[l],arr[j]=arr[j],arr[l]
    return j
def QuickSort(l,h):
    while(l<h):
        j = partition(l,h)
        QuickSort(l,j-1)
        QuickSort(j+1,h)
arr = list(map(int,input().split()))
QuickSort(0,len(arr)-1)
for i in arr:
    print(i)
