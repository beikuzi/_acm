#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<map>
#include<bitset> 
using namespace std;
map<int,int>m;
#define M(x,y) make_pair(x,y)
typedef map<int,int>::iterator mii_it;
mii_it it;
using namespace std;
void map_test2(map<int,int>m){
	m.size();
	m.empty();
	m.clear();
}
void map_test(){
	//���ֲ��뷽ʽ 
	m[25]=100;
	m.insert(M(10,0));
	//���ֲ��ҷ�ʽ
	int x=m[24];//����Ҳ�����ֵ���ᴴ��m[key]=0������0 
	it=m.find(10);//��������ʽ���Ҳ����᷵��end() (�õ���ֵ 
	cout<<(*it).second; 
	//����ɾ��
	m.erase(25);
	m.erase(it);
} 
void bit_test(){//�ʺ����ڱ�ʾ4��״̬��ѹ�� 
	bitset<10086>a,b;//ֻ������ֵ0��1 
	a.set();//��Ϊ 
	int i=1;
	b.reset(i);//��Ϊ0 
	a[i]^b[i];//����Ϊ01��10 
	a[i]&b[i];//11
}
int main(){
	
	
	return 0;
} 
