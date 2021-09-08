#include<iostream>
#include<cstdio>
using namespace std;
string happy="0123456789ABCDEF";
const int base=3;
void f(int x,int b){
	if(x/b)f(x/b,b);
	printf("%c",happy[x%b]);
}
int main()
{
    int n;scanf("%d",&n);
    f(n,base);
    return 0;
}
