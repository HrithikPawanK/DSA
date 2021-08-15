def bubbleSort(arr):
    for i in range(len(arr)-1):
        for j in range(len(arr)-i-1):
            if arr[j]>arr[j+1]:
                arr[j],arr[j+1] = arr[j+1],arr[j]
arr = list(map(int,input().split()))
bubbleSort(arr)
for i in arr:
    print(i,end=" ")
