#include<bits/stdc++.h>
using namespace std;
// placing n queens in NXN board so that no two queens kill each other.

// logic: for every col we fix one row then search for col + 1 and again fix one row untill it satisfies the condition. if it does not 
// satisfy then backtrack

// is safe checks whether queen is already present in current row, its diagonals 
// it checks only for the prev cols because only those are filled.
bool isSafe(vector<vector<bool>> &board, int row, int col, int n){
    for(int i = col-1; i >= 0; i--){
        if(board[row][i]) return false;
    }
    for(int i = row-1, j = col-1; i >= 0 and j >= 0; i--, j--){
        if(board[i][j]) return false;
    }
    for(int i = row+1, j = col-1; i < n and j >= 0; i++, j--){
        if(board[i][j]) return false;
    }
    return true;
}
bool solveRecur(vector<vector<bool>> &board, int col, int n){
    if(col == n){
        return true;
    }
    for(int i = 0; i < n; i++){
        if(isSafe(board, i, col, n)){
            board[i][col] = 1;
            if(solveRecur(board, col + 1, n)) return true;
            board[i][col] = 0; 
        }
    }
    return false;
}
void printMatrix(vector<vector<bool>> &board, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}   
void solve(int n){
    vector<vector<bool>> board(n, vector<bool>(n, 0));
    if(solveRecur(board, 0, n)){
        cout << "YES" << endl;
        printMatrix(board, n);
        return;
    }
    cout << "NO" << endl;
    return;
}
int main(){
    int n;
    cin >> n;
    solve(n);
    return 0;
}