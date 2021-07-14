#include<bits/stdc++.h>
using namespace std;
// matrix is given with 1's and 0's 
// 0 means blocked. 1 means free
// rat should go from top left cornter to bottom right corner.
// moves allowed are i+1,j or i, j+1 i.e move left or down.
void printMatrix(vector<vector<bool>> &sol, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
}
bool isSafe(vector<vector<bool>> &maze, int i, int j, int n){
    return i < n and j < n and maze[i][j] == 1;
}
bool solveMazeRecur(vector<vector<bool>> &maze, int i, int j, int n, vector<vector<bool>> &sol){
    if(i==n-1 and j==n-1){
        sol[i][j] = 1;
        return true;
    }
    if(isSafe(maze, i, j, n)){
        sol[i][j] = 1;
        if(solveMazeRecur(maze, i+1, j, n, sol)) return true;
        if(solveMazeRecur(maze, i, j+1, n, sol)) return true;
        sol[i][j] = 0;
    }
    return false;
}
void solveMaze(vector<vector<bool>> &maze, int n){
    vector<vector<bool>> sol(n, vector<bool>(n));
    if(solveMazeRecur(maze, 0, 0, n, sol)){
        cout << "YES" << endl;
        printMatrix(sol, n);
    }
    else{
        cout << "NO" << endl;
    }
}
int main(){
    int n;
    cin >> n;
    vector<vector<bool>> maze(n, vector<bool>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int x;
            cin >> x;
            maze[i][j] = x;
        }
    }
    solveMaze(maze,n);
    return 0;
}