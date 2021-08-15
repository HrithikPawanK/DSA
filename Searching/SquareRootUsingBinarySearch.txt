x = int(input())
def SquareRootUsingBinarySearch(x):
    l = 1
    h = x
    ans = -1
    while(l<=h):
        mid = (l+h)//2
        midsqr = mid*mid
        if midsqr > x:
            h = mid - 1
        elif midsqr == x:
            return mid
        else:
            l = mid + 1
            ans = mid
    return ans
print(SquareRootUsingBinarySearch(x))
