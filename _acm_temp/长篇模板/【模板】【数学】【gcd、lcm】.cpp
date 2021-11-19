//最小公倍数*最大公约数=两原数乘积 p*q=x*y
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int gcd(int x,int y)
{
	return y?gcd(y,x%y):x; 
}
int lcm(int x,int y){
	return x*y/gcd(x,y);
}
int main()
{
	int x=gcd(20,30);
	int y=lcm(20,30);
	printf("%d\n%d",x,y);
}
