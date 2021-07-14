#include<bits/stdc++.h>
using namespace std;
int main(){

    // c style strings.

    // last char will be '/0'
    char str[] = "hrithik";
    cout << sizeof(str) << endl;
    cout << str << endl;   
    cout << strlen(str) << endl;
    char s1[] = "abc";
    char s2[] = "bca";
    cout << strcmp(s1, s2) << endl;
    char s3[10];
    // we can't directly assign s3 = "pawan"; because both are addresses.
    strcpy(s3, "pawan");
    cout << s3 << endl;

    // c++ strings

    //they are dynamic
    string  s = "hrithik";
    cout << s.length() << endl;
    s += " pawan";
    cout << s << endl;
    cout << s.substr(1, 4) << endl;
    // find function return the index of first occurrence of the given substring.
    // if not fount it return string::npos which is position not found constant.
    if(s.find("pet")==string::npos){
        cout << "not found" << endl;
    }else{
        cout << "found at: " << s.find("pet") << endl;
    }

    // we can compare two strings lexographically using >, <, == operators.

    // cin for string stops at space
    // ex:  for  hrithik pawan it reads only hrithik
    // inorder to tackle this getline is used. getline(cin, str) it stops at new line i.e when we press enter
    // getline(cin, str, 'a') it stops when 'a' is encountered.

    string name;
    getline(cin, name);
    cout << name << endl;
    for(char c : name){
        cout << c;
    }
    return 0;
}