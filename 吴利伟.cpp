#include <iostream>
#define MAXSIZE 32
using namespace std;
typedef struct 			//顺序栈定义； 
{
	char str[MAXSIZE];	//存储相应进制的相应字符数组； 
	int top;
}SStack_Type;
int EmptySStack(SStack_Type *S); 		//入栈函数声明；
SStack_Type InitSStack();				//置空栈函数声明； 
int PushSStack(SStack_Type *S,char x);//入栈函数声明； 
int PopSStack(SStack_Type *S,char *x);//出栈函数声明； 
char SStack_Type1(SStack_Type *S);		//取栈顶元素函数声明； 
void toHex_toOctal_toBinary(int num);//声明进制转换函数；
void check(int num);				//声明判断数据要求函数；
/***************************************主函数*****************************************/ 
int main() 
{ 
	int num;			//用于转换的数 
	cout<<"请输入要转换的十进制正整数：";
	cin>>num;			//输入转换的数； 
	check(num);
	toHex_toOctal_toBinary(num);
	return 0;
}
/***************************************子函数*****************************************/ 
void check(int num)		//判断输入的数是否是正数； 
{
	if(num<0)
	{
		cout<<"输入的数不符合要求。请重新输入。";
		cin>>num;
		check(num);
	}
 } 
void toHex_toOctal_toBinary(int num) 
{											// 进制转换函数； 
	void change1(int num,int index,int dis);//进制转换过程函数申明； 
	change1(num,7,3);						// 转换为八进制； 
	change1(num,15,4);						// 转换为十六进制； 
	change1(num,1,1);						// 转换为二进制； 
}
void change1(int num,int index,int dis)
{									// 定义进制转换过程的函数；
	char arr[]={'0','1','2','3','4','5','6','7',
				'8','9','A','B','C','D','E','F'};
									// 字符数组包含十六以内进制的字符值； 
	SStack_Type s=SStack_Type();
	if(EmptySStack(&s))				//判空栈； 
	{
		cout<<"新栈不为空，不能进行操作。\n"; 
		exit(0); 
	} 
	int t=MAXSIZE,nums=num,n=0;
	if(num==0)						// 判断要转换的字符是否为0； 
	{
		PushSStack(&s,'0');
		cout<<"十进制数"<<nums<<"转换成"<<index+1<<"进制数为：";
		cout<<s.str[s.top]<<endl; 
		return;						//数为0时直接结束函数；	 
	} 
	while(num!=0)					//循环用于计算对应进制的字符值； 
	{
		if(PushSStack(&s,arr[num&index])==0)
			break;					//判断是否栈满，栈满退出操作； 
		n++;						//num&index运算用于计算对应进制下的对应字符的字符值； 
		num=num>>dis;				//移位运算符，相当于除以2的dis次方； 
	}
	char x;
	cout<<"十进制数"<<nums<<"转换成"<<index+1<<"进制数为：";
	for(int i=0;i<=n;i++)			//循环输出转换后的结果； 
	{
		if(PopSStack(&s,&x)==0)		//判断是否栈空，栈空退出操作； 
			break;
		cout<<x;
	}
	cout<<endl;	
 }
 /***************************************栈操作函数***********************************/ 
SStack_Type InitSStack()			//置空栈，建立栈空间，并返回其栈顶指针； 
{
	SStack_Type S;
	S.top=-1;
	return S; 
}
int EmptySStack(SStack_Type *S)		//判断是否为空栈； 
{
	if(S->top==-1)
		return 1;
	return 0;
}
int PushSStack(SStack_Type *S,char x)	//入栈， 
{
	if(S->top==MAXSIZE-1)
	{
		cout<<"栈满，不能入栈。\n";
		return 0;
	}
	else
	{
		S->top++;
		S->str[S->top]=x;
		return 1;
	}
}
int PopSStack(SStack_Type *S,char *x)	//出栈； 
{
	if(S->top==-1)
	{
		cout<<"栈空，不能出栈。\n";
		return 0;
	}
	else
	{
		*x=S->str[S->top];
		S->top--;
		return 1;	
	}
}
char SStack_Type1(SStack_Type *S)	//取栈顶元素； 
{
	if(S->top==-1)
	{
		cout<<"栈空，无元素。\n";
		return '0';
	}
	else
		return (S->str[S->top]);
}
