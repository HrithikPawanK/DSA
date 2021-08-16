# two pointer approach
# Finding whether a pair is present with given summ

# note: --> if the array is sorted its better to use two pointer because
# it takes s(1) auxilary space where as hash takes s(n) auxilary space.
# --> if arrays is unsorted its better to use hash because it takes O(n)
# where as in two pointer we need to sorted first so it takes O(nlogn)
# so it is not efficient.

arr = list(map(int,input().split()))
summ = int(input())

# is pair
def isPair(arr,summ):
    l = 0
    r = len(arr) - 1
    while(l<r):
        if arr[l] + arr[r] > summ:
            r = r -1
        elif arr[l] + arr[r] < summ:
            l = l + 1
        else:
            return True
    return False
print(isPair(arr,summ))

# is triplet

arr = list(map(int,input().split()))
summ = int(input())
def isPair(arr,summ,l,r):
    while(l<=r):
        if arr[l] + arr[r] > summ:
            r = r -1
        elif arr[l] + arr[r] < summ:
            l = l + 1
        else:
            return True
    return False

def isTriplet(arr,summ):
    for i in range(len(arr)):
        if isPair(arr,summ-arr[i],i+1,len(arr)-1):
            return True
    return False
print(isTriplet(arr,summ))

# timecomplexity--> O(n2)
# even if array is unsorted we can sort and apply this logic
# because O(nlogn)(for sorting) + O(n2) for this approach ==> O(n2)


#count is pair --> number of pairs with given sum

def CountIsPair(arr,summ):
    count = 0
    l = 0
    h = len(arr) - 1
    while(l < h):
        if arr[l] + arr[h] == summ:
            l += 1
            h -= 1
            count += 1
            print(arr[l],arr[h])
        elif arr[l] + arr[h] < summ:
            l += 1
        else:
            h -= 1
    return count

# CountIsTriplet --> count no of triplets with given sum

def CountIsPair(x,arr,summ,l,h):
    count = 0
    while(l < h):
        if arr[l] + arr[h] == summ:
            l += 1
            h -= 1
            if l==h:
                break
            count += 1
            print(x,arr[l],arr[h])
        elif arr[l] + arr[h] < summ:
            l += 1
        else:
            h -= 1
    return count

def CountIsTriplet(arr,summ):
    count = 0
    for i in range(len(arr)):
        count += CountIsPair(arr[i],arr,summ-arr[i],i+1,len(arr)-1)
    return count

print(CountIsTriplet(arr,summ))

# to check if there is a triplet such tha c2 = a2 + b2

def ispair(arr,c,l,h):
    while(l<h):
        if arr[l]**2 + arr[h]**2 == c**2:
            return True
        elif arr[l]**2 + arr[h]**2 < c**2:
            l += 1
        else:
            h -= 1
def triplet(arr):
    for i in range(len(arr)-1,-1,-1):
        if ispair(arr,arr[i],0,i-1):
            return True
    return False
    



    
