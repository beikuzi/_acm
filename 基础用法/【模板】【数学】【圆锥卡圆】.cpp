#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
    double r,a,b,h;
    cin>>r>>a>>b>>h;
    double x=b*h/(a-b);//ʵ�ʶ��ڵ�λ�� 
    double t=2*r*sqrt((h+x)*(h+x)+(a/2)*(a/2))/a;//Ӧ����ס��λ��
    if(t<=x)cout<<"Drop";
    else {
    	cout<<"Stack\n";
    	printf("%.10lf",t-x);
    }
}
