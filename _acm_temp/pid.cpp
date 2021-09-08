#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
struct pid{
	float goal_set;//Ŀ���趨ֵ 
	float goal_atl;//Ŀ��ʵ��ֵ 
	float err_1;//ƫ��ֵ1
	float err_2;//ƫ��ֵ2
	float err_3;//ƫ��ֵ3//���һ�� 
	float kp,ki,kd; //���������֡�΢�� 
}empty;
pid pid_init(){
	empty.goal_atl=0.0;
	empty.goal_set=0.0;
	empty.err_1=0.0;//���ϴ� 
	empty.err_2=0.0;//��һ�� 
	empty.err_3=0.0;//��ǰ 
	
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
	return speed*0.9;//���趯Ħ�� ����0.9
}
float change_speed(float speed_goal){
	//��Ŀ������ٶ�(goal_speed)����ת��ռ�ձ����ʸı�  
	//��ռ�ձ�Ƶ�ʲ������ٶ�*��Ħ����ϵ�����ز�����ǰ�ٶ�(get_speed)
	//�ɴ�������ȡ��ǰ�ٶ�������Ŀ���ٶ�
	return pow(speed_goal,1.1)*0.9;//����Ŀ���ٶ�ʵ�ʲ�����ת���ٶ�
	//ʵ������Ӧ�ö�Ӧ����ռ�ձ� 
}
void speed_up(float now_speed,float goal_speed){
	pid p=pid_init();
	float speed=now_speed;//1.0cmÿ�� 
	float speed_rlt=now_speed;//���Ŀ���ٶȣ� ����Ҫ����ǰ��ת���ٷֱ� 
	int k=10000;
    while(k--){
    	//1cm����10%�ĵ���ٶ� 
    	float var=pid_realize(p,get_speed(),speed_goal);
    	pwm_set_p(+var/10);
    	 
    	if(get_speed()<5.0*0.99)speed_goal+=1; //�ٷ�֮1����� 
    	else if(get_speed()>5.0*1.01)speed_goal-=0.01; 
    	else break;
    	
    	speed=change_speed(speed_goal);//����Ŀ��ת�� 
    	cout<<k<<' '<<speed<<' '<<get_speed()<<' '<<speed_goal<<endl;
    }
}
//���ݵ�ǰ�ٶȱ��仯���ٶȲ�ֵ��������ռ�ձȵİٷֱȵ���Ϊ����
void change_speed(float now_speed,float need_speed){
	int k=10000;
	while(k--){
		
	}
} 
int main()
{
    
    
    
    return 0;
}
//���ԣ�������� 
