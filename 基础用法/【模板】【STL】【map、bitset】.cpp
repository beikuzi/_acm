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
	//两种插入方式 
	m[25]=100;
	m.insert(M(10,0));
	//两种查找方式
	int x=m[24];//如果找不到该值，会创建m[key]=0并返回0 
	it=m.find(10);//迭代器方式，找不到会返回end() (得到乱值 
	cout<<(*it).second; 
	//两种删除
	m.erase(25);
	m.erase(it);
} 
void bit_test(){//适合用于表示4中状态的压缩 
	bitset<10086>a,b;//只有两个值0，1 
	a.set();//设为 
	int i=1;
	b.reset(i);//设为0 
	a[i]^b[i];//二者为01后10 
	a[i]&b[i];//11
}
int main(){
	
	
	return 0;
} 
