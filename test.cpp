#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

vector<pair<int,int>> dir = {{-1,-2}, {1,2},{-2,-1},{2, 1},{-2, 1},{2, 1},{-1, 2}, {1, 2}};
bool inside(int A, int B, int x, int y){
    return x >= 0 and x < A and y >= 0 and y < B;
}
int knight(int A, int B, int C, int D, int E, int F) {
    C--, D--, E--, F--;
    vector<vector<int>> v(A, vector<int>(B, 1));
    queue<pair<pair<int,int>,int>> q;
    q.push({{A, B}, 0});
    v[A][B] = 0;
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        int x = p.first.second , y = p.first.first;
        if(x == E and y == F) return p.second;
        for(auto dp : dir){
            int dx = x + dp.second;
            int dy = y + dp.first;
            if(inside(A, B, dx, dy) and v[dx][dy]==1){
                q.push({{dx, dy}, p.second + 1});
                v[dx][dy] = 0;
            }
        }
    }
    return -1;
}
int main(){
    int a, b, c, d, e, f;
    cout << "hp" << endl;
    cin >> a >> b >> c >> d >> e >> f;
    cout << knight(a, b, c, d, e, f) << endl;
    return 0;
}