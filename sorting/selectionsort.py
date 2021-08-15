def selectionSort(arr):
    for i in range(len(arr)-1):
        midx = i
        for j in range(i+1,len(arr)):
            if arr[j]<arr[midx]:
                midx = j
        if midx!=i:
            arr[i],arr[midx]= arr[midx],arr[i]
arr = list(map(int,input().split()))
selectionSort(arr)
for i in arr:
    print(i,end=" ")
            