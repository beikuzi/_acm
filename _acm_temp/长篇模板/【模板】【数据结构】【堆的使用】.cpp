#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<map>
#include<stack>
#include<queue>
using namespace std;
const int maxn=1e3+7;
inline int readi(){
	int x=0,b=1;
	char ch=getchar();
	while('0'>ch or ch>'9'){
		if(ch=='-')b=-1;
		ch=getchar();
	}
	while('0'<=ch and ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}return x*b;
}
typedef pair<int,int>pii;
struct cmp{
	bool operator()(pii x,pii y){//��һԪ��С��ǰ���ڶ�����ǰ 
		if(x.first==y.first)return x.second>y.second;
		return x.first<y.first;
	}
};
priority_queue<pii,vector<pii>,cmp>q;
bool cmp2(int x,int y){
	return x>y;
} 
int c[maxn];
void solve(){
	int n;
	make_heap(c,c+n,greater<int>());//ֱ�Ӹı�c�������ڵ�˳��,�Ѿ������� 
	make_heap(c,c+n,cmp2);
	
	push_heap(c+1,c+n+1,cmp2);//push��make��cmp��ʽӦ��Ҫһ�� 
	//���Ὣ��������һ��Ԫ��ѹ�����
	pop_heap(c+1,c+n+1,cmp2);//�ѵ����һλn�ŵ�������ֵ ,1~n-1ά�ֶ� 
}
int main()
{
	int n=readi();
	for(int i=1;i<=n;i++) {
		c[i]=readi();
	}
	for(int i=1;i<=n;i++){
		make_heap(c+1,c+1+n-i+1);
		for(int j=1;j<=n;j++){
			printf("%d ",c[j]);
		}printf("\n");
		pop_heap(c+1,c+1+n-i+1);
		
	}
	return 0;
}
	
