arr = list(map(int,input().split()))
def countFirstOccurrenceOfOne(arr):
    l = 0
    h = len(arr)-1
    while(l<=h):
        mid = (l+h)//2
        if arr[mid] == 0:
            l = mid + 1
        else:
            if mid == 0 or arr[mid-1] != 1:
                return mid
            else:
                h = mid - 1
    return -1
print(count1(arr))
