/*
字符串M化成以N为单位的段
输入m个字符串 和一个整数n, 把字符串M化成以N为单位的段，不足的位数用0补齐。
如 n=8 m=9 ，
123456789划分为：12345678
90000000
123化为 ：12300000
*/
#include "iostream"
using namespace std;

int main()
{
	int m,n;
	char str[100]={'\0'};
	int len;
	int yu,shang;
	
	printf("输入字符窜字符个数：");
	scanf("%d",&m);

	scanf("%s",&str);
	len=strlen(str);

	printf("输入n的值：");
	scanf("%d",&n);

	yu=len%n;
	for (int i=0;i<len;i++)
	{
		if(i%n==0)
			printf("\n%c",str[i]);
		else 
			printf("%c",str[i]);
	}
	if (yu==0)
		;
	else
	{
		for(int i=yu+1;i<=n;i++)
			printf("0");
		printf("\n");
	}
	return 0;
}