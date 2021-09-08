#include<iostream>
#include<algorithm>
#include<cstdio> 
using namespace std;
const int maxn=5050;
bool c[maxn][maxn];
int n;
const int aim=5000;
//void test(){
//	for(int i=0;i<=aim/100;i++){
//		for(int j=0;j<=aim/100;j++){
//			cout<<c[i][j]<<' ';
//		}cout<<endl;
//	}
//}
void deal(int x,int y){
	for(int i=1;y+i<=aim;i++)c[x][y+i]=true;
	for(int i=1;x+i<=aim;i++)c[x+i][y]=true;
	
	for(int j=1;y+j<=aim;j++){
		for(int i=1;x+i*j<=aim;i++){
			c[x+i*j][y+j]=true;
		}
	}
	for(int i=1;x+i<=aim;i++){
		for(int j=1;y+i*j<=aim;j++){
			c[x+i][y+i*j]=true;
		}
	}
	
	
}
void cal(){
	for(int i=0;i<=aim;i++){
		for(int j=0;j<=aim;j++){
			if(!c[i][j])deal(i,j);//失败的值用去搜索 
		}
	}
}
int main()
{
	cal();//test();
    scanf("%d",&n);
    int x,y;
    while(n--){
    	scanf("%d%d",&x,&y);
    	if(c[x][y])printf("Alice\n");
    	else printf("Bob\n");
    }return 0;
}
