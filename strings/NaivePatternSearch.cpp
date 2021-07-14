#include<bits/stdc++.h>
using namespace std;
// considering each index as first index and checking the pattern.
// its like sliding window.
// timecomplexity O((n-m+1)*m) 
void patternSearch(string &s, string &pat){
    int n = s.length();
    int m = pat.length();
    for(int i = 0; i <= n - m; i++){
        int j;
        for(j = 0; j < m; j++){
            if(pat[j]!=s[i + j]){
                break;
            }
        }
        if(j == m){
            cout << i << " "; 
        }
    }
    cout << endl;
}
// improved Naive Algorithm if given pattern is distinct.
// time complexity teta(n);
// logic: given a distinct char pat so as characters match we can directly move to the index where it didn't match. for next starting index.
void PatSearchDist(string& s, string& pat){
    int n = s.length();
    int m = pat.length();
    for(int i = 0; i <= n-m;){
        int j;
        for(j = 0; j < m; j++){
            if(pat[j]!=s[i+j]){
                break;
            }
        }
        if(j==m){
            cout << i << " ";
        }
        if(j==0){
            i++;
        }else{
            i = i + j;
        }
    }
    cout << endl;
}
// Rabin Karp Algorithm.
// hashing
// rolling: t_i+1 = d(t_i - txt[i]*(d^(m-1))) + txt[i+m];

#define d 256
const int q = 101;

void RBSearch(string txt, string pat){
    int N = txt.length();
    int M = pat.length();  
    //Compute (d^(M-1))%q
    int h=1;
    for(int i=1;i<=M-1;i++)
        h=(h*d)%q;
    
    //Compute p and to
    int p=0,t=0;
    for(int i=0;i<M;i++){
        p=(p*d+pat[i])%q;
        t=(t*d+txt[i])%q;
    }
    
    for(int i=0;i<=(N-M);i++){
       //Check for hit
       if(p==t){
           bool flag=true;
           for(int j=0;j<M;j++)
                if(txt[i+j]!=pat[j]){flag=false;break;}
            if(flag==true)cout<<i<<" ";
       }
       //Compute ti+1 using ti
       if(i<N-M){
           t=((d*(t-txt[i]*h))+txt[i+M])%q;
        if(t<0)t=t+q;
       }
    }
}
int main(){
    string s, pat;
    getline(cin, s);
    getline(cin, pat);
    patternSearch(s, pat);
    PatSearchDist(s, pat);
    RBSearch(s, pat);
    return 0;
}