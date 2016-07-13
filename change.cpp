#include <iostream>
using namespace std;
int main()
{
	void toHex_toOctal_toBinary(int num);
	void check(int num);
	int num;
	cout<<"请输入要转换的十进制正整数：";
	cin>>num;
	check(num);
	toHex_toOctal_toBinary(num);
	return 0;
}
void check(int num)
{
	if(num<0)
	{
		cout<<"输入的数不符合要求。请重新输入。";
		cin>>num;
		check(num);
	}
 } 
void toHex_toOctal_toBinary(int num) 
{
	void change1(int num,int index,int dis);
	change1(num,7,3);
	change1(num,15,4);
	change1(num,1,1);
}
void change1(int num,int index,int dis)
{
	char arr[]={'0','1','2','3','4','5','6','7',
				'8','9','A','B','C','D','E','F'};
	int t=32,nums=num;
	char st1[32];
	if(num==0)
	{
		st1[--t]='0';
		return;
	} 
	while(num!=0)
	{
		st1[--t]=arr[num&index];
		num=num>>dis;
	}
	cout<<"十进制数"<<nums<<"转换成"<<index+1<<"进制数为：";
	for(int i=t;i<32;i++)
	{
		cout<<st1[i];
	}
	cout<<endl;	
 }
 void change_Binary(int num,char *ps)
 {
 	char arr[]={'0','1'};
	int t=32;
	if(num==0)
	{
		ps[--t]='0';
		return;
	} 
	while(num!=0)
	{
		ps[--t]=arr[num&1];
		num=num>>1;
	}
 }
 void judge(char *ps,int i)
 {
 	if(ps[31-i]=='1')
 		ps[31-i]='0';
 }
 void change_Comp(int n,char *ps)
 {
 	static int i=n;
 	for(;ps[31-i]!='\0';i--)
 		if(ps[31-i]=='0')
 			ps[31-i]='1';
 		else if(ps[31-i]=='1')
 			ps[31-i]='0';
 	for(i=0;ps[31-i]!='\0';i++)
	{
		if(ps[31-i]=='0')
		{
			ps[31-i]='1';
			return;
		}
		for(;ps[31-i]=='1';i++)
		{
			judge(ps,i);
		}
	}
	int t=0;i=n;
	for(;ps[31-i]=='0';i--,t++);
	if(t==n)
		ps[31-n-1]='1';		
 }
 void nage_change(int num,int index,int dis)
 {
 	char st1[32];
 	change_Binary(num,st1);
 	int n=0,i=31;
 	for(;st1[i]!='\0';i++,n++);
 	change_Comp(n,st1);
 	
 }
 void exchange(int index,char *ps)
 {
 	
 }
	

