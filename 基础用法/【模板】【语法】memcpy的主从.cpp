#include<iostream>
#include<cstring>
using namespace std;
const int maxn=1012;
int c[maxn],d[maxn];
//�����衢���衢��С 
int main()
{
	c[1]=1;
    memcpy(d,c,sizeof(c));
    cout<<d[1];
}
