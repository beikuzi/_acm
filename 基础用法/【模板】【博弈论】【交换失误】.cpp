#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
typedef long long ll;
//������a��b�����֣��ɹ�������+1��ʧ��Է�+1����˫���÷�a��b������£��м���ʧ�����
 
//����0��Ȼ���������������ż�������е� ֵ���2����Ϊmin(a,b) �ǿ����ȶ�ʧ��� ��һʧ���Ҫ˫����ʧ�������� 
//�����������˭�ȷ���Ϳ��Ծ���ʧ��/��ʧ�� ����ֵ���1 
//cmin=abs(b-a)/2;//����ʧ��ʣ��ʧ��ǿ��һ��,����ȡ�� 
//cmax=(abs(b-a)+1)/2+min(a,b)*2;//min(a,b����ʧ��,ǿ��һ������ȡ�� 
void solve(){
	int a,b;
	scanf("%d%d",&a,&b);
    int cmin,cmax;
    cmin=abs(b-a)/2;//����ʧ��ʣ��ʧ��ǿ��һ��,����ȡ�� 
    cmax=(abs(b-a)+1)/2+min(a,b)*2;//min(a,b����ʧ��,ǿ��һ������ȡ�� 
    int cnt;
    if(a==0 or b==0){
    	int n=a+b;
    	if(n%2){
    		printf("2\n%d %d\n",n/2,n/2+1);
    	}
    	else{
    		printf("1\n%d\n",n/2);
    	}
    	return;
    }
    if((a+b)%2){
    	cnt=cmax-cmin+1;
    	printf("%d\n",cnt);
    	for(int i=cmin;i<=cmax;i++){
    		printf("%d ",i);
   		}
    }
    else{
    	
    	cnt=(cmax-cmin+2)/2;
    	printf("%d\n",cnt);
    	for(int i=cmin;i<=cmax;i+=2){
    		printf("%d ",i);
   		}
    }
    printf("\n");
} 
int main()
{
    int t;scanf("%d",&t);
    while(t--){
		solve();
    }
    return 0;
}
