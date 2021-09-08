#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=520;
char a[maxn][maxn],b[maxn][maxn];
char r[maxn][maxn];
int n,m;
void test(){
	cout<<"//init---------------\n";
	for(int i=0;i<n;i++){
		printf("%s\n",a[i]);
	}
	for(int i=0;i<n;i++){
		printf("%s\n",b[i]);
	}
	cout<<"//answer---------------\n";
}
void init(){
	for(int i=0;i<n;i++){
    	a[i][0]='1',a[i][m-1]='0';
    	b[i][0]='0',b[i][m-1]='1';
    }
    for(int i=0;i<n;i++){
    	if(i&1){
			for(int j=1;j<m-1;j++){
    			a[i][j]='0',b[i][j]='1';
    		}
		} 
		else{
			for(int j=1;j<m-1;j++){
				a[i][j]='1',b[i][j]='0';
			}
		} 
    }
    test();
}
int main()
{
    scanf("%d%d",&n,&m);
    getchar();
    for(int i=0;i<n;i++){
    	scanf("%s",&r[i]);
    }
	
	init();
	
    for(int i=1;i<n-1;i++){
    	for(int j=1;j<m-1;j++){
    		if(r[i][j]=='1'){
    			if(i&1)a[i][j]='1';
    			else b[i][j]='1';
    		}
    	}
    }
	for(int i=0;i<n;i++){
		printf("%s\n",a[i]);
	}
	for(int i=0;i<n;i++){
		printf("%s\n",b[i]);
	}
	return 0;
}
