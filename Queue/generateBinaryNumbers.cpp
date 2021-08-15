#include<bits/stdc++.h>
using namespace std;
// logic first push given digits
// then for iteration pop element and append given digits to popped element add push to queue
// it is similar to level order traversal.
vector<string> generate(int N)
{
	vector<string> ans;
	queue<string> q;
	q.push("1");
	for(int i = 0; i < N; i++){
	    string curr = q.front();
	    q.pop();
	    ans.push_back(curr);
	    q.push(curr + '0');
	    q.push(curr + '1');
	}
	return ans;
}
int main(){
    
    return 0;
}