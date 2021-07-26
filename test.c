#include<stdio.h>
#include<stdlib.h>
#define SWAP(a, b, c)(c t; t = a, a = b, b = t)
unsigned int foo(int a, int b){
    return 1 + a < b ? -1 : foo(a--, b++);
}
int main(){
    printf("%d \n", foo(6, 1));
    printf("%s", "hi");
    return 0;
}