d = [(0, 1), (1, 0)]
def dfs(n, i, j, grid, memo):
    if i == n - 1 and j == n - 1:
        return grid[n-1][n-1] 
    if memo[i][j] != -1:
        return memo[i][j]
    res = 0
    for dx, dy in d:
        x = i + dx
        y = j + dy
        if x < n and y < n:
            res = max(res, grid[i][j] + dfs(n, x, y, grid, memo))
    memo[i][j] = res
    return res
def CollectMoney(input1, input2):
    memo = [[-1 for i in range(input1)] for i in range(input1)]
    return dfs(input1, 0, 0, input2, memo)
    
input1 = 4
input2 = [[1, 7, 5 ,2], [5, 12, 3, 6], [100, 9, 23, 16], [16, 4, 5, 9]]
print(CollectMoney(input1, input2))