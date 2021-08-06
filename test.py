ob = [2,1,2,3]
def fun(ob, idx, lane, memo):
    if(idx == len(ob)):
        return 0
    print(memo[idx][lane])
    if(memo[idx][lane]!=-10):
        return memo[idx][lane]
    ans = 1000000000
    if(ob[idx]==lane):
        for i in range(1, 4):
            if(i != lane):
                ans = min(ans, 1 + fun(ob, idx + 1, i, memo))
        memo[idx][lane] = ans
        return ans
    else:
        return fun(ob, idx + 1, lane, memo)

memo = [[-10 for i in range(4)] for j in range(len(ob) + 1)]
print(fun(ob, 0, 2, memo))



