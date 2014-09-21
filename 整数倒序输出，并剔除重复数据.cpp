/*
将整数倒序输出，剔除重复数据
输入一个整数，如12336544，或1750，然后从最后一位开始倒过来输出，
最后如果是0，则不输出，输出的数字是不带重复数字的，所以上面的输出是456321和571。
如果是负数，比如输入-175，输出-571。
*/

#include "iostream"
using namespace std;

int main()
{
	int Num,n[50],a[10]={0},temp,i=0,flag=0;
	char c;
	scanf("%c%d",&c,&Num);

	while (Num>0)
	{
		temp=Num%10;
		if (a[temp]==0)
		{
			a[temp]=1;
			n[i]=temp;
			i++;
		}
		Num=Num/10;
	}
	if(c=='-') printf("%c",c);
	for (temp=0;temp<i;temp++)
	{
		if ((n[temp]!=0)||flag!=0)
		{
			printf("%d",n[temp]);
			flag=1;
		}
	}
	if(c!='-') printf("%d",(int)c-48);
	return 0;
}