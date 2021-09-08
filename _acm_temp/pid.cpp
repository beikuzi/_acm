#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
struct pid{
	float goal_set;//目标设定值 
	float goal_atl;//目标实际值 
	float err_1;//偏差值1
	float err_2;//偏差值2
	float err_3;//偏差值3//最后一次 
	float kp,ki,kd; //比例、积分、微分 
}empty;
pid pid_init(){
	empty.goal_atl=0.0;
	empty.goal_set=0.0;
	empty.err_1=0.0;//上上次 
	empty.err_2=0.0;//上一次 
	empty.err_3=0.0;//当前 
	
	empty.kp=0.2;
	empty.ki=0.015;
	empty.kd=0.2;
	return empty;
}
float pid_realize(pid &p,float goal_a,float goal_s){
	p.goal_atl=goal_a;
	p.goal_set=goal_s;
	
	p.err_3=p.goal_set-p.goal_atl;
	float var=p.kp*(p.err_3-p.err_2)+p.ki*p.err_3+p.kd*(p.err_3+p.err_1-2*p.err_2);
	p.goal_atl+=var;
	goal_a+=var;
	p.err_1=p.err_2;
	p.err_2=p.err_3;
	return var;
}

//
float get_speed(float speed){
	return speed*0.9;//假设动摩擦 因素0.9
}
float change_speed(float speed_goal){
	//由目标相对速度(goal_speed)决定转机占空比评率改变  
	//由占空比频率产生的速度*动摩擦关系等因素产生当前速度(get_speed)
	//由传感器获取当前速度来反馈目标速度
	return pow(speed_goal,1.1)*0.9;//假设目标速度实际产生的转机速度
	//实际这里应该对应增加占空比 
}
void speed_up(float now_speed,float goal_speed){
	pid p=pid_init();
	float speed=now_speed;//1.0cm每秒 
	float speed_rlt=now_speed;//相对目标速度， 还需要他当前的转机百分比 
	int k=10000;
    while(k--){
    	//1cm增加10%的电机速度 
    	float var=pid_realize(p,get_speed(),speed_goal);
    	pwm_set_p(+var/10);
    	 
    	if(get_speed()<5.0*0.99)speed_goal+=1; //百分之1的误差 
    	else if(get_speed()>5.0*1.01)speed_goal-=0.01; 
    	else break;
    	
    	speed=change_speed(speed_goal);//调整目标转速 
    	cout<<k<<' '<<speed<<' '<<get_speed()<<' '<<speed_goal<<endl;
    }
}
//根据当前速度被变化的速度差值，来决定占空比的百分比调整为多少
void change_speed(float now_speed,float need_speed){
	int k=10000;
	while(k--){
		
	}
} 
int main()
{
    
    
    
    return 0;
}
//测试，如果传入 
