#include<iostream>
#include<fstream>
#include<cstdio> 
using namespace std;
ofstream kout;
void redirect_fout(string s)
{
	kout.close();
	if(s.empty())return;
	kout.open(&s[0]);
}
void redirect_Fin(string s)
{
	FILE *fin;
	fin=fopen("123.txt","r");
}
int main()
{
    freopen("test.abc","r",stdin);;
}
