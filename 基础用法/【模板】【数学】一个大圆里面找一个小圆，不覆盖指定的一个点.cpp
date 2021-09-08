#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int main()
{
    double R,x1,y1,x2,y2;
    scanf("%lf%lf%lf%lf%lf",&R,&x1,&y1,&x2,&y2);
    double loc_dis=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    //cout<<loc_dis<<endl;
    if(loc_dis>=R*R){
    	printf("%.10lf %.10lf %.10lf",x1,y1,R);
    }
    else if(loc_dis==0){
    	printf("%.10lf %.10lf %.10lf",x1+R/2,y1,R/2);
    }
    else{
    	double r=(sqrt(loc_dis)+R)/2;
    	double x=x2+(x1-x2)*r/sqrt(loc_dis);
    	//r=X2_O,loc_dis=x2_x1
    	double y=y2+(y1-y2)*r/sqrt(loc_dis);
    	printf("%.10lf %.10lf %.10lf",x,y,r);
    }
    return 0;
}
