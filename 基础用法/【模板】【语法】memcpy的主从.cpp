#include<iostream>
#include<cstring>
using namespace std;
const int maxn=1012;
int c[maxn],d[maxn];
//被给予、给予、大小 
int main()
{
	c[1]=1;
    memcpy(d,c,sizeof(c));
    cout<<d[1];
}
