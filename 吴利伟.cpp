#include <iostream>
#define MAXSIZE 32
using namespace std;
typedef struct 			//˳��ջ���壻 
{
	char str[MAXSIZE];	//�洢��Ӧ���Ƶ���Ӧ�ַ����飻 
	int top;
}SStack_Type;
int EmptySStack(SStack_Type *S); 		//��ջ����������
SStack_Type InitSStack();				//�ÿ�ջ���������� 
int PushSStack(SStack_Type *S,char x);//��ջ���������� 
int PopSStack(SStack_Type *S,char *x);//��ջ���������� 
char SStack_Type1(SStack_Type *S);		//ȡջ��Ԫ�غ��������� 
void toHex_toOctal_toBinary(int num);//��������ת��������
void check(int num);				//�����ж�����Ҫ������
/***************************************������*****************************************/ 
int main() 
{ 
	int num;			//����ת������ 
	cout<<"������Ҫת����ʮ������������";
	cin>>num;			//����ת�������� 
	check(num);
	toHex_toOctal_toBinary(num);
	return 0;
}
/***************************************�Ӻ���*****************************************/ 
void check(int num)		//�ж���������Ƿ��������� 
{
	if(num<0)
	{
		cout<<"�������������Ҫ�����������롣";
		cin>>num;
		check(num);
	}
 } 
void toHex_toOctal_toBinary(int num) 
{											// ����ת�������� 
	void change1(int num,int index,int dis);//����ת�����̺��������� 
	change1(num,7,3);						// ת��Ϊ�˽��ƣ� 
	change1(num,15,4);						// ת��Ϊʮ�����ƣ� 
	change1(num,1,1);						// ת��Ϊ�����ƣ� 
}
void change1(int num,int index,int dis)
{									// �������ת�����̵ĺ�����
	char arr[]={'0','1','2','3','4','5','6','7',
				'8','9','A','B','C','D','E','F'};
									// �ַ��������ʮ�����ڽ��Ƶ��ַ�ֵ�� 
	SStack_Type s=SStack_Type();
	if(EmptySStack(&s))				//�п�ջ�� 
	{
		cout<<"��ջ��Ϊ�գ����ܽ��в�����\n"; 
		exit(0); 
	} 
	int t=MAXSIZE,nums=num,n=0;
	if(num==0)						// �ж�Ҫת�����ַ��Ƿ�Ϊ0�� 
	{
		PushSStack(&s,'0');
		cout<<"ʮ������"<<nums<<"ת����"<<index+1<<"������Ϊ��";
		cout<<s.str[s.top]<<endl; 
		return;						//��Ϊ0ʱֱ�ӽ���������	 
	} 
	while(num!=0)					//ѭ�����ڼ����Ӧ���Ƶ��ַ�ֵ�� 
	{
		if(PushSStack(&s,arr[num&index])==0)
			break;					//�ж��Ƿ�ջ����ջ���˳������� 
		n++;						//num&index�������ڼ����Ӧ�����µĶ�Ӧ�ַ����ַ�ֵ�� 
		num=num>>dis;				//��λ��������൱�ڳ���2��dis�η��� 
	}
	char x;
	cout<<"ʮ������"<<nums<<"ת����"<<index+1<<"������Ϊ��";
	for(int i=0;i<=n;i++)			//ѭ�����ת����Ľ���� 
	{
		if(PopSStack(&s,&x)==0)		//�ж��Ƿ�ջ�գ�ջ���˳������� 
			break;
		cout<<x;
	}
	cout<<endl;	
 }
 /***************************************ջ��������***********************************/ 
SStack_Type InitSStack()			//�ÿ�ջ������ջ�ռ䣬��������ջ��ָ�룻 
{
	SStack_Type S;
	S.top=-1;
	return S; 
}
int EmptySStack(SStack_Type *S)		//�ж��Ƿ�Ϊ��ջ�� 
{
	if(S->top==-1)
		return 1;
	return 0;
}
int PushSStack(SStack_Type *S,char x)	//��ջ�� 
{
	if(S->top==MAXSIZE-1)
	{
		cout<<"ջ����������ջ��\n";
		return 0;
	}
	else
	{
		S->top++;
		S->str[S->top]=x;
		return 1;
	}
}
int PopSStack(SStack_Type *S,char *x)	//��ջ�� 
{
	if(S->top==-1)
	{
		cout<<"ջ�գ����ܳ�ջ��\n";
		return 0;
	}
	else
	{
		*x=S->str[S->top];
		S->top--;
		return 1;	
	}
}
char SStack_Type1(SStack_Type *S)	//ȡջ��Ԫ�أ� 
{
	if(S->top==-1)
	{
		cout<<"ջ�գ���Ԫ�ء�\n";
		return '0';
	}
	else
		return (S->str[S->top]);
}
