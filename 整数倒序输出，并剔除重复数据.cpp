/*
����������������޳��ظ�����
����һ����������12336544����1750��Ȼ������һλ��ʼ�����������
��������0�������������������ǲ����ظ����ֵģ���������������456321��571��
����Ǹ�������������-175�����-571��
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