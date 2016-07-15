/*************进制转换1_1，可以把给定的数装换成计算机二进制数，*******************
 1、暂时不支持浮点数的转换；
 2、暂不支持输入转换，只能更改源代码进行进制转换；
 3、支持十六以内的任意进制的转换，但仍需更改源代码。
 ************/
class  Playp
{
    public static void main(String[] args)
    {
        toHex(26);
        toBinary(-6);
        toOctal(8);
    }
    public static void toHex(int num)
    {
        change(num,15,4);
    }
    public static void toBinary(int num)
    {
        change(num,1,1);
    }
    public static void toOctal(int num)
    {
        change(num,7,3);
    }
    public static void change(int num,int index,int dis)
    {
        int n=num,in=index+1;
        if(num==0)
        {
            System.out.println(0);
            return ;
        }
        char []bbb={'0','1','2','3','4','5','6',
                '7','8','9','A','B','C','D','E','F'};
        char[] arr=new char[32];
        int p=arr.length;
        while(num!=0)
        {
            arr[--p]=bbb[num&index];
            num=num>>>dis;
        }
        for(int i=p;i<arr.length;i++)
            System.out.print(arr[i]);
        System.out.println(n);
    }
}
