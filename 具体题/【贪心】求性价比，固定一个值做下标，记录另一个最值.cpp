#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m;
const int maxm=1010,maxs=1010;
int c[maxs];//��¼i��������С�۸� 
bool b[maxs];//��ʾ��ǰ�����޷����� 
//��ΪҪ����С�������Ǹ�����������������
//�����뵽�������±� 
struct sp{
	int s,p;
}f[maxm];//��¼ 
bool cmp(sp x,sp y){
	if(x.p!=y.p)return x.p<y.p;
	return x.s<y.s; 
} 
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
    	for(int j=0;j<m;j++){
    		scanf("%d%d",&f[j].s,&f[j].p);
    	}sort(f,f+m,cmp);
    	int loc=0;
    	f[m].s=1919810;
    	for(int k=1;k<=1000;k++){
    		if(b[k])break;//����������϶����� 
    		while(f[loc].s<k)loc++;//���Ԫ������С�ڣ��ﲻ��Ŀ�ģ��Ǿ�Ҫ��һ�� 
    		if(loc==m)b[k]=true;
    		else c[k]+=f[loc].p;
    	}
    }
    //�������С���鷳�Ļ���ͬʱ��¼���ŵ������ͼ۸�Ȼ��ѷ�ʽ��ɳ˷��Ͳ����׳��� 
    long long price=1;
    long long save=0;
    for(int i=1;i<=1000;i++){
    	if(b[i])continue;
    	if(price*i>save*c[i]){//��λ��ֵ���� 
    		price=c[i];
			save= i;
    	}
    	if(price*i==save*c[i]){
    		if(price>c[i]){
    			price=c[i];
    			save=i;
    		}
    	}
    }
    cout<<price;
    return 0;
}
