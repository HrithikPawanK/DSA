def searchInInfiniteSortedArray(arr,x):
    if arr[0] == x:
        return 0
    i = 1
    while(arr[i] < x):
        i = i*2
    if(arr[i] == x):
        return i
    else:
        return binarySearch(arr,x,i/2 +1,i-1)

# time complexity O(log(pos))
# because for position its traverses 2*pos which is log(2*pos)
# and for binary search it again takes log(pos)